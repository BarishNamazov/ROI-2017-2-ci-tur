/****Author: Barish Namazov****/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;
const int INF = 1000000000;

int n, m, a, b;
vector <int> g[MAX];
int dis[MAX];

void bfs (int v) {
    for (int u = 0; u < MAX; u ++)
        dis[u] = INF;
    dis[v] = 0;
    queue <int> qu;
    qu.push (v);
    while (!qu.empty ()) {
        int cur = qu.front ();
        qu.pop ();
        for (int u = 0; u < g[cur].size(); u ++)
            if (dis[g[cur][u]] == INF)
                dis[g[cur][u]] = dis[cur] + 1, qu.push (g[cur][u]);
    }
}

int main()
{
    cin >> n >> m;
    while (m --) {
        cin >> a >> b;
        g[a].push_back (b);
        g[b].push_back (a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        bfs (i);
        for (int j = 1; j <= n; j++)
            if (dis[j] != INF)
                ans += dis[j];
    }
    cout << ans / 2 << endl;
    return 0;
}
