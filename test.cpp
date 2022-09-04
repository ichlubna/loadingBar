#include <chrono>
#include <thread>
#include <iostream>

import loadingbar;

int main(int argc, char *argv[])
{
	size_t legoBrickCount{200};
	LoadingBar bar(legoBrickCount);
	std::cout  << "Assembling..." << std::endl;
	for(size_t i=0; i<legoBrickCount; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		bar.add();
	}
}
