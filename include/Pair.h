#ifndef PAIR_C
#define PAIR_C
class Pair{
public:
	int x, y;
	Pair(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	int first()
	{
		return x;
	}
	int second()
	{
		return y;
	}
};
#endif