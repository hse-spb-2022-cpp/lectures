#include <boost/asio.hpp>
#include <exception>
#include <iostream>
#include <sstream>
#include <utility>

using boost::asio::ip::tcp;

// https://stackoverflow.com/questions/67196597/terminate-called-after-throwing-an-instance-of-std-ios-failure-when-tryin

int main() {
    try {
        try {
            boost::asio::io_context io_context;
            tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 10000));
            std::cout << "Listening at " << acceptor.local_endpoint() << "\n";

            tcp::iostream client(acceptor.accept());
            client.exceptions(
                std::ios_base::failbit | std::ios_base::badbit |
                std::ios_base::eofbit
            );  // (1)
            while (client << "x\n") {
            }
            std::cout << "Completed\n";
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << "\n";
        }
    } catch (...) {
        std::cout << "Unknown exception\n";
    }
    return 0;
}
