#include <bits/stdc++.h>

using namespace std;

int main(){
    int V = 6;
    int S = 4;
    vector<vector<pair<int, int>>> adj = vector<vector<pair<int, int>>>(V);
    adj[0].emplace_back(pair(1, 10));
    adj[0].emplace_back(pair(5, 8));
    adj[1].emplace_back(pair(3, 2));
    adj[2].emplace_back(pair(1, 1));
    adj[3].emplace_back(pair(2, -2));
    adj[4].emplace_back(pair(3, -1));
    adj[4].emplace_back(pair(1, -4));
    adj[5].emplace_back(pair(4, 1));
    vector<int> distance = vector<int>(V, INT16_MAX);
    distance[S] = 0;
    for (int j = 0; j < V; ++j) {
        for (int i = 0; i < V; ++i) {
            for (auto w: adj[i]) {
                if(distance[i] != INT16_MAX){
                    distance[w.first] = min(distance[i] + w.second, distance[w.first]);
                }
            }
        }
    }
    for (auto dis: distance) {
        cout << dis <<"\n";
    }
    cout << "\n";
}
