#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCyclic(int N, vector<int> adj[]) {
  int inDeg[N];
  queue<int> q;
  memset(inDeg, 0, sizeof(inDeg));

  for(int i = 0; i < N; ++i) {
    for(auto it : adj[i]) {
      inDeg[it]++;
    }
  }

  for(int i = 0; i < N; ++i) {
    if(inDeg[i] == 0) {
      q.push(i);
    }
  }

  int cnt = 0;
  while(!q.empty()) {
    int node = q.front();
    q.pop();
    cnt++;

    for(auto it : adj[node]) {
      inDeg[it]--;
      if(inDeg[it] == 0) {
        q.push(it);
      }
    }

  }

  return (cnt == N) ? false : true;
}