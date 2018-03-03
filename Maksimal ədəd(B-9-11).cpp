/****Author: Barish Namazov****/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, n=0, i, j, max=0, a[31][31], fl;
    cin >> k;
    while (k > 0) {
    a[0][n ++] = k % 2;
    k /= 2;
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < n; j++)
            a[i][j] = a[0][(j + i) % n];
        fl = 0;
        for(j = n - 1; j >= 0 && fl == 0; j--) {
            if (a[max][j] > a[i][j])
                fl = 1;
            if(a[max][j] < a[i][j])
                fl = 2;
        }
        if(fl == 2)
            max = i;
    }
    j = 1;
    for(i = 0; i < n; i++) {
    k += a[max][i] * j;
    j *= 2;
    }
    cout << k << endl;
    return 0;
}
