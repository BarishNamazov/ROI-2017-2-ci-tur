/****Author: Barish Namazov****/
#include <bits/stdc++.h>
using namespace std;

const int reg = 'A' - 'a';

bool check(char symbol) {
    return symbol >= '1' && symbol <= '9' || symbol >= 'a' && symbol <= 'z' || symbol >= 'A' && symbol <= 'Z' ? true : false;
}

bool ispal(char *word, int begin, int end) {
    return end <= begin ? true : word[begin] != word[end] ? false : ispal(word, ++begin, --end);
}

void makelower(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') word[i] -= reg;
    }
}

int main()
{
    char word[100001];
    int len, mxlen = 0, index = 0;
    for (int i = 1; cin >> word; i++) {
        makelower(word);
        if (!check(word[strlen(word) - 1])) word[strlen(word) - 1] = '\0';
        len = strlen(word);
        if (len > mxlen) {
            if (ispal(word, 0, len - 1)) {
                mxlen = len;
                index = i;
            }
        }
    }
    cout << index << endl;
    return 0;
}
