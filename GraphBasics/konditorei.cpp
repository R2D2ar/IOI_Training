#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> solution;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> in(n, 0);
        vector<vector<int>> adj = vector<vector<int>>(n);
        for (int j = 0; j < n-1; ++j) {
            int h1, h2;
            cin >> h1 >> h2;
            adj[h1].emplace_back(h2);
            adj[h2].emplace_back(h1);
            ++in[h1], ++in[h2];
        }

        queue<int> active;
        for (int j = 0; j < n; ++j) {
            if(in[j] == 1) active.push(j);
        }

        vector<int> topological_order;

        while(!active.empty()){
            int s = active.front();
            active.pop();
            topological_order.emplace_back(s);
            for (auto item: adj[s]){
                if (--in[item] == 1){
                    active.push(item);
                }
            }
        }
        solution.emplace_back(topological_order.back());
    }
    for (int i = 0; i < solution.size(); ++i) {
        cout << "Case #" << i+1 << ": " << solution[i] << "\n";
    }
}
