// Here we have an array of integers as prices of stock on ith day
// And we have to find the maximum profit, if we can buy and sell that stock at once

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
  int mini = prices[0], profit = 0;
  int n = prices.size();
  for(int i = 1; i < n; i++) {
    profit = max(profit, prices[i] - mini);
    mini = min(mini, prices[i]);
  }

  return profit;
}

int main() {
  vector<int> prices = {7, 1, 3, 5, 4, 6, 2};

  cout << maxProfit(prices) << endl;

  return 0;
}