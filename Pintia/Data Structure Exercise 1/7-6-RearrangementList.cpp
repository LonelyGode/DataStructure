#include <bits/stdc++.h>
using namespace std;

typeid struct Link {
    int Address;
    int Data;
    int Next;
}

void CreateList() {
    int firstAddress, n;
    cin >> firstAddress >> n;
    Link link[n];
    for(int i = 0; i < n; i++) {
        cin >> link[i].Address >> link[i].Data >> link[i].Next;
    }

}

int main(int argc, char** argv) {

}




