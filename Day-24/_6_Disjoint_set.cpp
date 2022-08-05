#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> Parent(100000), Rank(100000, 0);

void makeSet(int N) {
  for (int i = 0; i < N; i++) {
    Parent[i] = i;
  }
}

int findParent(int node) {
  if(node == Parent[node]) return node;

  return Parent[node] = findParent(Parent[node]);
}

void Union(int u, int v) {
  u = findParent(u);
  v = findParent(v);

  if(Rank[u] < Rank[v]) {
    Parent[u] = v;
  }
  else if(Rank[u] > Rank[v]) {
    Parent[v] = u;
  }
  else {
    Parent[v] = u;
    Rank[u]++;
  }
}

int main() {
  int N;
  int u, v;
  int node;
  cin >> N;

  makeSet(N);

  // Here we can perform Union of Components
  // And can also find Parent of a node

  while(true) {
    cout << "Enter choice :-" << endl;
    cout << "1. Union" << endl;
    cout << "2. Find Parent" << endl;
    cout << "Otherwise exit" << endl;

    int ch;
    cin >> ch;
    
    switch (ch) {
      case 1:
        cout << "Enter U & V" << endl;
        cin >> u >> v;

        Union(u, v);

        cout << endl << endl;

        break;
      

      case 2:
        cout << "Enter node" << endl;
        cin >> node;

        cout << "Parent of " << node << " is " << findParent(node) << endl;

        cout << endl << endl;

        break;
    

      default: exit(0);
    }
  }

  return 0;
}