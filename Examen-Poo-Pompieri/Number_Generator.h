#pragma once
#include <ctime>
#include <cstdlib>

class Number_Generator
{
private:
	static bool is_seeded;
	static void initialize_seed()
	{
		if (!is_seeded)
		{
			srand(time(nullptr));
		}
		is_seeded = true;
	}

public:
	Number_Generator() = delete;
	~Number_Generator() = delete;
	Number_Generator(const Number_Generator&) = delete;
	Number_Generator(Number_Generator&&) = delete;

	template<int min = 0, int max = 1000>
	int generate_number()
	{
		initialize_seed();
		return rand() % (max - min + 1) + min;
	}
};

bool Number_Generator::is_seeded = false;