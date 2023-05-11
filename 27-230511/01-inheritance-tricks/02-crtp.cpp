#include <iostream>
#include <string_view>

template<typename Derived>
struct RichWriter {
    // virtual void writeChar(char c) = 0;  // No virtual functions!

protected:
    Derived &derived() {
        // Compile-time call
        return static_cast<Derived&>(*this);
    }

public:
    void writeInt(int value) {
        static_assert(CHAR_BIT == 8);
        for (int i = 0; i < 4; i++) {
            derived().writeChar((value >> (8 * i)) & 0xFF);
        }
    }
    void writeString(std::string_view s) {
        writeInt(s.size());
        for (char c : s) {
            derived().writeChar(c);
        }
    }
};

struct OstreamWriter : RichWriter<OstreamWriter> {  // CRTP: Curiously Recurring Template Pattern
private:
    std::ostream &m_os;

public:
    OstreamWriter(std::ostream &os) : m_os(os) {}

    void writeChar(char c) {  // no 'override'
        m_os << c;
    }
};

struct CountingWriter : RichWriter<CountingWriter> {  // CRTP
private:
    int m_written = 0;

public:
    void writeChar(char) {  // no 'override'
        m_written++;
    }
    int written() const {
        return m_written;
    }
};

// Do not have a "common" type for `RichWriter`s, need templates.
template<typename RW>
void writeHello(RW &w) {
    w.writeString("hello\n");
}

template<typename T>
void writeHello2(RichWriter<T> &w) {
    w.writeString("hello\n");
}

int main() {
    OstreamWriter ow(std::cout);
    writeHello(ow);

    CountingWriter cw;
    writeHello(cw);
    std::cout << cw.written() << "\n";

    // Pros: probably faster, objects take less space
    // Cons: less clear code
}
