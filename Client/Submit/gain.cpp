#include "SubmitApi.h"

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>




using boost::asio::ip::tcp;

namespace{
	auto max_length = 1000000;
	boost::asio::io_context io_context;
	tcp::socket s(io_context);
	tcp::resolver resolver(io_context);
}
int gain(int argc, char* argv[])
{
	try
	{
		if (argc != 3)
		{
			std::cerr << "Usage: race_client <host> <port> < data\n";
			return 1;
		}

		boost::asio::connect(s, resolver.resolve(argv[1], argv[2]));
		{
			std::cout << "Enter message: ";
			char request[max_length];
			std::cin.getline(request, max_length);
			size_t request_length = std::strlen(request);
			boost::asio::write(s, boost::asio::buffer(request, request_length));
		}
		{
			char reply[max_length];
			size_t reply_length = boost::asio::read(s,
				boost::asio::buffer(reply, request_length));
			//std::cout << "Reply is: ";
			std::cout.write(reply, reply_length);
			std::cout << "\n";
		}
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}

