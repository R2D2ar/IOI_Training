#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    int n = 0;
    cin >> n;
    ll o = -1;
    for (int i = 0; i < n; ++i) {
        ll temp;
        cin >> temp;
        o = max(o, temp);
    }

    cout << o*o*o << "\n";

    return 0;
}