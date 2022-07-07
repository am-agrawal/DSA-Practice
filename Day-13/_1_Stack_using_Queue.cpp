#include <iostream>
#include <queue>
using namespace std;


// Sttack implementation using Two Queues
// class Stack {
//     queue<int> q1, q2;

// public:
//     void push(int x) {
//         q2.push(x);
//         while (!q1.empty()) {
//             q2.push(q1.front());
//             q1.pop();
//         }

//         swap(q1, q2);
//     }

//     void pop() {
//         q1.pop();
//     }

//     int top() {
//         return q1.front();
//     }
// };

// Stack implementation using Single Queue
class Stack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int k = q.size();
        while(--k) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        q.pop();
    }

    int top() {
        return q.front();
    }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();


    return 0;
}