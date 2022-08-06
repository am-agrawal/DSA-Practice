#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<bool>& vis, stack<int>& st, vector<int> adj[]) {
  vis[node] = true;

  for(auto it : adj[node]) {
    if(!vis[it]) {
      dfs(it, vis, st, adj);
    }
  }

  st.push(node);
}

void revDFS(int node, vector<int>& ds, vector<bool>& vis, vector<int> adj[]) {
  vis[node] = true;

  for(auto it : adj[node]) {
    if(!vis[it]) {
      revDFS(it, ds, vis, adj);
    }
  }

  ds.push_back(node);
}

vector<vector<int>> strongly_connected_components(int N, vector<int> adj[]) {
  stack<int> st;
  vector<bool> vis(N, false);

  vector<vector<int>> res;

  for(int i = 0; i < N; i++) {
    if(!vis[i]) {
      dfs(i, vis, st, adj);
    }
  }

  vector<int> transpose[N];

  for(int i = 0; i < N; i++) {
    vis[i] = false;
    for(auto it : adj[i]) {
      transpose[it].push_back(i);
    }
  }

  while(!st.empty()) {
    int node = st.top();
    st.pop();

    if(!vis[node]) {
      vector<int> ds;
      revDFS(node, ds, vis, transpose);
      res.push_back(ds);
    }
  }


  return res;
}


int main() {
  vector<int> adj[] = {
                        {1},
                        {2, 3},
                        {0},
                        {4},
                        {}
                      };

  vector<vector<int>> res = strongly_connected_components(5, adj);

  for(auto it : res) {
    for(auto i : it) {
      cout << i << " ";
    }
    cout << endl;
  }


  return 0;
}