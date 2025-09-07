#pragma once

class I_Urgenta
{
public:
	I_Urgenta() = default;
	virtual ~I_Urgenta() = default;
};

class I_Urgenta_Factory
{
public:
	I_Urgenta* create_new_Accident();
	I_Urgenta* create_new_Accident(const std::string& adresa, int numar_victime);
	I_Urgenta* create_new_Accident(const std::string& adresa, int numar_victime, int numar_vehicule);

	I_Urgenta* create_new_Incendiu_Electric();
	I_Urgenta* create_new_Incendiu_Electric(const std::string& adresa, int numar_victime);
	I_Urgenta* create_new_Incendiu_Electric(const std::string& adresa, int numar_victime, int inaltime, double arie);

	I_Urgenta* create_new_Incendiu_Vegetatie();
	I_Urgenta* create_new_Incendiu_Vegetatie(const std::string& adresa, int numar_victime);
	I_Urgenta* create_new_Incendiu_Vegetatie(const std::string& adresa, int numar_victime, int inaltime, double arie);
};