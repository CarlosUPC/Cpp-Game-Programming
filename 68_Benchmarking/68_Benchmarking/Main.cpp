#include <iostream>
#include <chrono>

#include <array>
#include <memory>

class Timer
{
public:

	Timer()
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();

		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		auto duration = end - start;
		double ms = duration * 0.001;

		std::cout << duration << "us (" << ms << "ms)\n";
	}

private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;



};

//Mesuring performance in debug mode is not great because it does a whole lot of extra safety stuff which takes time --> aware to prefile code on release mode

//Put the instrumentalization code(Timer) on the right way to measure the performance cause on release, compiler change a lot of code and can affect to the analysis. Check it always using breakpoint and go to de assembly code to view the CPU instructions

int main()
{
	int value = 0;

	{
		Timer timer;
		for (int i = 0; i < 1000000; i++)
			value += 2;
	}

	struct Vector2
	{
		float x, y;
	};

	std::cout << "Make Shared\n";
	
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_shared<Vector2>();
	}

	std::cout << "heap Shared\n";
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		Timer timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
	}

	std::cout << "Make Unique\n";

	{
		std::array<std::unique_ptr<Vector2>, 1000> uniquePtrs;
		Timer timer;
		for (int i = 0; i < uniquePtrs.size(); i++)
			uniquePtrs[i] = std::make_unique<Vector2>();

	
	}

	std::cout << value << std::endl;
	__debugbreak();
}