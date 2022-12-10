#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;


int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int V;
        cin >> V;
        vector<vector<pair<int, int>>> adj = vector<vector<pair<int, int>>>(V);
        for (int j = 0; j < V; ++j) {
            for (int k = 0; k < V; ++k) {
                int w;
                cin >> w;
                if(j == k) continue;
                adj[j].emplace_back(k, w);
            }
        }

        ll total_distance = 0;
            vector<ll> distance = vector<ll>(V, -1);
            vector<int> order = vector<int>(V);
            queue<int> queue;
            priority_queue<pli, vector<pli>, greater<pli>> pq;
            pq.push({0, 0});
            while (pq.size()){
                ll d; int v;
                tie(d, v) = pq.top();
                pq.pop();
                if(distance[v] != -1 && distance[v] <= d) continue;
                order.emplace_back(v);
                distance[v] = d;
                for(auto p: adj[v])
                    pq.push({d + p.second, p.first});
            }
            for (auto item:distance) {
                total_distance+=item;
            }
            total_distance += distance[order[1]];
        cout << "Case #" << i+1 << ": " << total_distance << "\n";
    }
    return 0;
}
