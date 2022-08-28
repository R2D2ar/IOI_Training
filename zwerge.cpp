#include <bits/stdc++.h>

using namespace std;

int main() {

    int rows;
    cin >> rows;

    string zwerg1;
    char op;
    string zwerg2;

    vector<string> order = vector<string>();
    for (int i = 0; i < rows; ++i) {
        cin >> zwerg1 >> op >> zwerg2;
        if (op != '<') swap(zwerg1, zwerg2);
        auto it1 = find(order.begin(), order.end(), zwerg1);
        auto it2 = find(order.begin(), order.end(), zwerg2);
        if(it1 != order.end() && it2 != order.end()){
            if (it1 > it2) {
                cout << "impossible";
                return 0;
            }
        }
        else if (it1 == order.end() && it2 == order.end()) {
            order.insert(order.begin(), zwerg1);
            order.insert(order.begin() + 1, zwerg2);
        } else if (it1 != order.end()) {
            //Wenn einer der beiden nicht enthalten ist
            order.insert(it1 + 1, zwerg2);
        } else if (it2 != order.end()) {
            //Wenn einer der beiden nicht enthalten ist
            order.insert(it2, zwerg1);
        }
    }

    cout << "possible";


    return 0;
}