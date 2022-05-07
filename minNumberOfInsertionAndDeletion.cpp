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

    cout << "Insertion : " << n - K[n][m];
    cout << "\nDeletion : " << m - K[n][m];
}

int main()
{
    string x = "heap";
    string y = "pea";
    int n = x.size();
    int m = y.size();
    minInsertionDeletion(x, y, n, m);
    return 0;
}
