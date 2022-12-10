#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;


int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj = vector<vector<pair<int, int>>>(V);
        for (int j = 0; j < E; ++j) {
            int a, b, w;
            cin >> a >> b >> w;
            --a, --b;
            adj[a].emplace_back(b, w);
            adj[b].emplace_back(a, w);
        }

        ll total_distance = 0;
        for (int j = 0; j < V; ++j) {
            vector<ll> distance = vector<ll>(V, -1);
            queue<int> queue;
            priority_queue<pli, vector<pli>, greater<pli>> pq;
            pq.push({0, j});
            while (pq.size()){
                ll d; int v;
                tie(d, v) = pq.top();
                pq.pop();
                if(distance[v] != -1 && distance[v] <= d) continue;
                distance[v] = d;
                for(auto p: adj[v])
                    pq.push({d + p.second, p.first});
            }
            for (auto item:distance) {
                total_distance+=item*2;
            }
        }
        cout << "Case #" << i+1 << ": " << total_distance << "\n";
    }
    return 0;
}
