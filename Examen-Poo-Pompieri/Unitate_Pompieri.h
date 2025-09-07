#pragma once

class Unitate_Pompieri
{
protected:
	Unitate_Pompieri() = default;
	Unitate_Pompieri(const Unitate_Pompieri&) = delete;
	Unitate_Pompieri& operator=(const Unitate_Pompieri&) = delete;
	Unitate_Pompieri(Unitate_Pompieri&&) = delete;
	Unitate_Pompieri& operator=(Unitate_Pompieri&&) = delete;
	~Unitate_Pompieri() = default;

public:
	static Unitate_Pompieri& get_instance();
};

