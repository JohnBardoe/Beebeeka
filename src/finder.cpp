#include <vector.h>
#include <Arduino.h>

class Finder{
public:
    int map[4][8][4];
    bool bolmap[4][8];
    int xcube, ycube;
    int xans, yans;
    int s=0;
    Finder(int x, int y)
    {
        xcube = x;
        ycube = y;
    }

    void Find()
    {
        int x_s, y_s;
        x_s = max(xcube-3, 0);
        y_s = max(ycude-3, 0);
        int x_f, y_f;
        x_f = min(xcube+3, 7);
        y_f = min(ycude+3, 3);
        for (int i = y_s; i <= y_f; i++)
        {
            for (int j = x_s; j <= x_f; j++)
            {
                bolmap[i][j] = 1;
            }
        }
        for (int i = y_s; i <= y_f; i++)
        {
            for (int j = x_s; j <= x_f; j++)
            {
                int count = 0;
                for (int k = 0; k < 4; k++)
                {
                    count+=map[i][j][k];
                }
                if (count == 3 || count == 4)
                {
                    int x_s1, y_s1, x_f1, y_f1;
                    x_s1=max(0, j-1);
                    y_s1=max(0, i-1);
                    x_f1=min(7, j+1);
                    y_s1=min(0, i+1);
                    for (int k = y_s1; k <= y_f1; k++)
                    {
                        for (int p = x_s1; p <= x_f1; p++)
                        {
                            bolmap[k][p]=1;
                        }
                    }
                    int ar=0;
                    for (int k = 0; k < 4; k++)
                    {
                        for (int p = 0; p < 8; p++)
                        {
                            if (bolmap[k][p]==1)
                                ar++;
                        }
                    }
                    if (ar>s)
                    {
                        xans=j;
                        yans=i;
                        s=ar;
                    }


                    for (int k = y_s1; k <= y_f1; k++)
                    {
                        for (int p = x_s1; p <= x_f1; p++)
                        {
                            bolmap[k][p]=0;
                        }
                    }

                    for (int k = y_s; k <= y_f; k++)
                    {
                        for (int p = x_s; p <= x_f; p++)
                        {
                            bolmap[i][j] = 1;
                        }
                    }       
                }
            }
        }
    }
};