#include <boost/asio.hpp>
#include <cassert>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

using boost::asio::buffer;
using boost::asio::ip::tcp;

int main(int argc, char *argv[]) {
    assert(argc == 2);

    boost::asio::io_context io_context;
    tcp::acceptor acceptor(
        io_context, tcp::endpoint(tcp::v4(), std::atoi(argv[1]))
    );
    std::cout << "Listening at " << acceptor.local_endpoint() << "\n";

    tcp::socket client = acceptor.accept();
    std::cout << "Connected " << client.remote_endpoint() << " --> "
              << client.local_endpoint() << "\n";

    for (;;) {
        std::vector<char> buf(50);
        std::size_t read = client.receive(buffer(buf), 0);  // reads _something_
        std::string s(buf.begin(), buf.begin() + read);
        std::cout << "string of length " << read << ": " << s << "\n";
    }
    std::cout << "Completed\n";
    return 0;
}
