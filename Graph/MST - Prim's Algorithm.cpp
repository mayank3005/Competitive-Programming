/*
  spanning tree - n nodes , n-1 edges , every node can be reached from every other node
  TC : O(V^2 + E)
  SC : O(V+V) , third V is optional (parent one)
*/
void primMST(vector<pair<int, int>> adj[], int n) {
	vector<int> parent(n, -1), mstSet(n, 0), key(n, INT_MAX);
	parent[0] = -1;
	key[0] = 0;

	for (int i = 0; i < n - 1; i++) {
		int mini = INT_MAX, u;
		for (int v = 0; v < n; v++) {
			if (!mstSet[v] and key[v] < mini)
				mini = key[v], u = v;
		}
		mstSet[u] = true;
		for (auto it : adj[u]) {
			int v = it.first, wt = it.second;
			if (!mstSet[v] and wt < key[v])
				parent[v] = u, key[v] = wt;
		}
	}
}

------------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------------
  
/*
  TC : O(ElogE) ~ O(ElogV) 
  Unlike Dijkstra’s implementation, a boolean array inMST[] is mandatory here 
  because the key values of newly inserted items can be less than the key values of extracted items. So we must not consider extracted items.
*/
  
void primMST(vector<pair<int, int>> adj[], int n) {
	vector<int> parent(n, -1), mstSet(n, 0), key(n, INT_MAX);
	parent[0] = -1;
	key[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 0});

	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		if (mstSet[u]) continue;
		mstSet[u] = true;
		for (auto &[v, wt] : adj[u]) {
			if (!mstSet[v] and key[v] > wt) {
				key[v] = wt;
				pq.pop({key[v], v});
				parent[v] = u;
			}
		}
	}
}
