#ifndef PAIR_CPP
#define PAIR_CPP

#pragma once

#include "Pair.h"

template <typename T, typename U>
Pair<T, U>::Pair()
: first(),
second()
{}

template <typename T, typename U>
Pair<T, U>::Pair(T t, U u)
: first(t),
second(u)
{}

template <typename T, typename U>
Pair<T, U>::~Pair()
{}

template<class T, class U>
Pair<T, U>::Pair(const Pair<T, U> &pair)
: first(pair.first),
second(pair.second)
{}

template<class T, class U>
Pair<T, U> &Pair<T, U>::operator=(const Pair<T, U> &pair)
{
    if (pair != this)
    {
        this->first = pair.first;
        this->second = pair.second;
    }

    return *this;
}

#endif