#ifndef RANDOM_H
#define RANDOM_H
#include <cstdlib>
#include <ctime>

class Random
{
    public:
        Random();
        unsigned GetRandomNumber(int limit) const;
};

#endif // RANDOM_H
