/****Author: Barish Namazov****/
#include <bits/stdc++.h>
using namespace std;
 
int n, m;
int arr[501][501];
 
char ch;
 
struct point {
    int x, y;
};
 
point fin, st;
 
int check(int i, int j)
{
    if(i < 1 || i > n || j < 1 || j > m || arr[i][j])
        return 0;
    return 1;
}
 
int main()
{
    cin >> n; m = n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> ch;
            if (ch == 'O')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
            if (ch == '@')
                st.x = i, st.y = j;
            if (ch == 'X')
                fin.x = i, fin.y = j;
        }
 
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
 
    queue <point> q;
    arr[st.x][st.y] = 1;
    q.push (st);
    while(!q.empty())
    {
        point cur = q.front(), tmp;
        q.pop();
        if (cur.x == fin.x && cur.y == fin.y)
            break;
        for (int k = 0; k < 4; k++) {
            tmp.x = cur.x + dx[k], tmp.y = cur.y + dy[k];
            if (check (tmp.x, tmp.y))
                q.push(tmp), arr[tmp.x][tmp.y] = arr[cur.x][cur.y] + 1;
        }
    }
    if (arr[fin.x][fin.y] == 0)
        cout << "N" << endl;
    else
        cout << "Y" << endl << arr[fin.x][fin.y] - 1 << endl;
    return 0;
}
