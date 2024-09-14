#include <boost/asio.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <thread>

using boost::asio::ip::tcp;

//a function that send the file to client
void sendFile(tcp::socket& socket, const std::string& fileName)
{
	std::ifstream file(fileName, std::ios::binary | std::ios::ate);
        //checks is file is open and found
        if (!file) 
	{
                std::cerr << "File not found: " << fileName << std::endl;
                return;
        }

        std::ifstream::pos_type fileSize = file.tellg();
        if (fileSize == 0) 
	{
        	std::cerr << "File is empty: " << fileName << std::endl;
        	return;
	}
	//seeks to the begging of file
	file.seekg(0, std::ios::beg);

	//vector of bytes that acts like a buffer
	std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	boost::asio::write(socket, boost::asio::buffer(buffer));

	std::cout << "File sent to client." << std::endl;
}

//a function that handles clients
void handleClient(tcp::socket socket) {
        try 
	{
        	std::cout << "Client connected: " << socket.remote_endpoint() << std::endl;
        	sendFile(socket, "response.txt");
        	socket.close();
   	}
	catch (std::exception& e) 
	{
        std::cerr << "Error handling client: " << e.what() << std::endl;
    	}
}

int main() 
{
	try 
	{
        	boost::asio::io_context io_context;

        	tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));
        	std::cout << "Server started, waiting for connections..." << std::endl;

		//server wotking until user doesnt stop it
        	while (true) 
		{
            		tcp::socket socket(io_context);
            		acceptor.accept(socket);
			//creating an thread for every user
           		std::thread clientThread(&handleClient, std::move(socket));
			//detaching this thread so it can work independantly
           		clientThread.detach();
        	}
    	} 
	catch (std::exception& e) 
	{
        	std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}

