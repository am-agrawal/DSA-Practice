#include <iostream>
#include <vector>

using namespace std;

int minCoins(int X, vector<int>& coins) {
  vector<int> coinsNeeded;

  for(int i = coins.size() - 1; i >= 0; i--) {
    while(X >= coins[i]) {
      X -= coins[i];
      coinsNeeded.push_back(coins[i]);
    }
  }

  return coinsNeeded.size();
}

int main() {
  vector<int> coinsAvailable = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int X = 87;

  int minCoinReq = minCoins(X, coinsAvailable);
  cout << minCoinReq << endl;

  return 0;
}