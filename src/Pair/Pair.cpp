#ifndef PAIR_CPP
#define PAIR_CPP

#pragma once

#include "Pair.h"

template <typename T, typename U>
Pair<T, U>::Pair()
    : first(),
      second()
{
}

template <typename T, typename U>
Pair<T, U>::Pair(T t, U u)
    : first(t),
      second(u)
{
}

template <typename T, typename U>
Pair<T, U>::~Pair()
{
}

#endif