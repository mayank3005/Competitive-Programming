/*
  Single source shortest path algorithm
  TC : O((V-1)*E)
  SC : O(V)
*/
void bellmanFord(vector<pair<int, int>> adj[], int n, int st) {
	vector<int> dist(n, 1e8);
	dist[st] = 0;
	for (int i = 0; i < n - 1; i++) {
		// Relaxing every edge
		for (int src = 0; src < n; src++) {
			for (auto &[dest, wt] : adj[src]) {
				if (dist[src] + wt < dist[dest])
					dist[dest] = dist[src] + wt;
			}
		}
	}
	// Relaxing the edges one more time
	for (int src = 0; src < n; src++) {
		for (auto &[dest, wt] : adj[src]) {
			if (dist[src] + wt < dist[dest]) {
				cout << "Negative cycle detected" << endl;
				return;
			}
		}
	}
	for (auto i : dist) cout << i << " ";
}
