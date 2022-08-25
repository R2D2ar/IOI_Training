#include <bits/stdc++.h>

using namespace std;

bool changing(string input) {
    int size = input.size();
    if (size > 0 && size % 2 == 0) {
        for (int i = 1; i < size; ++i) {
            if (input[i - 1] == input[i]) return false;
        }
        return true;
    }
    return false;
}

int main() {
    int number_cases;
    cin >> number_cases;

    string cases[number_cases];
    for (int i = 0; i < number_cases; ++i) {
        cin >> cases[i];
    }

    for (int i = 0; i < number_cases; ++i) {
        int number_w = 0;
        int number_b = 0;
        for (int j = 0; j < cases[i].size(); ++j) {
            if(cases[i][j] == 'W'){
                number_w++;
            }
            else{
                number_b++;
            }
        }

        if(number_w == number_b && !changing(cases[i])){ cout << "Case #" << i + 1 << ": possible" << endl; continue;}
        cout << "Case #" << i + 1 << ": impossible" << endl;

    }
    return 0;
}