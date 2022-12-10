#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ll N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> input = vector<pair<ll, ll>>();
    int size = 0;
    for (int i = 0; i < N; ++i) {
        int a, d;
        cin >> a >> d;
        if(d > size) size = d;
        input.emplace_back(pair(a, d));
    }
    vector<ll> num_edges_outcoming = vector<ll>(size, 0);
    vector<ll> num_edges_incoming = vector<ll>(size, 0);
    for (auto item: input){
        num_edges_outcoming[--item.first]++;
        num_edges_incoming[--item.second]++;
    }
    ll used = 0;
    for (int i = 0; i < size; ++i) {
        used += num_edges_outcoming[i] - num_edges_incoming[i];
        if (used > K){
            cout << "impossible";
            return 0;
        }
    }
    cout << "possible";
    return 0;
}
