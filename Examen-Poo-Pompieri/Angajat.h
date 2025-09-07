#pragma once
#include "I_Angajat.h"
#include "Unique_ID_Generator.h"
#include <string>

class Angajat : public I_Angajat
{
protected:
	int id_unic = 0;
	std::string nume;

public:
	Angajat();
	Angajat(const std::string& nume);
	virtual ~Angajat() override = default;

	inline int get_id() const { return this->id_unic; }
	inline const std::string& get_nume() const { return this->nume; }

	inline void set_id(int id) { this->id_unic = id; }
	inline void set_nume(const std::string& nume) { this->nume = nume; }


};

