#include <bits/stdc++.h>

#define NotFound -1
using namespace std;

void BulidMatch(char *pattern, int *match) {
    int i, j;
    int m = strlen(pattern);
    match[0] = -1;
    for (j = 1; j < m; j++) {
        i = match[j - 1];
        while ((i >= 0) && (pattern[i + 1] != pattern[j])) {
            i = match[i];
        }
        if (pattern[i + 1] == pattern[j]) {
            match[j] = i + 1;
        } else
            match[j] = -1;
    }

}

int KMP(char *string, char *pattern) {
    int n = strlen(string);
    int m = strlen(pattern);
    int s = 0, p = 0;
    if (n < m) {
        return NotFound;
    }
    int match[m];
    BulidMatch(pattern, match);

    while (s < n && p < m) {
        if (string[s] == pattern[p]) {
            s++;
            p++;
        } else if (p > 0) {
            p = match[p - 1] + 1;
        } else
            s++;
    }
    return (p == m) ? (s - m) : NotFound;
}

int main() {
    int N, i, p;
    char string[1000001];
    char pattern[100001];
    cin >> string >> N;
    for (i = 0; i < N; i++) {
        cin >> pattern;
        p = KMP(string, pattern);
        if (p == NotFound) {
            cout << "Not Found" << endl;
        } else {
            cout << p + string << endl;
        }
    }
    return 0;
}




