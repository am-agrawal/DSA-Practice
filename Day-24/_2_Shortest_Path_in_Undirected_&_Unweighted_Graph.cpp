#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int[] shortestPath(int N, vector<int> adj[], int src) {
  int dist[N];
  queue<int> q;
  memset(dist, INT_MAX, sizeof dist);

  dist[src] = 0;
  q.push(src);

  while(!q.empty()) {
    int node = q.front(); q.pop();
    int d = dist[node] + 1;

    for(auto it : adj[node]) {
      if(d < dist[it]) {
        dist[it] = d;
        q.push(it);
      }
    }

  }
  return dist;
}