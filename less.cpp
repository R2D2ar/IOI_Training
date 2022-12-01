#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int inner = 0, outer = 1000000000;
    int k = outer/2;
    for (int i = 0; i < 42; ++i) {
        cout << "Q " << k << "\n" << flush;
        char a;
        cin >> a;
        if(a =='y'){
            outer = k;
            k = k - ((outer - inner) / 2);
        }
        else{
            inner = k;
            k = k + ((outer - inner) / 2);
        }
    }
    cout << "A " << k << "\n" << flush;
    return 0;
}
