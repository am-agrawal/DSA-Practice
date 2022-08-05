#include <iostream>
#include <vector>
#include <stack>

#define INF INT_MAX

using namespace std;

void topoSort(int node, bool vis[] stack<int> st, vector<pair<int, int>> adj[]) {
  vis[node] = true;
  for(auto it : adj[node]) {
    if(!vis[it.first]) {
      topoSort(it, vis, st, adj);
    }
  }

  st.push(node);
}

int[] shortestPath(int N, vector<pair<int, int>> adj[], int src) {
  bool vis[N];
  stack<int> st;
  int dist[N];
  memset(vis, false, sizeof(vis));
  memset(dist, INF, sizeof(dist));

  for(int i = 0; i < N; i++) {
    if(!vis[i]) {
      topoSort(i, vis, st, adj);
    }
  }

  dist[src] = 0;

  while(!st.empty()) {
    int node = st.top(); st.pop();
    int d = dist[node];

    if(d != INF) {
      for(auto it : adj[node]) {
        if(d + it.second < dist[it.first]) {
          dist[it.first] = d + it.second;
        }
      }
    }

  }

  return dist;
}