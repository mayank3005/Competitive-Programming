const int N = 2e5;
int tree[4 * N]; int lazy[4 * N]; vector<int> a;

void build(int lx, int rx, int x) {
	if (lx == rx) {
		tree[x] = a[lx]; return;
	}
	int mid = (lx + rx) >> 1;
	build(lx, mid, 2 * x + 1); build(mid + 1, rx, 2 * x + 2);
	tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
}

int query(int lx, int rx, int x, int l, int r) {
	if (lazy[x]) {
		int dx = lazy[x]; lazy[x] = 0;
		tree[x] += dx * (rx - lx + 1);
		if (lx != rx)
			lazy[2 * x + 1] += dx, lazy[2 * x + 2] += dx;
	}

	if (r<lx or l>rx) return 0;
	if (lx >= l and rx <= r) return tree[x];
	int mid = (lx + rx) >> 1;
	return query(lx, mid, 2 * x + 1, l, r) + query(mid + 1, rx, 2 * x + 2, l, r);
}

void update(int lx, int rx, int x, int l, int r, int v) {
	if (lazy[x]) {
		int dx = lazy[x]; lazy[x] = 0;
		tree[x] += dx * (rx - lx + 1);
		if (lx != rx)
			lazy[2 * x + 1] += dx, lazy[2 * x + 2] += dx;
	}
	if (r<lx or l>rx) return;
	if (lx >= l and rx <= r) {
		int dx = (rx - lx + 1) * v;
		tree[x] += dx;
		if (lx != rx)
			lazy[2 * x + 1] += v, lazy[2 * x + 2] += v;
		return;
	}
	int mid = (lx + rx) >> 1;
	update(lx, mid, 2 * x + 1, l, r, v);
	update(mid + 1, rx, 2 * x + 2, l, r, v);
	tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
}
