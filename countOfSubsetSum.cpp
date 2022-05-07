#include <bits/stdc++.h>
using namespace std;

int countOfSubsetSum(int *arr, int n, int sum)
{
    int K[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        K[i][0] = 1;
    for (int i = 1; i <= sum; i++)
        K[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                K[i][j] = K[i - 1][j] + K[i - 1][j - arr[i - 1]];
            else
                K[i][j] = K[i - 1][j];
        }
    }
    return K[n][sum];
}

int main()
{
    int arr[] = {1, 5, 5, 11, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;
    cout << countOfSubsetSum(arr, n, sum);
    return 0;
}
