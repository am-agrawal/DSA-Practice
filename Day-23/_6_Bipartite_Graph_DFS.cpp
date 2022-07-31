#include <iostream>
#include <stack>
using namespace std;

// For Single component Graph
bool isBipartite(int V, vector<int> adj[]) {
  vector<bool> color(V, -1);
  stack<int> q;

  q.push(0);
  color[0] = 0;

  while(!q.empty()) {
    int node = q.top();
    q.pop();

    for(auto it : adj[node]) {
      if(color[it] == -1) {
        q.push(it);
        color[it] = !color[node];
      } else if(color[it] == color[node]) {
        return false;
      }
    }

  }

  return true;
}



bool bitartiteDFS(int node, vector<int> adj[], int color[]) {
  color[node] = 1;

  for(auto it : adj[node]) {
    if(color[it] == -1) {
      color[it] = 1 - color[node];
      if(!bitartiteDFS(it, adj, color)) {
        return false;
      }
    } else if(color[it] == color[node]) {
      return false;
    }
  }

  return true;
}

// For Multi-Component Graph
bool isBipartite(vector<int> adj[], int n) {
  int color[n];
  memset(color, -1, sizeof color);

  for(int i = 0; i < n; i++) {
    if(color[i] == -1) {
      if(!bitartiteDFS(i, adj, color)) {
        return false;
      }
    }
  }

  return true;
}