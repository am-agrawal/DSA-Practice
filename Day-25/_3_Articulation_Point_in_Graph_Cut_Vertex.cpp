#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, int parent, vector<bool>& vis, vector<int>& tIn, vector<int>& low, int& timer, vector<int> adj[], vector<int>& res) {
  vis[node] = true;
  tIn[node] = low[node] = timer++;

  for(auto it : adj[node]) {
    if(it == parent) continue;

    if(!vis[it]) {
      dfs(it, node, vis, tIn, low, timer, adj, res);

      low[node] = min(low[node], low[it]);

      if(low[it] >= tIn[node] && parent != -1) {
        res.push_back(node);
      }

    } else {
      low[node] = min(low[node], tIn[it]);
    }
  }
}

vector<int> articPoints(int N, vector<int> adj[]) {
  vector<bool> vis(N, false);
  vector<int> tIn(N, -1), low(N, -1);

  vector<int> res;

  int timer = 0;

  for(int i = 0; i < N; ++i) {
    if(!vis[i]) {
      dfs(i, -1, vis, tIn, low, timer, adj, res);
    }
  }

  return res;
}

int main() {
  vector<int> adj[] = {
                        {1, 2}, 
                        {0, 3}, 
                        {0, 3}, 
                        {1, 2, 4}, 
                        {3, 5, 6},
                        {4, 7},
                        {4, 7},
                        {5, 6}
                      };

  vector<int> res = articPoints(8, adj);

  for(auto it : res) {
    cout << it << endl;
  }


  return 0;
}