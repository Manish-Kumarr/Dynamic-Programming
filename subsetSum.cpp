#include <bits/stdc++.h>
using namespace std;

bool isSubset(int *arr, int n, int sum)
{
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
    return K[n][sum];
}

int main()
{
    int arr[] = {3, 24, 4, 12, 5, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 90;
    cout << isSubset(arr, n, sum);
    return 0;
}
