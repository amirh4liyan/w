// PanicCounter.cpp
#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int32_t n, q;
vector<int64_t> S = {0};
vector<int64_t> M = {0};

void update(int i)
{
    int64_t key = S[i];
    while(key < M[i] && key <= n) {
        M[i++] = key;
    }
}

int32_t iterate()
{
    int32_t counter = 0;
    for (int i = 2; i < S.size(); i++) {
        int64_t min = M[i-1];
        if (S[i] < min) {
            counter++;
            min = S[i];
        }
    }
    return counter;
}

int main()
{
    // get n and q
    cin >> n >> q;

    // get initial price
    int64_t min = 1e9;
    for (int i = 1; i <= n; i++) {
        int64_t x;
        cin >> x;
        if (x < min)
            min = x;
        S.push_back(x);
        M.push_back(min);
    }

    // get & process query
    while(q--) {
        int i, d;
        cin >> i >> d;
        S[i] -= d;
        update(i);
        cout << iterate() << endl;
    }

    return 0;
}
