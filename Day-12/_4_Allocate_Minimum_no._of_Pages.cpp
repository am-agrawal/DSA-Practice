#include <iostream>
#include <vector>
using namespace std;

// Here, we are given an array pages that contains pages of n Books and the number of students
// And we have some rules :-
// =>   At least one book will be allocated to a Student
// =>   We can't split a book
// =>   We have to distribute the books among students in contiguous order
// Our result should be the minimum (maximum (number of pages among students))

bool isAllocationPossible(vector<int>& pages, int limit, int n) {
    // code to check if we can distribute the books among n students within the limit
    // if Yes => return true;
    // else => return false;
    int cnt = 1;
    int tempSum = 0;

    for (int i = 0; i < pages.size(); i++) {
        if(tempSum + pages[i] <= limit) {
            tempSum += pages[i];
        } else {
            tempSum = pages[i];
            cnt++;
        }
    }

    if(cnt > n) return false;

    return true;
}

int pageAllocation(vector<int>& pages, int n, int totalPages) {
    int l = 0, h = totalPages;
    while(l <= h) {
        int mid = (l + h) >> 1;

        if(isAllocationPossible(pages, mid, n)) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return l;
}

int main() {
    vector<int> pages = {12, 34, 67, 90};
    int nStudents = 2;
    int totalPages = (12 + 34 + 67 + 90);

    cout << pageAllocation(pages, nStudents, totalPages) << endl;

    return 0;
}