// PanicCounter_Stack.cpp
#include <fstream>
#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

int32_t n, q;
vector<int64_t> arr = {(int64_t) 9e18};

class MyStack {
    vector<int32_t> A;

    int32_t binarySearchInsertPosition(int32_t a, int32_t b, int32_t index) {
        // Initial boundary check
        if (index <= A[a] || index >= A[b]) {
            return -10;
        }

        // Main binary search loop
        while (b - a > 1) {  // We want b - a == 1 at the end
            int32_t mid = a + (b - a) / 2;

            // Check if current mid violates the condition
            if (index <= A[mid] || index >= A[b]) {
                return -10;
            }

            if (arr[A[mid]] < arr[index]) {
                a = mid;
            } else if (arr[A[mid]] > arr[index]) {
                b = mid;
            } else {
                // When values are equal, compare the indices
                if (A[mid] < index) {
                    a = mid;
                } else {
                    b = mid;
                }
            }

            // Check if the new boundaries violate the condition
            if (index <= A[a] || index >= A[b]) {
                return -10;
            }
        }

        // Final check before returning
        if (index <= A[a] || index >= A[b]) {
            return -10;
        }

        return a;
    }

    public:
    void push(int32_t x) {
        A.push_back(x);
    }

    void insertAfter(int32_t index, int32_t value) {
        A.insert(A.begin() + index+1, value);
    }

    int32_t panicCount() {
        return A.size();
    }

    void update(int32_t index) {
        int32_t result = binarySearchInsertPosition(0, panicCount()-1, index);
        if (result != -10) {
            insertAfter(result, index);
        }
    }

    void print() {
        for (int32_t i = 0; i < A.size(); i++) {
            cout << "arr[" << i << "]: " << A[i] << endl;
        }
    }
};

int main()
{
    // Define Stack
    MyStack stack;

    // Get n and q
    cin >> n >> q;

    // Get first element
    int32_t x, min;
    cin >> x;
    arr.push_back(x); min = x;

    // Get other elements
    for (int32_t i = 2; i <= n; i++) {
        cin >> x;
        arr.push_back(x);
        if (x < min) {
            stack.push(i);
            min = x;
        }
    }

    /*
    for (int i = 1; i <= n; i++)
        cout << arr[i] << endl;
     stack.print();
    */

    // Process Queries
    int32_t i, d;
    while (q--) {
        cin >> i >> d;
        arr[i] -= d;
        stack.update(i);
        for (int i = 1; i <= n; i++)
            cout << arr[i] << "  ";
        cout << endl;
        stack.print();
        cout << "---------------------------\n";
    }

    return 0;
}
