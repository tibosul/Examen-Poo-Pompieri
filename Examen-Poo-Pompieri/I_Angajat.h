#pragma once

class I_Angajat
{
public:
	I_Angajat() = default;
	virtual ~I_Angajat() = default;
};

class I_Angajat_Factory
{
public:
	I_Angajat* create_new_Pompier();
	I_Angajat* create_new_Pompier(const std::string& nume);
	I_Angajat* create_new_Pompier(const std::string& nume, int numar_interventii);

	I_Angajat* create_new_Sofer();
	I_Angajat* create_new_Sofer(const std::string& nume);
};