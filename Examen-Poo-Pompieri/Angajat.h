#pragma once
#include "I_Angajat.h"
#include "Unique_ID_Generator.h"
#include "Exceptions.h"

class Angajat : public I_Angajat
{
protected:
	int id_unic = 0;
	std::string nume;

public:
	Angajat();
	Angajat(const std::string& nume);
	virtual ~Angajat() override = default;

	virtual inline int get_id() const override { return this->id_unic; }
	virtual inline const std::string& get_nume() const override { return this->nume; }

	virtual inline void set_id(int id) override { this->id_unic = id; }
	virtual inline void set_nume(const std::string& nume) override { this->nume = nume; }

	virtual inline int get_numar_interventii() const { throw Wrong_Angajat_Type("N'est pas un pompier"); }
	virtual inline void set_numar_interventii(int numar_interventii) { throw Wrong_Angajat_Type("N'est pas un pompier"); }
};

