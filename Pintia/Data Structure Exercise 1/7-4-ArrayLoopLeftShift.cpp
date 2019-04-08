#include <bits/stdc++.h>
using namespace std;

bool flag = true;

int main(int argc, char** argv) {
    int l, s;
    cin >> l >> s;
    if(s > l) {
        s = s % l;
    }
    int array[l + s];
    for(int i = 0; i < l; i++) {
        cin >> array[i];
    }
    for(int j = 0; j < s; j++) {
        array[l + j] = array[j];
    }
    for(int k = 0; k < l; k++) {
        array[k] = array[s + k];
        if(!flag) {
            cout << " " << array[k];
        } else {
            flag = false;
            cout << array[k];
        }
    }
}



