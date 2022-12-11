struct noncopyable {  // boost::noncopyable
    noncopyable() = default;
    noncopyable(const noncopyable &) = delete;
    noncopyable(noncopyable &&) = delete;
    noncopyable &operator=(const noncopyable &) = delete;
    noncopyable &operator=(noncopyable &&) = delete;
};

struct Foo : private noncopyable {};
struct Bar : private noncopyable {};
struct Baz : private noncopyable {};

int main() {
    Foo f;
    // noncopyable &n = f;  // WTF, 'private' prevents that.

    // Foo f2 = f;
}
