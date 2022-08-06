#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Using Greedy Approach
// Time => O(2*n*log(n)) + O(2n)
// Space => O(1)

int minPlatform(vector<int> arrival, vector<int> departure) {
  int platform = 1, result = 1;
  int i = 1, j = 0;
  int n = arrival.size();

  sort(arrival.begin(), arrival.end());
  sort(departure.begin(), departure.end());

  while(i < n && j < n) {
    if(arrival[i] <= departure[j]) {
      platform++;
      i++;
    } else {
      platform--;
      j++;
    }

    result = max(result, platform);
  }

  return result;
}

int main() {
  vector<int> arrival = {120, 50, 550, 200, 700, 850};
  vector<int> departure = {600, 550, 700, 500, 900, 1000};

  cout << minPlatform(arrival, departure) << endl;

  return 0;
}