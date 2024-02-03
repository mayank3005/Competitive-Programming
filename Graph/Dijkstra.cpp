/*
  Single source shortest path algorithm
  Time complexity : 0(Vlogv + ElogV)
  Space complexity : 0(V+V)

*/
vector<int> dijkstra(vector<pair<int, int>> adj[], int n, int st) {
	vector<int> dist(n, 1e8);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[st] = 0;
	pq.push({0, st});
	while (!pq.empty()) {
		int src = pq.top().second, d = pq.top().first;
		pq.pop();
		if (dist[src] != d) continue;
		for (auto &[dest, wt] : adj[src]) {
			if (dist[src] + wt < dist[dest]) {
				dist[dest] = dist[src] + wt;
				pq.push({dist[dest], dest});
			}
		}
	}
	return dist;
}
