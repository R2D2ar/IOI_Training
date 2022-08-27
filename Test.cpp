#include <bits/stdc++.h>
#include <stdint-gcc.h>
#include <xmath.h>

typedef long long ll;

typedef std::vector<int> v;

using namespace std;

const int N = 5;

vector<int> adjacent(vector<pair<int, int>> adj, int num){
    vector<int> output;
    for (auto item : adj) {
        if(item.first == num) output.emplace_back(item.second);
    }
    return output;
}

int main(){
    //Important functions
    //freopen("C:\\Users\\R2D2\\CLionProjects\\IOI_Training\\test.txt", "r", stdin);
    //freopen("C:\\Users\\R2D2\\CLionProjects\\IOI_Training\\test.txt", "w", stdout);

    int a = 123456789;

    ll b = (ll)a*a;
    cout << b << "\n";

    v numbers = {1, 3, 5, 7, 9};

    //Fibonacci Binet's Formula
    int n = 60;
    double sum1 = (pow(1+ sqrt(5), n)-pow(1- sqrt(5), n))/(pow(2, n) * sqrt(5));

    printf("%f\n", sum1);

    double num[] = {5, 4, 3, 2, 1, 0, 0};

    double* pointer = num;
    cout << *pointer << "\n";
    num[0] = 6;
    cout << *pointer << "\n";

    vector<pair<int, int>> adj;
    adj.emplace_back(0, 1);
    adj.emplace_back(0, 2);
    adj.emplace_back(2, 4);
    adj.emplace_back(1, 3);
    adj.emplace_back(3, 4);

    sort(adj.begin(), adj.end());

    queue<int> q;
    bool visited[N]{0};
    int distance[N];

    int x = 0;

    visited[x] = true;
    distance[x] = 0;
    q.push(x);
    while (!q.empty()) {
        int s = q.front(); q.pop();
// process node s
        for (auto u : adjacent(adj, s)) {
            if (visited[u]) continue;
            cout << u << "\n";
            visited[u] = true;
            q.push(u);
        }
    }


    return 0;
}