#include <iostream>
#include <string_view>

struct RichWriter {
public:
    virtual void writeChar(char c) = 0;

    void writeInt(int value) {
        static_assert(CHAR_BIT == 8);
        for (int i = 0; i < 4; i++) {
            writeChar((value >> (8 * i)) & 0xFF);
        }
    }
    void writeString(std::string_view s) {
        writeInt(s.size());
        for (char c : s) {
            writeChar(c);
        }
    }
};

struct OstreamWriter : RichWriter {
private:
    std::ostream &m_os;

public:
    OstreamWriter(std::ostream &os) : m_os(os) {}

    void writeChar(char c) override {
        m_os << c;
    }
};

struct CountingWriter : RichWriter {
private:
    int m_written = 0;

public:
    void writeChar(char) override {
        m_written++;
    }
    int written() const {
        return m_written;
    }
};

void writeHello(RichWriter &w) {
    w.writeString("hello\n");
}

int main() {
    OstreamWriter ow(std::cout);
    writeHello(ow);

    CountingWriter cw;
    writeHello(cw);
    std::cout << cw.written() << "\n";
}
