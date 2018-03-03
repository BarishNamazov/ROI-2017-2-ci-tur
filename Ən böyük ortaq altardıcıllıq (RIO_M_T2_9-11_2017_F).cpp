/****Author: Barish Namazov****/
#include <bits/stdc++.h>
using namespace std;

int arr[1001], brr[1001], dp[1001][1001];
int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> brr[i];

     for (int i = 1; i <= n; i++)
       for (int j = 1; j <= m; j++)
            if (arr[i] == brr[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
    cout << dp[n][m] << endl;
    return 0;
}
