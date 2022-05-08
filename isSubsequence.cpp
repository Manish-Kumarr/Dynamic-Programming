#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        int K[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                if (i == 0 || j == 0)
                    K[i][j] = 0;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    K[i][j] = 1 + K[i - 1][j - 1];
                else
                    K[i][j] = max(K[i - 1][j], K[i][j - 1]);
            }

        if (s.size() == K[n][m])
            return true;

        return false;
    }
};

int main()
{
    Solution s;
    string x = "abc";
    string y = "xagbc";
    cout << s.isSubsequence(x, y);
    return 0;
}