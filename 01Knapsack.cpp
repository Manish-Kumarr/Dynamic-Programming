#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int t[10][10];
int K[10][10];

// Recursion
int knapsack(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] <= W)
        return max(knapsack(wt, val, W, n - 1), val[n - 1] + knapsack(wt, val, W - wt[n - 1], n - 1));
    else if (wt[n - 1] > W)
        return knapsack(wt, val, W, n - 1);
}

// Memoziation
int Mknapsack(int wt[], int val[], int W, int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (t[n][W] != -1)
        return t[n][W];
    if (wt[n - 1] <= W)
        return t[n][W] = max(Mknapsack(wt, val, W, n - 1), val[n - 1] + Mknapsack(wt, val, W - wt[n - 1], n - 1));
    else if (wt[n - 1] > W)
        return t[n][W] = Mknapsack(wt, val, W, n - 1);
}

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
                                  K[i - 1][w - wt[i - 1]],
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
    memset(t, -1, sizeof(t));
    cout << TDKnapsack(wt, val, W, n);
    return 0;
}
