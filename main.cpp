#include <bits/stdc++.h>

int main() {
    int amount_users;
    std::cin >> amount_users;

    int amount_friends;
    std::cin >> amount_friends;

    int current_input = 0;
    int input[amount_friends*2];
    for (int i = 0; i < amount_friends * 2; ++i) {
        std::cin >> current_input;
        input[i] = current_input;
    }

    std::sort(input, input + sizeof input / sizeof input[0]);

    int position = 0;
    int counter = 0;
    int output[amount_users];
    for(int i = 0; i < amount_friends * 2; ++i){
        counter++;
        if ((i+1 < amount_friends * 2 && input[i] != input[i+1]) || i == amount_friends * 2 - 1){
            output[position] = counter;
            counter = 0;
            position++;
        }
    }

    int smallest = 10000;
    for (int i = 0; i < amount_users; ++i) {
        if(output[i] < smallest) smallest = output[i];
    }

    for (int i = 0; i < amount_users; ++i) {
        if (output[i] == smallest){
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
