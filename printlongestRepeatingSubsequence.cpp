#include <bits/stdc++.h>
using namespace std;

void printlongestRepeatingSubsequence(string x, int n)
{
    int K[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if (i == 0 || j == 0)
                K[i][j] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == x[j - 1] && i != j)
                K[i][j] = 1 + K[i - 1][j - 1];
            else
                K[i][j] = max(K[i][j - 1], K[i - 1][j]);
        }

    // Print
    int i = n,
        j = n;
    string str;
    while (i > 0 || j > 0)
    {
        if (K[i][j] == K[i - 1][j - 1] + 1)
        {
            str = x[i - 1] + str;
            i--;
            j--;
        }
        else if (K[i][j] == K[i - 1][j])
            i--;
        else
            j--;
    }

    cout << str;
}

int main()
{
    string x = "AABEBCDDE";
    int n = x.size();
    printlongestRepeatingSubsequence(x, n);
    return 0;
}
