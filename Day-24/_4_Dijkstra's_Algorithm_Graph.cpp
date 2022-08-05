#include <iostream>
#include <vector>
#include <priority_queue>

using namespace std;

// Graph Vertices => 0 -> N-1

// vector<pair<int, int>> => (int, int) => ToNode, Distance
int[] singleSourceShortestPath(int N, vector<pair<int, int>> adj[], int src) {
  int distTo[N];
  memset(distTo, INT_MAX, sizeof distTo);

  // pair<int, int> => Dist, Node (Dist is the distance from previous iteration)
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

  distTo[src] = 0;
  pq.push(make_pair(0, src));

  while(!pq.empty()) {
    int dist = pq.front().first;
    int prev = pq.front().second;
    pq.pop();

    for(auto it : adj[prev]) {
      int next = it.first;
      int nextDist = it.second;

      if(dist + nextDist < distTo[next]) {
        distTo[next] = dist + nextDist;
        pq.push(make_pair(distTo[next], next));
      }
    }
  }

  return distTo;
}