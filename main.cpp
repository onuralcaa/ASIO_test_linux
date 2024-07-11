 
#include <boost/asio.hpp>
#include <iostream>

int main() {
    boost::asio::io_context io;
    std::cout << "Boost ASIO is installed and working." << std::endl;
    return 0;
}
