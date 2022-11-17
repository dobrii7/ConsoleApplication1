#include <iostream>
#include <thread>
#include <chrono>

void doWord()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "id-thread  " << std::this_thread::get_id() << "  Do Word " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	}
}

int main()
{
	std::cout << "Hello World!\n" << std::endl;
	//doWord();
	std::thread dow(doWord);
	for (int i = 0; i < 10; i++)
	{
		std::cout << "id-thread  " << std::this_thread::get_id() << "  main " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	dow.join();
	return 0;
}