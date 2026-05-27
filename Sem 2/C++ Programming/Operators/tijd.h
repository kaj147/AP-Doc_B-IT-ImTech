//
// Created by Christophe on 23/04/2026.
//

#ifndef OPERATORS_TIJD_H
#define OPERATORS_TIJD_H


class Tijd
{
public:
    int min;
    int sec;
    Tijd(int min, int sec);
    Tijd operator++();
    bool operator<(const Tijd& t) const;
};


#endif //OPERATORS_TIJD_H