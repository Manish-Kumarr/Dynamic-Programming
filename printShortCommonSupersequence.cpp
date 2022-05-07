#include <bits/stdc++.h>
using namespace std;

void minInsertionDeletion(string x, string y, int n, int m)
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

    int i = n, j = m;
    string str;
    while (i > 0 || j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            str.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (K[i][j - 1] > K[i - 1][j])
            {
                str.push_back(y[j - 1]);
                j--;
            }
            else
            {
                str.push_back(x[i - 1]);
                i--;
            }
        }
    }

    while (i > 0)
    {
        str.push_back(x[i - 1]);
        i--;
    }

    while (j > 0)
    {
        str.push_back(y[j - 1]);
        j--;
    }

    reverse(str.begin(), str.end());
    cout << "SHORTEST COMMON SUPERSEQUENCE IS : " << str;
}

int main()
{
    string x = "ramca";
    string y = "csa";
    int n = x.size();
    int m = y.size();
    minInsertionDeletion(x, y, n, m);
    return 0;
}
