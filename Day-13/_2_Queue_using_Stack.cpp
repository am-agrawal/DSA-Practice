#include <iostream>
#include <stack>
using namespace std;

// Queue implementation using Two Stacks
// class Queue {
//     stack<int> st1, st2;
// public:
//     void push(int x) {
//         while(!st1.empty()) {
//             st2.push(st1.top());
//             st1.pop();
//         }
//         st1.push(x);
//         while(!st2.empty()) {
//             st1.push(st2.top());
//             st2.pop();
//         }
//     }

//     void pop() {
//         st1.pop();
//     }

//     int front() {
//         return st1.top();
//     }
// };

class Queue {
    stack<int> in, out;
public:
    void push(int x) { in.push(x); }

    void pop() {
        if(!out.empty()) out.pop();
        else {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
            out.pop();
        }
    }

    int front() {
        int res = -1;
        if(!out.empty()) res = out.top();
        else {
            while(!in.empty()) {
                out.push(in.top());
                in.pop();
            }
            res = out.top();
        }
        return res;
    }
};


int main() {
    Queue q;
    q.push(1);
    cout << q.front() << endl;
    q.push(2);
    cout << q.front() << endl;
    q.push(3);
    cout << q.front() << endl;

    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;


    return 0;
}