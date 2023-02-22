const int N = 2e5 + 5;
vector<int> adj[N];
int up[N][20]; // (2^19 > 5 * 10^5)
int lvl[N];

void dfs(int src, int par, int level) {
	lvl[src] = level;
	for (auto child : adj[src]) {
		if (child != par) dfs(child, src, level + 1);
	}
}

void binary_lifting(int src, int par) {
	up[src][0] = par;
	for (int i = 1; i < 20; i++) {
		if (up[src][i - 1] != -1)
			up[src][i] = up[up[src][i - 1]][i - 1];
		else up[src][i] = -1;
	}
	for (int child : adj[src]) {
		if (child != par) binary_lifting(child, src);
	}
}

int findPar(int node, int jumps) {
	if (node == -1 || jumps == 0) return node;
	for (int i = 19; i >= 0; i--) {
		if (jumps >= (1 << i)) return findPar(up[node][i], jumps ^ (1 << i));
	}
}

int lca(int u, int v) {
	if (lvl[u] < lvl[v]) swap(u, v);
	u = findPar(u, lvl[u] - lvl[v]);
	if (u == v) return u;

	for (int i = 19; i >= 0; i--) {
		if (up[u][i] != up[v][i])
			u = up[u][i], v = up[v][i];
	}

	return findPar(u, 1);

}
