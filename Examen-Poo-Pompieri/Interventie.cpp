#include "Interventie.h"

using Interventie_ID_Generator = Unique_ID_Generator<Interventie>;

Interventie::Interventie()
{
	this->id_unic = Interventie_ID_Generator::generate_next_id();
}
