#include <iostream>
using namespace std;

bool checkDFS(int node, int vis[], int dfsvis[], vector<int> adj[]) {
  vis[node] = 1;
  dfsvis[node] = 1;

  for(auto it : adj[node]) {
    if(!vis[it]) {
      if(checkDFS(it, vis, dfsvis, adj)) return true;
    } else if(dfsvis[it]) {
      return true;
    }
  }

  dfsvis[node] = 0;

  return false;
}

bool isCycle(int n, vector<int> adj[]) {
  int vis[n], dfsvis[n];
  memset(vis, 0, sizeof(vis));
  memset(dfsvis, 0, sizeof(dfsvis));

  for (int i = 0; i < n; i++) {
    if(!vis[i]) {
      if(checkDFS(i, vis, dfsvis, adj)) {
        return true;
      }
    }
  }

  return false;
}