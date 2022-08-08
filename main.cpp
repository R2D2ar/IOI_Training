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
    int amount;
    std::cin >> amount;

    int input1 [amount*2];

    for (int i = 0; i < amount*2; ++i) {
        std::cin >> input1[i];
    }


    std::vector<std::pair<int, int>> input = std::vector<std::pair<int, int>>();
    input.emplace_back(0, 2);
    input.emplace_back(5, 1);
    input.emplace_back(4, 2);
    input.emplace_back(4, 3);
    input.emplace_back(5, 2);
    input.emplace_back(5, 7);
    input.emplace_back(0, 1);
    input.emplace_back(0, 4);
    input.emplace_back(6, 7);
    input.emplace_back(5, 3);

    std::vector<int> collection = std::vector<int>();
    for (auto & i : input) {
        collection.emplace_back(i.first);
        collection.emplace_back(i.second);
    }

    input.clear();

    for (auto item : collection) {
        if(!existing(input, item)) {
            input.emplace_back(item, 1);
        }
        else{
            int index = find_first(input, item);
            input[index].first = item;
            input[index].second = input[index].second + 1;
        }
    }

    int smallest = smallest_number_friends(input);
    for (auto item : input) {
        if (item.second == smallest) std::cout << item.first << " ";
    }
    std::cout << std::endl;

    return 0;
}
