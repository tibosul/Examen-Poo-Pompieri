#pragma once
#include <set>

template <typename T>
class Unique_ID_Generator
{
private:
	static int current_id;

public:
	
	Unique_ID_Generator() = delete;
	~Unique_ID_Generator() = delete;
	Unique_ID_Generator(const Unique_ID_Generator&) = delete;
	Unique_ID_Generator(Unique_ID_Generator&&) = delete;

	static int generate_next_id()
	{ 
		current_id++;
		return current_id;
	}
};

template <typename T>
int Unique_ID_Generator<T>::current_id = -1;