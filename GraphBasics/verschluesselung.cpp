#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> keys = vector<int>(N);
    for (int i = 0; i < N; ++i) {
        cin >> keys[i];
    }
    std::sort(keys.begin(), keys.end());
    vector<int> decoded = vector<int>(M);
    for (int i = 0; i < M; ++i) {
        int y, k;
        cin >> y >> k;
        cout << y-keys[k-1] << "\n";
    }
}
