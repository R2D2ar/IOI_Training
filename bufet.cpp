#include <bits/stdc++.h>

using namespace std;

int main(){
    int speisen_num;
    cin >> speisen_num;
    int portionen_num;
    cin >> portionen_num;
    vector<pair<double, int>> sp(speisen_num);
    for (int i = 0; i < speisen_num; ++i) {
        string name;
        int anzahl;
        double noms;
        cin >> name >> anzahl >> noms;
        sp[i] = {noms, anzahl};
    }
    sort(sp.begin(), sp.end());
    double total = 0;
    for(int i = speisen_num-1; i >= 0; i--){
        double noms = sp[i].first;
        double amount = sp[i].second;
        if (portionen_num >= sp[i].second){
            total += noms * amount;
            portionen_num -= amount;
        } else {
            total += noms * portionen_num;
            break;
        }
    }

    cout << fixed << setprecision(10) << total << endl;

    return 0;
}