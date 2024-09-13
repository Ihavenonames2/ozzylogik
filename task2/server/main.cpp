#include <boost/asio.hpp>
#include <fstream>
#include <iostream>

using boost::asio::ip::tcp;

void sendFile(tcp::socket& socket, const std::string& fileName) {
    std::ifstream file(fileName, std::ios::binary);
    if (file) {
        std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        boost::asio::write(socket, boost::asio::buffer(buffer));
    }
}

int main(){
	return 0;
}

