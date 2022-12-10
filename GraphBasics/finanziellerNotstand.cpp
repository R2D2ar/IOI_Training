#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    vector<int> solution;
    for (int i = 0; i < T; ++i) {
        //Erstelle Adjazenzliste
        int K;
        cin >> K;
        vector<vector<int>> adj = vector<vector<int>>(K);
        vector<int> in(K, 0);
        vector<bool> visited (K, false);
        vector<pair<int, int>> data = vector<pair<int, int>>(K, pair(1, 0));
        for (int j = 0; j < K - 1; ++j) {
            int s1, s2;
            cin >> s1 >> s2;
            --s1, --s2;
            adj[s1].emplace_back(s2);
            adj[s2].emplace_back(s1);
            ++in[s1], ++in[s2];
        }

        queue<int> active;
        for (int j = 0; j < K; ++j) {
            if (in[j] == 1) {
                active.push(j);
                visited[j] = true;
            }
        }
        vector<int> topological_order;
        while (!active.empty()) {
            int s = active.front();
            active.pop();
            topological_order.emplace_back(s);
            for (auto k: adj[s]) {
                if(--in[k] == 1){
                    for (auto j : adj[k]) {
                        if(data[k].first == 1 && data[k].second == 0) {
                            data[k].first += data[j].second;
                            data[k].second += data[j].first;
                        }
                    }
                    active.push(k);
                    visited[k] = true;
                }
            }
        }
        int size = topological_order.size();
        solution.emplace_back(max(data[topological_order[size-1]].first, data[topological_order[size-1]].second));

    }
    for (int i = 0; i < solution.size(); ++i) {
        cout << "Case #" << i + 1 << ": " << solution[i] << "\n";
    }

    return 0;
}