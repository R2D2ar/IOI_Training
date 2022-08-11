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
    std::vector<int> collection = std::vector<int>();
    for (int i = 0; i < amount_friends * 2; ++i) {
        std::cin >> current_input;
        collection.emplace_back(current_input);
    }

    std::vector<std::pair<int, int>> input = std::vector<std::pair<int, int>>();

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

    std::vector<int> output = std::vector<int>();
    for (auto item : input) {
        //smallest number of friends
        if (item.second == smallest) output.emplace_back(item.first);
    }

    //sort the output
    std::sort(output.begin(), output.end());

    for (auto item : output) {
        std::cout << item << " ";
    }

    std::cout << std::endl;

    return 0;
}
