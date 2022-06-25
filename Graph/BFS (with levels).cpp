const int N = 1e5 + 7;
vector<int> graph[N];

bool vis[N];
int lvl[N];

void bfs(int src) {
	queue<int> q;
	q.push(src);
	vis[src] = 1; lvl[src] = 0;

	while (!q.empty()) {
		int cur_v = q.front();
		q.pop();
		for (auto &child : graph[cur_v]) {
			if (vis[child]) continue;
			vis[child] = 1;
			q.push(child);
			lvl[child] = lvl[cur_v] + 1;
		}
	}
}
