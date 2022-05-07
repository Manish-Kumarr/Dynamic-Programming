#include <bits/stdc++.h>
using namespace std;

int lcsubstring(string x, string y, int n, int m)
{
    int K[n + 1][m + 1];
    int mx = INT_MIN;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if (i == 0 || j == 0)
                K[i][j] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
                K[i][j] = 1 + K[i - 1][j - 1];
            else
                K[i][j] = 0;
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mx = max(mx, K[i][j]);

    return mx;
}

int main()
{
    string x = "MANISH";
    string y = "MANSH";
    int n = x.size();
    int m = y.size();
    cout << "LONGEST COMMON SUBSTRING IS : " << lcsubstring(x, y, n, m);
    return 0;
}
