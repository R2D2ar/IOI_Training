#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int number_coins, total;
        cin >> number_coins >> total;
        vector<int> coins = vector<int>(number_coins);
        for (int j = 0; j < number_coins; ++j) {
            cin >> coins[j];
        }
        vector<int> T = vector<int>(total+1);
        T[0] = 0;
        vector<int> R = vector<int>(total+1);
        for (int j = 1; j <= total; ++j) {
            T[j] = std::numeric_limits<int>::max() -1;
            R[j] = -1;
        }
        for (int j = 0; j < number_coins; ++j) {
            for (int k = 1; k <= total; ++k) {
                if (k >= coins[j]){
                    if (T[k - coins[j]] + 1 < T[k]) {
                        T[k] = 1 + T[k - coins[j]];
                        R[k] = j;
                    }
                }
            }
        }
        if (R[R.size() - 1] == -1) {
            cout << "No solution is possible";
            continue;
        }
        int start = R.size() - 1;
        cout << "Case #" << i+1 << ": ";
        vector<int> output = vector<int>(number_coins, 0);
        while ( start != 0 ) {
            int j = R[start];
            output[j]++;
            start = start - coins[j];
        }
        for (int j = 0; j < number_coins; ++j) {
            cout << output[j] << " ";
        }
        cout << "\n";

    }

}
