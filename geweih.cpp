#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int links, rechts;
    cin >> links >> rechts;

    if(links == rechts && links != 0) cout << "Even " << links*2 << "\n";
    else if(links != rechts) cout << "Odd " << max(links, rechts)*2 << "\n";
    else cout << "Not a moose\n";

    return 0;
}