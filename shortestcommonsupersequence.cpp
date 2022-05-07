#include <bits/stdc++.h>
using namespace std;

int shortestCommonSupersequence(string x, string y, int n, int m)
{
    int K[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (i == 0 || j == 0)
                K[i][j] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
                K[i][j] = 1 + K[i - 1][j - 1];
            else
                K[i][j] = max(K[i][j - 1], K[i - 1][j]);
        }

    return ((n + m) - K[n][m]);
}

int main()
{
    string x = "MHNISH";
    string y = "MANSH";
    int n = x.size();
    int m = y.size();

    cout << "SCS => " << shortestCommonSupersequence(x, y, n, m);
    return 0;
}
