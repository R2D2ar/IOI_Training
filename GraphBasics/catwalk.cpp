#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> schoenheit;
int highest(vector<int> numbers){
    int schoen = 0;
    int index = 0;

    for(int number : numbers){
        if (schoenheit[number] > schoen){
            index = number;
            schoen = schoenheit[number];
        }
    }
    return index;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    schoenheit = vector<int>(N);
    vector<int> katzen(N);
    int katzenSumme = 0;
    vector<vector<int>> adj = vector<vector<int>>(N);

    for (int i = 0; i < N; ++i) {
        int s;
        cin >> s;
        schoenheit[i] = s;
    }
    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;
        katzen[i] = k;
    }
    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;
        for (int j = 0; j < K; ++j) {
            int o;
            cin >> o;
            adj[i].emplace_back(--o);
        }
    }

    queue<int> queue;
    queue.push(0);
    int schoen = schoenheit[0];
    katzenSumme+=katzen[0];
    while (!queue.empty()){
        int s = queue.front();
        queue.pop();
        int u = highest(adj[s]);
            if(schoenheit[u] > schoen){
                queue.push(u);
                katzenSumme+=katzen[u];
                schoen = schoenheit[u];
            }
    }
    cout << katzenSumme;


    return 0;
}
