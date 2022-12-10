#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> adj = vector<vector<ll>>(N);
    //red = 0 and blue = 1 and no color = -1
    for (ll i = 0; i < M; ++i) {
        ll n1, n2;
        cin >> n1 >> n2;
        adj[--n1].emplace_back(--n2);
        adj[n2].emplace_back(n1);
    }

    vector<ll> color = vector<ll>(N, -1);
    vector<ll> visited(N);
    for (ll i = 0; i < N; ++i) {
        if(visited[i]) continue;
        queue<ll> q;
        q.push(i);
        color[i] = true;
        while(!q.empty()){
            ll s = q.front();
            q.pop();
            for (auto j : adj[s]) {
                if(!visited[j]){
                    q.push(j);
                    if(color[j] == -1){
                        color[j] = !color[s];
                    }
                    else if(color[j] == color[s]){
                        cout << "NEIN";
                        return 0;
                    }
                }
            }
            visited[s] = true;
        }
    }

    ll r = 0, b = 0;
    for (ll i = 0; i < N; ++i) {
        if(color[i] == 0){
            r++;
        }
        else{
            b++;
        }
    }
    cout << "JA" << "\n" << max(r, b);

    return 0;
}