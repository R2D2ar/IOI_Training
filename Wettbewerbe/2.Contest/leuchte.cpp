#include <bits/stdc++.h>

using namespace std;


bool checkLights(int N, vector<int>& is_light, vector<int>& position){
    bool changed = false;
    cout << "Q";
    for (int i = 0; i < N; ++i) {
        cout << " " << position[i]+1;
    }
    cout << "\n" << flush;
    for (int i = 0; i < N; ++i) {
        int save = is_light[i];
        cin >> is_light[i];
        if(save != is_light[i]) changed = true;
    }
    if(!changed) return false;

    //Change order
    vector<pair<int, int>> need_to_change_indices = vector<pair<int, int>>();
    for (int i = 0; i < N; ++i) {
        int value = position[i];
        if(is_light[i] != 1){
            need_to_change_indices.emplace_back(i, value);
        }
    }
    int size = need_to_change_indices.size();
    if(size > 1){
        for (int i = 0; i < size; i++) {
            if(i + 1 == size){
                position[need_to_change_indices[0].first] = need_to_change_indices[i].second;
                break;
            }
            position[need_to_change_indices[i + 1].first] = need_to_change_indices[i].second;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> is_light(N, -1);
    vector<int> position = vector<int>(N);
    for (int i = 0; i < N; i++) {
        position[i] = i;
    }
    bool changed = true;
    while(changed){
        changed = checkLights(N, is_light, position);
    }
    cout << "A";
    for (int i = 0; i < N; ++i) {
        cout << " " << position[i]+1;
    }
    cout << "\n" << flush;
    return 0;
}
