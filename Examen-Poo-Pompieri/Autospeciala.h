#pragma once
#include "I_Autospeciala.h"
#include "Unique_ID_Generator.h"

class Autospeciala : public I_Autospeciala
{
protected:
	int id_unic = 0;

public:
	Autospeciala();
	Autospeciala(const Autospeciala&) = default;
	Autospeciala(Autospeciala&&) = default;
	virtual ~Autospeciala() override = default;

	inline int get_id() const { return this->id_unic; }

	inline void set_id(int id) { this->id_unic = id; }
};

