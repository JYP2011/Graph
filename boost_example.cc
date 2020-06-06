#include <iostream>

#include <boost/thread.hpp>
#include <boost/bind.hpp>

boost::mutex io_mutex;

void count(int id)
{
	for (int i = 0; i < 10; i++)
	{
		boost::mutex::scoped_lock lock(io_mutex);
		std::cout << id << ":" << i << std::endl;
	}
}

int main(int argc, char* argv[])
{
	boost::thread thrd1(boost::bind(&count, 1));
	boost::thread thrd2(boost::bind(&count, 2));
	thrd1.join();
	thrd2.join();
	return 0;
}