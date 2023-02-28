#include <boost/asio.hpp>
#include <cassert>
#include <exception>
#include <iostream>
#include <sstream>
#include <utility>

using boost::asio::buffer;
using boost::asio::ip::tcp;

int main(int argc, char *argv[]) {
    assert(argc == 3);

    boost::asio::io_context io_context;

    tcp::socket s(io_context);
    boost::asio::connect(
        s, tcp::resolver(io_context).resolve(argv[1], argv[2])
    );
    std::cout << "Connected " << s.local_endpoint() << " --> "
              << s.remote_endpoint() << "\n";

    for (int i = 0; i < 20; i++) {
        s.send(buffer("hello\n"));  // bad
        // write(s, buffer("hello\n"));  // good, but does not matter
    }
}
