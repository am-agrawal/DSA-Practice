#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void DFS(int node, int vis[], stack<int>& st, vector<int> adj[]) {
  vis[node] = 1;

  for(auto it : adj[node]) {
    if(!vis[it]) {
      DFS(it, vis, st, adj);
    }
  }

  st.push(node);
}

vector<int> topologicalSort(int n, vector<int> adj[]) {
  int vis[n];
  memset(vis, 0, sizeof(vis));
  stack<int> st;
  vector<int> res;

  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      DFS(i, vis, st, adj);
    }
  }

  while(!st.empty()) {
    res.push_back(st.top());
    st.pop();
  }

  return res;
}