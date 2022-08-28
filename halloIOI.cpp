#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long target[n];
    for (int i = 0; i < n; ++i) {
       cin >> target[i];
    }
    sort(target, target+n);

    cout << setprecision(18) << pow(target[n-1], 3);

    return 0;
}