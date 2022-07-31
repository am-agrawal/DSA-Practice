#include <iostream>
#include <stack>
using namespace std;

bool cycleDFS(int s, vector<int>& vis, vector<int> adj[]) {
  stack<pair<int, int>> q;

  vis[s] = 1;
  q.push({s, -1});

  while (!q.empty()) {
    int node = q.top().first;
    int par = q.top().second;
    q.pop();

    for(auto it : adj[node]) {
      if(!vis[it]) {
        vis[it] = 1;
        q.push({it, node});
      } else if(par != it) {
        return true;
      }
    }

  }

  return false;
}

bool cycleDFS2(int node, int parent, vector<int>& vis, vector<int> adj[]) {
  vis[node] = 1;
  for(auto it : adj[node]) {
    if(!vis[it]) {
      if(cycleDFS2(it, node, vis, adj)) {
        return true;
      }
    } else if(it != parent) {
      return true;
    }
  }

  return false;
}


// Start function
bool isCycle(int V, vector<int> adj[]) {
  vector<int> vis(V+1, 0);
  
  for(int i = 1; i <= V; i++) {
    if(!vis[i]) {
      if(cycleDFS(i, vis, adj)) {
        return true;
      }
    }
  }

  return false;
}