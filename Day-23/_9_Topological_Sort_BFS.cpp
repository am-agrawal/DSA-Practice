#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int[] topologicalSort(int n, vector<int> adj[]) {
  int ans[n], inDeg[n];
  queue<int> q;

  for(int i = 0; i < n; i++) {
    for(auto it : adj[i]) {
      inDeg[it]++;
    }
  }

  for(int i = 0; i < n; i++) {
    if(inDeg[i] == 0) {
      q.push(i);
    }
  }

  int idx = 0;
  while(!q.empty()) {
    int node = q.front();
    ans[idx++] = node;
    q.pop();

    for(auto it : adj[node]) {
      inDeg[it]--;
      if(inDeg[it] == 0) {
        q.push(it);
      }
    }
  }

  return ans;
}