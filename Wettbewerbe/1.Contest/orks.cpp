#include <bits/stdc++.h>

using namespace std;

int M, N;

int ask(pair<int, int> pos){
    cout << "1 " << pos.first << " " << pos.second << "\n" << flush;
    int i;
    cin >> i;
    return i;
}

void up(pair<int, int> pos, vector<vector<int>>& mat, vector<pair<int, int>>& mem){
    if (pos.second-1 >= 0){
        mat[pos.first][pos.second-1] = ask(pair(pos.first, pos.second-1));
        mem.emplace_back(pair(pos.first, pos.second-1));
    }
}
void down(pair<int, int> pos, vector<vector<int>>& mat, vector<pair<int, int>>& mem){
    if (pos.second+1 < N){
        mat[pos.first][pos.second+1] = ask(pair(pos.first, pos.second+1));
        mem.emplace_back(pair(pos.first, pos.second+1));
    }
}
void left(pair<int, int> pos, vector<vector<int>>& mat, vector<pair<int, int>>& mem){
    if (pos.first-1 >= 0){
        mat[pos.first-1][pos.second] = ask(pair(pos.first-1, pos.second));
        mem.emplace_back(pair(pos.first-1, pos.second));
    }
}
void right(pair<int, int> pos, vector<vector<int>>& mat, vector<pair<int, int>>& mem){
    if (pos.first+1 < M){
        mat[pos.first+1][pos.second] = ask(pair(pos.first+1, pos.second));
        mem.emplace_back(pair(pos.first+1, pos.second));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<pair<int, int>> memory = vector<pair<int, int>>();

    cin >> M >> N;
    vector<vector<int>> mat(M, vector<int> (N, -1));
    //Start
    int m1, n1;
    cin >> m1 >> n1;
    int c1 = --m1, c2 = --n1;

    //Schritt 1 nach oben
    while (mat[c1][c2-1] != 0 && c2-1 >= 0){
        up(pair(c1, c2-1), mat, memory);
        c2--;
    }
    while ((c1+1 < M && mat[c1+1][c2] != 0) || (c2-1 >=0 && mat[c1][c2-1] != 0)){
        if(c1+1 < M){
            right(pair(c1+1, c2), mat, memory);
            c1++;
        }
        if(c2-1 >= 0){
            up(pair(c1, c2-1), mat, memory);
            c2--;
        }
    }




    return 0;
}