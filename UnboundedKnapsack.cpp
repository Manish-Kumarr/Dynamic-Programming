#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int K[10][10];
// Top-Down
int TDKnapsack(int *wt, int *val, int W, int n)
{
    int i, w;
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                  K[i][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;
    int n = sizeof(wt) / sizeof(wt[0]);
    cout << TDKnapsack(wt, val, W, n);
    return 0;
}
