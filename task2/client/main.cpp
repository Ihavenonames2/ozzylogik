#include <boost/asio.hpp>
#include <iostream>
#include <fstream>

using boost::asio::ip::tcp;

//simple function that receives file using 
void saveFile(tcp::socket& socket, const std::string& fileName) 
{
	std::ofstream file(fileName, std::ios::binary);
	if (file) 
	{
        	std::vector<char> buffer(1024);
        	boost::system::error_code error;
        	std::size_t len;

        	while ((len = socket.read_some(boost::asio::buffer(buffer), error)) > 0) 
		{
            		file.write(buffer.data(), len);
       		}

        	if (error != boost::asio::error::eof) 
		{
            		throw boost::system::system_error(error);
        	}
    }
}

int main() {
	try 
	{
        	boost::asio::io_context io_context;
        	tcp::resolver resolver(io_context);
        	tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "12345");
        	tcp::socket socket(io_context);

        	boost::asio::connect(socket, endpoints);

        	std::cout << "Connected to server, receiving file..." << std::endl;
        	saveFile(socket, "received.txt");

        	std::cout << "File received, saved as 'received.txt'." << std::endl;
    	} 
	catch (std::exception& e) 
	{
        	std::cerr << "Error: " << e.what() << std::endl;
    	}

    return 0;
}

