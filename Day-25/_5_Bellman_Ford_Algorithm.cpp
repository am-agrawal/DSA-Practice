/*

* Bellman Ford' Algorithm is also used to find the MST of a Graph
* But it has other benefits alse.
* It works on Directed Weighted Graph
* It can work with negative weights also.
* But when there is a Negative Cycle, it can detect the cycle
* So as that it can't find the MST of a Graph which contains Negative Cycle

Algorithm:-
1.  Relax All the Edges N-1 times
    [ if(dist[u] + weight < dist[v]) then dist[v] = dist[u] + weight ]

2.  Relax All the Edges one more time
    If the condition is found to be true at any point, then it means Graph contains Negative Cycle
    But if the condition got false at every point, it means the Final dist[] Array is our result
    And Graph doesn't contain Negative Cycle.

* Time => O(N - 1) * O(E)
* Space => O(N)

*/

#include <iostream>
#include <vector>

#define INF 10000000

using namespace std;

struct node {
  int u, v, wt;

  node(int _u, int _v, int _wt) {
    u = _u;
    v = _v;
    wt = _wt;
  }
};

pair<vector<int>, bool> bellmanAlgo(int N, vector<pair<int, int>> adj[]) {
  vector<node> edges;
  vector<int> dist(N, INF);

  dist[0] = 0;

  for(int i = 0; i < N; i++) {
    for(auto it : adj[i]) {
      edges.push_back(node(i, it.first, it.second));
    }
  }

  for(int i = 0; i < N-1; i++) {
    for(auto it : edges) {
      if(dist[it.u] + it.wt < dist[it.v]) {
        dist[it.v] = dist[it.u] + it.wt;
      }
    }
  }

  bool flag = false;

  for(auto it : edges) {
    if(dist[it.u] + it.wt < dist[it.v]) {
      flag = true;
      break;
    }
  }

  return make_pair(dist, flag);
}

int main() {
  vector<pair<int, int>> adj[] = {
                        {{1, 2}},
                        {{2, -1}, {3, 1}},
                        {},
                        {{2, 2}}
                      };

  pair<vector<int>, bool> dist = bellmanAlgo(4, adj);

  if(dist.second) {
    cout << "There is a Negative Cycle" << endl;
  }

  for(int i = 0; i < dist.first.size(); i++) {
    cout << "Node : " << i << " " << dist.first[i] << endl;
  }


  return 0;
}