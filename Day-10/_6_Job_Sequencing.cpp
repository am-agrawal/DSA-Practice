#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int dead;
    int profit;
};

bool comp(Job a, Job b) {
    return (a.profit > b.profit);
}

pair<int, int> JobScheduling(Job arr[], int n) {
    sort(arr, arr + n, comp);
    int maxi = arr[0].dead;

    vector<int> slot(maxi + 1);
    
    for(int i = 0; i <= maxi; i++) {
        slot[i] = -1;
    }

    int countJobs = 0, jobProfit = 0;

    for(int i = 0; i < n; i++) {
        for(int j = arr[i].dead; j > 0; j--) {
            if(slot[j] == -1) {
                slot[j] = i;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }

    return make_pair(countJobs, jobProfit);
}