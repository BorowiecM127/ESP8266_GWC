#ifndef PAIR_H
#define PAIR_H

#pragma once

template <typename T, typename U>
class Pair
{
public:
    Pair();
    Pair(T, U);
    ~Pair();
    Pair(const Pair &pair);
    Pair &operator=(const Pair &pair);

    T first;
    T second;
};

#include "Pair.cpp"

#endif