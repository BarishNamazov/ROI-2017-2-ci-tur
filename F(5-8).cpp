/****Author: Barish Namazov****/
#include <bits/stdc++.h>
using namespace std;

double arr[10001];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int mx = 0, mn = 0, flag = 0;
    for (int i = 2; i <= n - 1; i++)
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
            if (flag == 0)
                mn = i, flag = 1;
            else
                if (i - mn > mx)
                    mx = i - mn, mn = i;
                else
                	mn = i;
    cout << mx << endl;
    return 0;
}
