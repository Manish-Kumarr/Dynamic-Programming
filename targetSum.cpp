#include <bits/stdc++.h>
using namespace std;

int findTargetSum(vector<int> &v, int n, int target)
{
    int sum = accumulate(v.begin(), v.end(), 0);
    if (target > sum || (sum - target) % 2 != 0)
        return 0;

    int newTarget = (sum - target) / 2;

    int K[n + 1][newTarget + 1];
    int countO = 0;

    for (int i = 0; i < n; i++)
        if (!v[i])
            countO++;

    for (int i = 0; i <= n; i++)
        K[i][0] = 1;
    for (int i = 1; i <= newTarget; i++)
        K[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= newTarget; j++)
        {
            if (v[i - 1] > j || v[i - 1] == 0)
                K[i][j] = K[i - 1][j];
            else
                K[i][j] = K[i - 1][j - v[i - 1]] + K[i - 1][j];
        }
    }
    return K[n][newTarget] * pow(2, countO);
}

int main()
{
    vector<int> v = {1, 1, 1, 1, 1};
    int n = v.size();
    int target = 3;
    cout << findTargetSum(v, n, target);
    return 0;
}
