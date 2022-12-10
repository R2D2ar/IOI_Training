#include <bits/stdc++.h>

using namespace std;

int main(){
    map<int, float> noten = map<int, float>();
    noten[0] = 2.0;
    noten[1] = 1.0;
    noten[2] = 0.5;
    noten[4] = 0.25;
    noten[8] = 0.125;
    noten[16] = 0.0625;
    int N;
    cin >> N;
    float sum = 0.0;
    for (int i = 0; i < N; ++i) {
        int k;
        cin >> k;
        sum += noten[k];
    }
    cout << sum;
    return 0;
}
