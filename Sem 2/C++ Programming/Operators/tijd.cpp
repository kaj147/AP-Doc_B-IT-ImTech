//
// Created by Christophe on 23/04/2026.
//

#include "tijd.h"

Tijd::Tijd(int min, int sec)
{
    this->min = min;
    this->sec = sec;
}

Tijd Tijd::operator++()
{
    if (this->sec == 59)
        return Tijd(this->min++, this->sec = 0);
    return Tijd(this->min, this->sec++);
}

bool Tijd::operator<(const Tijd &t) const
{
    //performanter
    return (this->min < t.min && this->sec < t.sec);
    //trager maar ook mogelijk
    return ((this->min*60 + this->sec) < (min*60+sec));
}