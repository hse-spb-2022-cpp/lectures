#include <boost/asio.hpp>
#include <cassert>
#include <exception>
#include <iostream>
#include <sstream>
#include <utility>

using boost::asio::ip::tcp;

int main(int argc, char *argv[]) {
    assert(argc == 3);

    boost::asio::io_context io_context;

    auto create_connection = [&]() {
        tcp::socket s(io_context);
        boost::asio::connect(
            s, tcp::resolver(io_context).resolve(argv[1], argv[2])
        );
        return tcp::iostream(std::move(s));
    };
    tcp::iostream conn = create_connection();
    std::cout << "Connected " << conn.socket().local_endpoint() << " --> "
              << conn.socket().remote_endpoint() << "\n";

    conn << "hello world 123\n";
    conn.socket().shutdown(tcp::socket::shutdown_send);
    std::cout << "Shut down\n";

    int c;
    while ((c = conn.get()) != std::char_traits<char>::eof()) {
        std::cout << static_cast<char>(c);
    }

    std::cout << "Completed\n";
    return 0;
}
