/****Author: Barish Namazov****/
#include <bits/stdc++.h>
using namespace std;

#define MAX 101

int arr[MAX][MAX];
int dp[MAX][MAX];
int n;

int main(){
    memset(arr, -63, sizeof(arr));
    memset(dp, -63, sizeof(dp));
    cin >> n;
    for(int i=n; i>=1; --i)
        for(int j=1; j<=n; ++j)
            cin >> arr[j][i];
    dp[1][1] = arr[1][1];
    for(int i=2; i<=n; ++i)
        dp[1][i] = dp[1][i-1] + arr[1][i], dp[i][1] = dp[i-1][1] + arr[i][1];
    for(int i=2; i<=n; ++i)
        for(int j=2; j<=n; ++j)
            dp[i][j] = max(dp[i-1][j] + arr[i][j], max(dp[i][j-1] + arr[i][j], dp[i-1][j-1] + arr[i][j]));
    cout << dp[n][n] << endl;
    return 0;
}
