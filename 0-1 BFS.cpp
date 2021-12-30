const int N = 1e5 + 7;
const int INF = 1e8;
vector<pair<int, int>> graph[N];

vector<int> lvl(N, INF);

void bfs(int src) {
	deque<int> q;
	q.push_back(src);
	lvl[src] = 0;

	while (!q.empty()) {
		int cur_v = q.front();
		q.pop_front();
		for (auto &child : graph[cur_v]) {
			int child_v = child.first, wt = child.second;
			// Node can be processed max. twice
			if (lvl[cur_v] + wt < lvl[child_v]) {
				lvl[child_v] = lvl[cur_v] + wt;
				if (wt == 1) q.push_back(child_v);
				else q.push_front(child_v);
			}
		}
	}
}
