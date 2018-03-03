/****Author: Barish Namazov****/
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t = "";
    getline (cin, s);
    int len = s.size();
    while (s[0] == ' ')
        s.erase (s.begin());

    while (s[s.size() - 1] == ' ')
        s.erase (s.begin() + s.size() - 1);

    while (s[s.size() - 1] != ' ') {
        t += s[s.size() - 1];
        s.erase (s.begin() + s.size() - 1);
    }
    string ans = "";
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == ' ') {
            ans += ' ';
            while (s[i] == ' ')
                i ++;
        }
        ans += s[i];
    }
    ans.erase (ans.begin() + ans.size() - 1);
    ans.erase (ans.begin() + ans.size() - 1);
    len -= ans.size() + t.size();
    for (int i = 1; i <= len; i++)
        ans += '-';
    reverse (t.begin(), t.end());
    ans += t;
    cout << ans << endl;
    return 0;
}
