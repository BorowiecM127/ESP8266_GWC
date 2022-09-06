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

    T first;
    T second;

private:
};

#include "Pair.cpp"

#endif