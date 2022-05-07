#include <bits/stdc++.h>
using namespace std;

vector<int> subsetSum(int *arr, int n, int sum)
{
    vector<int> v;
    bool K[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        K[i][0] = true;
    for (int i = 1; i <= sum; i++)
        K[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                K[i][j] = K[i - 1][j] || K[i - 1][j - arr[i - 1]];
            else
                K[i][j] = K[i - 1][j];
        }
    }

    for (int i = 0; i <= sum / 2; i++)
        if (K[n][i])
            v.push_back(i);

    return v;
}

int minimumSumSubset(int *arr, int n, int range)
{
    vector<int> v;
    int mn = INT_MAX;
    v = subsetSum(arr, n, range);

    for (int i = 0; i < v.size(); i++)
        mn = min(mn, range - 2 * v[i]);

    return mn;
}

int main()
{
    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int range = 0;
    for (int i = 0; i < n; i++)
        range += arr[i];
    cout << minimumSumSubset(arr, n, range);
    return 0;
}
