#include "random.h"

Random::Random()
{
    srand(static_cast<unsigned>(std::time(0)));
}

unsigned Random::GetRandomNumber(int limit) const
{
    return rand() % limit;
}
