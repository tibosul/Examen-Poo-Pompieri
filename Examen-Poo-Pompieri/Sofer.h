#pragma once
#include "Angajat.h"

class Sofer : public Angajat
{
protected:

public:
	Sofer();
	Sofer(const std::string& nume);
	virtual ~Sofer() override = default;


};

