#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;


int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int E, V;
        cin >> E >> V;
        vector<vector<pair<int, int>>> adj = vector<vector<pair<int, int>>>(E);
        for (int j = 0; j < V; ++j) {
            int a, b, w;
            cin >> a >> b >> w;
            --a, --b;
            adj[a].emplace_back(b, w);
            adj[b].emplace_back(a, w);
        }

        vector<ll> distance = vector<ll>(E, -1);
        queue<int> queue;
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push({0, 0});
        while (pq.size()) {
            ll d;
            int v;
            tie(d, v) = pq.top();
            pq.pop();
            if (distance[v] != -1 && distance[v] <= d) continue;
            distance[v] = d;
            for (auto p: adj[v])
                pq.push({d + p.second, p.first});
        }

        cout << "Case #" << i + 1 << ": " << distance[E - 1] << "\n";
    }
    return 0;
}
