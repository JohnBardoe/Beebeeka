#include <vector.h>

#define push_back PushBack
#define size Size
#define erase Erase

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

class Queue{
public:
	Vector <int> v;
	void insert(int k)
	{
		v.push_back(k);
	}
	void pop()
	{
		for(int i = 1; i < v.size(); i++)
		{
			v[i-1]=v[i];
		}
		v.PopBack();
	}
	bool empty()
	{
		if (v.size()==0)
			return 1;
		else
			return 0;
	}
	int size()
	{
		return v.size();
	}
	int first()
	{
		return v[0];
	}
	
	/*bool print()
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i];
	}*/

};

class ShortestWay{
public:
	int x_st, y_st, x_f, y_f;
    int map_s [4][8][4];

	Queue q;
	Vector <int> answer;
	Vector <int> ans;
	int length [4][8] = {{0},{0}};

    ShortestWay()
    {
    	x_st = -1;
		y_st = -1;
		x_f = -1;
		y_f = -1;
    }
	ShortestWay(int x_st1, int y_st1, int x_f1, int y_f1)
	{
		x_st = x_st1+1;
		y_st = y_st1+1;
		x_f = x_f1+1;
		y_f = y_f1+1;
	}




	/*void enter_map()
	{
		int a=-124,b=-1241;
		cin >> a >> b;
		while (a != -1 && b != -1)
		{
			for (int i = 0; i < 4; i++)
			{
				cin >> map_s[a][b][i];
			}
			cin >> a >> b;
		}

	}*/



	/*void print_len()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
				cout << length[i][j];
			cout << endl;
		}
	}*/

	void bfs()
	{
		int coun = 0;
		q.insert(x_st*10+y_st);
		while (!q.empty())
		{
			coun++;
			int x = q.first()/10-1;
			int y = q.first()%10-1;
			//cout << coun << ") " << "x=" << x << ' ' << "y=" << y << endl;
			for (int i = 0; i < 4; i++)
			{
				if (map_s[x][y][i] == 1)
				{
					//cout << endl << "YES! " << i << endl;
					if (i == 0)
					{
						if (length[x-1][y]==0 && (x-1 != x_st-1 || y != y_st-1))
						{
							length[x-1][y] = length[x][y]+1;
							q.insert(x*10+y+1);
						}
					}
					if (i == 1)
					{
						if (length[x][y+1] == 0 && (x != x_st-1 || y+1 != y_st-1))
						{
							length[x][y+1] = length[x][y]+1;
							q.insert((x+1)*10+y+2);
						}
					}
					if (i == 2)
					{
						if (length[x+1][y] == 0 && (x+1 != x_st-1 || y != y_st-1))
						{
							length[x+1][y] = length[x][y]+1;
							q.insert((x+2)*10+y+1);
						}
					}
					if (i == 3)
					{
						if (length[x][y-1] == 0 && (x != x_st-1 || y-1 != y_st-1))
						{
							length[x][y-1] = length[x][y]+1;
							q.insert((x+1)*10+y);
						}
					}
				}
			}
			q.pop();
		}
		int x = x_f-1, y = y_f-1;
		while(x != x_st-1 || y != y_st-1)
		{
			if (length[x-1][y]==length[x][y]-1)
			{
				ans.push_back(3);
				x--;
				continue;
			}
			if (length[x+1][y]==length[x][y]-1)
			{
				ans.push_back(1);
				x++;
				continue;
			}

			if (length[x][y-1]==length[x][y]-1)
			{
				ans.push_back(2);
				y--;
				continue;
			}
			if (length[x][y+1]==length[x][y]-1)
			{
				ans.push_back(4);
				y++;
				continue;
			}
		}

		for (int i = ans.size()-1; i >=0; i --)
		{
			answer.push_back(ans[i]);
		}
	}

};
