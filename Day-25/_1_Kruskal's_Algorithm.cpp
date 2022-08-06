#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
  int wt, u, v;

  node(int _wt, int _u, int _v) {
    wt = _wt;
    u = _u;
    v = _v;
  }
};

class DisjointSet {
public:
  int Parent[100000], Rank[100000];

  DisjointSet(int N) {
    for(int i = 0; i < N; i++) {
      Parent[i] = i;
      Rank[i] = 0;
    }
  }

  int findParent(int node) {
    if(Parent[node] == node) return node;

    return Parent[node] = findParent(Parent[node]);
  }

  void Union(int u, int v) {
    u = findParent(u);
    v = findParent(v);

    if(Rank[u] < Rank[v]) {
      Parent[u] = v;
    } else if(Rank[u] > Rank[v]) {
      Parent[v] = u;
    } else {
      Parent[v] = u;
      Rank[u]++;
    }

  }

};

bool comp(node a, node b) {
  return a.wt < b.wt;
}

vector<node> mst(int N, vector<pair<int, int>> adj[]) {
  vector<node> nodes, res;
  int totWt = 0;

  for(int i = 0; i < N; i++) {
    for(auto it : adj[i]) {
      nodes.push_back(node(it.second, i, it.first));
    }
  }

  sort(nodes.begin(), nodes.end(), comp);

  DisjointSet dSet(N);

  for(auto node : nodes) {
    if(dSet.findParent(node.u) != dSet.findParent(node.v)) {
      dSet.Union(node.u, node.v);

      totWt += node.wt;

      res.push_back(node);
    }
  }

  return res;
}

int main() {
  vector<pair<int, int>> adj[] = {
                                  {{1, 4}, {2, 2}, {3, 3}, {4, 4}}, 
                                  {{0, 4}, {2, 1}}, 
                                  {{1, 1}, {0, 2}, {3, 1}}, 
                                  {{2, 1}, {0, 3}, {4, 2}}, 
                                  {{0, 4}, {3, 2}}
                                };

  vector<node> res = mst(5, adj);

  for(auto node : res) {
    cout << node.u << " --> " << node.v << "  [" << node.wt << "]" << endl;
  }


  return 0;
}