#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

// Here in this problem, we have to find out the triplets
// Triplet => (a[i], a[j], a[k]) where i != j != k
// Triplets should be unique in our answer, for that we can sort a triplet then add it to the set

// Time => Time - O(n*n*log(m)) & Space - O(n) + O(m)

// vector<vector<int>> threeSum(vector<int> nums) {
//     vector<vector<int>> ans;
//     map<int, int> mp;
//     set<vector<int>> st;

//     for(int i = 0; i < nums.size(); i++) {
//         mp[nums[i]]++;
//     }

//     for(int i = 0; i < nums.size(); i++) {
//         mp[nums[i]]--;
//         for(int j = i+1; j < nums.size(); j++) {
//             mp[nums[j]]--;

//             if(mp[-(nums[i] + nums[j])] > 0) {
//                 vector<int> t = {nums[i], nums[j], -(nums[i] + nums[j])};
//                 sort(t.begin(), t.end());
//                 st.insert(t);
//             }

//             mp[nums[j]]++;
//         }
//         mp[nums[i]]++;
//     }

//     for(auto it : st) {
//         ans.push_back(it);
//     }

//     return ans;
// }

// Approach 2 => Using 2-Pointer method
// Time => O(n*n) & Space => O(1)
vector<vector<int>> threeSum(vector<int> nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size()-2; i++) {
        if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
            int lo = i+1, hi = nums.size()-1, sum = 0 - nums[i];

            while(lo < hi) {
                if(nums[lo] + nums[hi] == sum) {
                    ans.push_back({nums[i], nums[lo], nums[hi]});

                    while(lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    while(lo < hi && nums[hi] == nums[hi - 1]) hi--;

                    lo++; hi--;
                }
                
                else if(nums[lo] + nums[hi] < sum) lo++;

                else hi--;
            }

        }
    }


    return ans;
}

int main() {
    vector<vector<int>> ans = threeSum({-1, 0, 1, 2, -1, -4});

    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}