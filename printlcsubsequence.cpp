#include <bits/stdc++.h>
using namespace std;

string printlcsubsequence(string x, string y, int n, int m)
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
                K[i][j] = max(K[i - 1][j], K[i][j - 1]);
        }

    int i = n, j = m;
    string str;
    while (j > 0 || i > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            str = x[i - 1] + str;
            i--;
            j--;
        }
        else
        {
            if (K[i - 1][j] > K[i][j - 1])
                i--;
            else
                j--;
        }
    }

    return str;
}

int main()
{
    string x = "MHNISH";
    string y = "MANSH";
    int n = x.size();
    int m = y.size();
    cout << "LONGEST COMMON SUBSEQUENCE IS : " << printlcsubsequence(x, y, n, m);
    return 0;
}
