/****Author: Barish Namazov****/
#include <bits/stdc++.h>
using namespace std;

#define MAX 10010

int used[MAX] = {0};
int arr[MAX];
int p[] = {2, 3, 5, 7, 11};
int n;

int main()
{
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> arr[i];
    for(int i=0; i<5; ++i)
        for(int j=0; j<n; ++j)
            if(arr[j] % p[i] == 0 && !used[j]) {
                cout << arr[j] << " ";
                used[j] = 1;
            }
    for(int i=0; i<n; ++i)
        if(!used[i])
            cout << arr[i] << " ";
    cout << endl;
    return 0;
}
