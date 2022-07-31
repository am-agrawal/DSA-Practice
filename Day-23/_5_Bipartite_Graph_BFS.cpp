#include <iostream>
#include <queue>
using namespace std;

// We can implement this code for multi-component Graph
// But, for now this will work fine for single component Graph
bool isBipartite(int V, vector<int> adj[]) {
  vector<bool> color(V, -1);
  queue<int> q;

  q.push(0);
  color[0] = 0;

  while(!q.empty()) {
    int node = q.front();
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