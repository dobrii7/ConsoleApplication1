#include <iostream>
#include <thread>
#include <chrono>
#include <vector>


void doWord(int a)
{
	for (int i = 0; i < a; i++)
	{
		std::cout << "id-thread  " << std::this_thread::get_id() << "  Do Word " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
}

int main()
{
	std::cout << "Hello World!\n" << std::endl;
	//doWord();
	std::thread dow(doWord, 20);
	std::vector<int> ver;
	for (int i = 0; i < 10; i++)
	{
		ver.push_back(i);
		std::cout << "id-thread  " << std::this_thread::get_id() << "  main " << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	dow.join();
	for (int n : ver)
	{
		std::cout << n << " ";
	}
	return 0;
}