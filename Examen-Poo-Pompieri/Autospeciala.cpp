#include "Autospeciala.h"

using Autospeciala_ID_Generator = Unique_ID_Generator<Autospeciala>;

Autospeciala::Autospeciala()
	:I_Autospeciala()
{
	this->id_unic = Autospeciala_ID_Generator::generate_next_id();
}
