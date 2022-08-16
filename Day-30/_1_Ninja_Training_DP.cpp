// In this problem, we have a grid of n x 3
//          Activities
//          0   1   2
// Day-0    10  50  5
// Day-1    11  100 1
//  |       |   |   |
//  |       |   |   |
// Day-n    |   |   |

// And there we get points by doing one activity on each day
// But there is a rule that we can't do exact activity on next adjacent day
// So we have to give maximum points that we can make from activities

#include <iostream>
#include <vector>

using namespace std;

// Memoization
// Time => O(n * 4)
// Space => O(n) + O(n * 4)
// int findMax(int day, int lastAct, vector<vector<int>>& activities, vector<vector<int>> dp) {
//   if(dp[day][lastAct] != -1) return dp[day][lastAct];

//   if(day == 0) {
//     int res = INT_MIN;
//     for(int i = 0; i < 3; i++) {
//       if(i != lastAct) {
//         res = max(res, activities[0][i]);
//       }
//     }
//     return dp[day][lastAct] = res;
//   }

//   int resMax = INT_MIN;
//   for(int i = 0; i < 3; i++) {
//     if(i != lastAct) {
//       resMax = max(resMax, findMax(day-1, i, activities, dp) + activities[day][i]);
//     }
//   }

//   return dp[day][lastAct] = resMax;
// }

// Tabulation
// Time => O(n * 4)
// Space => O(n * 4)
// int findMax(vector<vector<int>>& points) {
//   int n = points.size();
//   vector<vector<int>> dp(n, vector<int>(4, -1));

//   dp[0][0] = max(points[0][1], points[0][2]);
//   dp[0][1] = max(points[0][0], points[0][2]);
//   dp[0][2] = max(points[0][0], points[0][1]);
//   dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

//   for(int day = 1; day < n; day++) {
//     for(int last = 0; last < 4; last++) {
//       int mx = INT_MIN;
//       for(int task = 0; task < 3; task++) {
//         if(task != last) {
//           mx = max(mx, points[day][task] + dp[day-1][task]);
//         }
//       }
//       dp[day][last] = mx;
//     }
//   }

//   return dp[n-1][3];
// }

// Tabulation (Space Optimized)
// Time => O(n * 4)
// Space => O(4)
int findMax(vector<vector<int>>& points) {
  int n = points.size();
  vector<int> prev(4);

  prev[0] = max(points[0][1], points[0][2]);
  prev[1] = max(points[0][0], points[0][2]);
  prev[2] = max(points[0][0], points[0][1]);
  prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

  for(int day = 1; day < n; day++) {
    vector<int> temp(4, INT_MIN);
    for(int last = 0; last < 4; last++) {
      for(int task = 0; task < 3; task++) {
        if(task != last) {
          temp[last] = max(temp[last], points[day][task] + prev[task]);
        }
      }
    }
    prev = temp;
  }

  return prev[3];
}


int main() {
  vector<vector<int>> activities = {
                                    {10, 50, 5},
                                    {11, 100, 1}
  };

  int n = activities.size();
  // vector<vector<int>> dp(n, vector<int>(4, -1));
  // cout << findMax(n-1, 3, activities, dp) << endl;
  cout << findMax(activities) << endl;

  return 0;
}