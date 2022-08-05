#include <iostream>
#include <priority_queue>

using namespace std;

int[] mst(int N, vector<pair<int, int>> adj[], int src) {
  int parent[N], key[N];
  bool inMST[N];

  priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int> > > pq;

  for(int i = 0; i < N; ++i) {
    inMST[i] = false;
    key[i] = INT_MAX;
  }

  parent[src] = -1;
  key[src] = 0;

  pq.push(make_pair(0, src));

  for(int count = 0; count < N - 1; ++count) {
    int u = pq.top().second;
    pq.pop();

    inMST[u] = true;

    for(auto it : adj[u]) {
      int v = it.second;
      int weight = it.first;

      if(!inMST[v] && weight < key[v]) {
        parent[v] = u;
        key[v] = weight;
        
        pq.push(make_pair(key[v], v));
      }
    }
  }

  return parent;
}