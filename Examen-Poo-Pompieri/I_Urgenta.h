#pragma once
#include <string>

class I_Urgenta
{
public:
	I_Urgenta() = default;
	virtual ~I_Urgenta() = default;

	virtual inline const std::string& get_adresa() const = 0;
	virtual inline int get_numar_victime() const = 0;

	virtual inline void set_adresa(const std::string& adresa) = 0;
	virtual inline void set_numar_victime(int numar_victime) = 0;

	virtual inline int get_numar_vehicule() const = 0;
	virtual inline void set_numar_vehicule(int numar_vehicule) = 0;

	virtual inline int get_inaltime() const = 0;
	virtual  inline double get_arie() const = 0;

	virtual inline void set_inaltime(int inaltime) = 0;
	virtual inline void set_arie(double arie) = 0;


	virtual inline int get_numar_departatoare_necesare() const = 0;
	virtual inline int get_numar_foarfece_necesare() const = 0;
	virtual inline double get_pulbere_necesara() const = 0;
	virtual inline double get_spuma_necesara() const = 0;
	virtual inline int get_autoscari_necesare() const = 0;
	virtual inline int get_numar_pompieri_necesari() const = 0;

	virtual inline void set_numar_departatoare_necesare(int numar_departatoare_necesare) = 0;
	virtual inline void set_numar_foarfece_necesare(int numar_foarfece_necesare) = 0;
	virtual inline void set_pulbere_necesara(double pulbere_necesara) = 0;
	virtual inline void set_spuma_necesara(double spuma_necesara) = 0;
	virtual inline void set_autoscari_necesare(int autoscari_necesare) = 0;
	virtual inline void set_numar_pompieri_necesari(int numar_pompieri_necesari) = 0;
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