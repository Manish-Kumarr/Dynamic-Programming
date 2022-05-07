#include <bits/stdc++.h>
using namespace std;

// Recursive
int lcs(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (x[n - 1] == y[m - 1])
        return 1 + lcs(x, y, n - 1, m - 1);
    else
        return max(lcs(x, y, n - 1, m), lcs(x, y, n, m - 1));
}

// Memoziation
int Mlcs(string x, string y, int n, int m)
{
    int K[n + 1][m + 1];
    memset(K, -1, sizeof(K));

    if (n == 0 || m == 0)
        return 0;
    if (K[n][m] != -1)
        return K[n][m];
    if (x[n - 1] == y[m - 1])
        return K[n][m] = 1 + lcs(x, y, n - 1, m - 1);

    return K[n][m] = max(lcs(x, y, n - 1, m), lcs(x, y, n, m - 1));
}

// Top-Down -> Dynamic Programming
int Dlcs(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    return dp[n][m];
}

int main()
{
    string x = "GXTXAYB";
    string y = "AGGTAB";
    int n = x.size();
    int m = y.size();

    cout << Dlcs(x, y, n, m);

    return 0;
}
