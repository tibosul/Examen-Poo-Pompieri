#pragma once
#include "Autospeciala.h"

class Autoscara : public Autospeciala
{
protected:
	double lungime_scara = 0.0;

public:
	Autoscara();
	Autoscara(double lungime_scara);
	virtual ~Autoscara() override = default;

	inline double get_lungime_scara() const { return this->lungime_scara; }

	inline void set_lungime_scara(double lungime_scara) { this->lungime_scara = lungime_scara; }

};

