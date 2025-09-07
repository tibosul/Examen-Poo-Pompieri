#include "Unitate_Pompieri.h"

Unitate_Pompieri& Unitate_Pompieri::get_instance()
{
    static Unitate_Pompieri instance;
    return instance;
}
