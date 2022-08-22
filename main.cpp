#include <bits/stdc++.h>

bool existing(const std::vector<std::pair<int, int>>& input, int number){
    if(!input.empty()){
        for (auto item : input) {
            if(item.first == number) return true;
        }
    }
    return false;
}

int find_first(const std::vector<std::pair<int, int>>& input, int number){
    int index = 0;
    for (auto item : input) {
        if(item.first == number) return index;
        index++;
    }
    return -1;
}

int smallest_number_friends(const std::vector<std::pair<int, int>>& input){
    int smallest = 1000000;
    for (auto item : input) {
        if (item.second < smallest) smallest = item.second;
    }
    return smallest;
}

int main() {
    int amount_users;
    std::cin >> amount_users;

    int amount_friends;
    std::cin >> amount_friends;

    int current_input = 0;
    std::vector<std::pair<int, int>> output;
    for (int i = 0; i < amount_friends * 2; ++i) {
        std::cin >> current_input;
        if(!existing(output, current_input)) {
            output.emplace_back(current_input, 1);
        }
        else{
            int index = find_first(output, current_input);
            output[index].second += 1;
        }
    }

    std::sort(output.begin(), output.end());
    int smallest = smallest_number_friends(output);
    for (auto item : output) {
        if(item.second == smallest){
            std::cout << item.first << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
