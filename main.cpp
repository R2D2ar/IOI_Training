#include <bits/stdc++.h>

int amount_users;

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
    std::cin >> amount_users;

    int amount_friends;
    std::cin >> amount_friends;

    int current_input = 0;
    int collection[amount_friends * 2];
    for (int i = 0; i < amount_friends * 2; ++i) {
        std::cin >> current_input;
        collection[i] = current_input;
    }

    std::vector<std::pair<int, int>> input;

    for (auto item : collection) {
        if(!existing(input, item)) {
            input.emplace_back(item, 1);
        }
        else{
            int index = find_first(input, item);
            input[index].second += 1;
        }
    }
    std::sort(input.begin(), input.end());
    int smallest = smallest_number_friends(input);
    for (auto item : input) {
        if(item.second == smallest){
            std::cout << item.first << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
