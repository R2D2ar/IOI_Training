#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    //pair first = position, second = eta/ch false = eta
    map<int, pair<int, bool>> player_data;
    map<int, int> graph;
    vector<int> players = vector<int>(N*2);
    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;
        players[i] = k;
        player_data[k] = pair(i + 1, false);
    }
    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;
        players[i+N] = k;
        player_data[k] = pair(i + 1, true);
    }
    std::sort(players.begin(), players.end());
    vector<int> adj = vector<int>(N*2, -1);
    vector<bool> used(N*2);

    for (int j = 0; j < N*2; ++j) {
        graph[j] = players[j];
    }
    int begin = 0;
    int win = 0;
    for (int i = 0; i < N*2; ++i) {
        if(!used[i] && !player_data[graph[i]].second){
            begin = i;
            used[i] = true;
            for (int j = begin+1; j < N*2; ++j) {
                if(!used[j] && player_data[graph[j]].second){
                    adj[begin] = j;
                    used[j] = true;
                    win++;
                    break;
                }
                if(i-1 == N*2){
                    for (int z = 0; z < N * 2; ++z) {
                        if(!used[z] && player_data[graph[z]].second){
                            adj[begin] = z;
                            used[z] = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << win << "\n";

    for (int i = 0; i < N*2; ++i) {
        if(adj[i] == -1) continue;
        cout << player_data[graph[i]].first << " " << player_data[graph[adj[i]]].first << "\n";
    }



    return 0;
}