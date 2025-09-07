#pragma once
#include <string>

class I_Angajat
{
public:
	I_Angajat() = default;
	virtual ~I_Angajat() = default;

	virtual inline int get_id() const = 0;
	virtual inline const std::string& get_nume() const = 0;

	virtual inline void set_id(int id) = 0;
	virtual inline void set_nume(const std::string& nume) = 0;

	virtual inline int get_numar_interventii() const = 0;
	virtual inline void set_numar_interventii(int numar_interventii) = 0;
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