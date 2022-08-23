#include <bits/stdc++.h>

using namespace std;

bool oneChar(string input){
    for (auto i : input) {
        if(i != input[0]) return false;
    }
    return true;
}

string remove(string input){
    int size = input.size();
    if (size > 3){
        for (int i = 0; i < size-2; ++i) {
            string compare = input.substr(i, 3);
            if(compare == "WWB" || compare == "BWW"){
                input.replace(i, 3, "W");
                return input;
            }
            if(compare == "BBW" || compare == "WBB"){
                input.replace(i, 3, "B");
                return input;
            }
        }
    }
}

string convert(string input){
    if(input == "BW" || input == "WB" || oneChar(input)){
        return input;
    }
    else{
        return convert(remove(input));
    }
}

int main() {
    int number_cases;
    cin >> number_cases;

    string cases[number_cases];
    for (int i = 0; i < number_cases; ++i) {
        cin >> cases[i];
    }

    for (int i = 0; i < number_cases; ++i) {
        string output = convert(cases[i]);
        if(output == "WB" || output == "BW"){
            cout << "Case #" << i << ": possible" << endl;
        } else {
            cout << "Case #" << i << ": impossible" << endl;
        }
    }
    return 0;
}