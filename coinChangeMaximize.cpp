#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    int K[n + 1][amount + 1];

    for (int i = 1; i <= amount; i++)
        K[0][i] = 0;
    for (int i = 0; i <= n; i++)
        K[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] <= j)
                K[i][j] = K[i - 1][j] + K[i][j - coins[i - 1]];
            else
                K[i][j] = K[i - 1][j];
        }
    }

    return K[n][amount];
}

int main()
{
    vector<int> v = {1, 2, 3, 5};
    int amount = 5;
    cout << coinChange(v, amount);
    return 0;
}
