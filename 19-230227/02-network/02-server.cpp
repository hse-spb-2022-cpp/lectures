#include <boost/asio.hpp>
#include <cassert>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>
#include <utility>

using boost::asio::ip::tcp;

int main(int argc, char *argv[]) {
    assert(argc == 2);

    boost::asio::io_context io_context;  // TODO: once per thread or per app?
    tcp::acceptor acceptor(
        io_context, tcp::endpoint(tcp::v4(), std::atoi(argv[1]))
    );
    std::cout << "Listening at " << acceptor.local_endpoint() << "\n";

    tcp::iostream client([&]() {
        tcp::socket s = acceptor.accept();
        std::cout << "Connected " << s.remote_endpoint() << " --> "
                  << s.local_endpoint() << "\n";
        return s;
    }());

    while (client) {
        std::string s;
        client >> s;
        client << "string: " << s << "\n";
    }
    std::cout << "Completed\n";
}
