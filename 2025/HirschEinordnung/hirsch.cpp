#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n1, n2;
    cin >> n1 >> n2;
    cout << n1 << " " << n2 << endl;

    if (n1 == 0 && n2 == 0) {
        cout << "Not a moose" << endl;
        return -1;
    }

    if (n1 == n2) {
        cout << "Even " << n1 * 2 << endl;
    }
    else {
        cout << "Odd " << max(n1, n2) * 2 << endl;
    }

    return 0;
}