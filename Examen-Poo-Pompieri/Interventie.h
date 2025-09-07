#pragma once
#include "Unique_ID_Generator.h"

class Interventie
{
protected:
	int id_unic = 0;

public:
	Interventie();
	~Interventie() = default;

	inline int get_id() const { return this->id_unic; }

	inline void set_id(int id) { this->id_unic = id; }
};

