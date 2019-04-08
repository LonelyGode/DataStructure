#include <iostream>
#include <map>
#include <algorithm>
#include <stack>
#define eof "."
using namespace std;

int main() {
    string s;
    char a[101], b[101];
    int d = 0, c = 0;
    int flag = 1;
    map<char, char> q;
    q['('] = ')';
    q['{'] = '}';
    q['['] = ']';
    q['<'] = '>';
    while(cin >> s && s != eof) {
        for(int j = 0; j < s.size(); j ++) {
            if(s[j] == '[' || s[j] == ']' || s[j] == '{' || s[j] == '}' || s[j] == '(' || s[j] == ')')a[d ++] = s[j];
            else if(s[j] == '/' && s[j + 1] == '*')a[d ++] = '<', j ++;
            else if(s[j] == '*' && s[j + 1] == '/')a[d ++] = '>', j ++;
        }
    }
    int j;
    for(j = 0; j < d; j ++) {
        if(a[j] == '(' || a[j] == '[' || a[j] == '{' || a[j] == '<') {
            b[c ++] = a[j];
        } else if(c && q[b[c - 1]] == a[j])c --;
        else {
            flag = 0;
            cout << "NO" << endl;
            if(!c) {
                if(a[j] == '>')cout << "?-*/";
                else cout << "?-" << a[j];
            } else {
                if(b[c - 1] == '<')cout << "/*-?";
                else
                    cout << b[c - 1] << "-?";
            }
            break;
        }
    }
    if(flag) {
        if(!c)cout << "YES" << endl;
        else {
            cout << "NO" << endl;
            if(b[c - 1] == '<')cout << "/*-?";
            else
                cout << b[c - 1] << "-?";
        }
    }
}


