// PanicCounter_Queue.cpp
#include <iostream>
#include <cstdint>
using namespace std;

class PriorityQueue {
    public:
        int32_t n;

        PriorityQueue(int32_t i) {
            n = i;
        }

        int32_t getParent(int32_t i) {
            return((int32_t) i / 2);
        }

        int32_t getLeftChild(int32_t i) {
            if (2*i <= n)
                return 2*i;
            return -1;
        }

        int32_t getRightChild(int32_t i) {
            if (2*i + 1 <= n)
                return 2*i + 1;
            return -1;
        }
};

int main()
{
    int32_t n = 2e5;
    PriorityQueue pq(n);
    cout << pq.getParent(25) << endl;
    cout << pq.getLeftChild(1e5) << endl;
    return 0;
}
