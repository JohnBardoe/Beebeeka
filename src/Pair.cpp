#include "Pair.h"
Pair::Pair(int x1, int y1)
{
    x = x1;
    y = y1;
}

int Pair::first()
{
    return x;
}

int Pair::second()
{
    return y;
}