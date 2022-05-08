#include <bits/stdc++.h>
using namespace std;

// This code is written by myself.
// DP -> No. of insertion to make a string pallindrome == No. of deletion
// So we can write that code also

// Formula = length of string - lenth of LCS
void minInsertionToMakePallindrome(string x, int n)
{
    int i = 0, j = n - 1;
    int count = 0;
    while (i < j)
    {
        if (x[i] == x[j])
        {
            i++, j--;
        }
        else if (x[i] == x[j - 1])
        {
            count++;
            j--;
        }
        else
        {
            count++;
            i++;
        }
    }
    cout << count;
}

int main()
{
    string s = "MANISH";
    int n = s.size();
    minInsertionToMakePallindrome(s, n);
    return 0;
}
