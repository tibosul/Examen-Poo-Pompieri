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

	virtual inline double get_lungime_scara() const override { return this->lungime_scara; }
	virtual inline void set_lungime_scara(double lungime_scara) override { this->lungime_scara = lungime_scara; }

};

