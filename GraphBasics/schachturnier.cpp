#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        vector<vector<int>> teams = vector<vector<int>>(N);
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < 5; ++k) {
                int o;
                cin >> o;
                teams[j].emplace_back(o);
            }
            std::sort(teams[j].begin(), teams[j].end());
            std::reverse(teams[j].begin(), teams[j].end());
        }
        std::sort(teams.begin(), teams.end());
        cout << "Case #" << i+1 << ":\n";
        for (int k = N-1; k >= 0; --k) {
            for (int j = 0; j < 5; ++j) {
                cout << teams[k][j] << " ";
            }
            cout << "\n";
        }

    }
    return 0;
}
