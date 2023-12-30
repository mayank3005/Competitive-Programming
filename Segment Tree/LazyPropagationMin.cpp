struct segTree {

	vector<int> values; vector<int> lazy;
	int size;

	segTree(int n) {
		size = 1;
		while (size < n) size *= 2;
		values.resize(2 * size); lazy.resize(2 * size);
	}

	void pushdown(int lx, int rx, int x) {
		if (lx != rx) {
			lazy[2 * x + 1] += lazy[x]; lazy[2 * x + 2] += lazy[x];
		}
		values[x] += lazy[x];
		lazy[x] = 0;
	}

	int merge(int x, int y) {
		return min(x, y);
	}

	void build(int x, int lx, int rx, vector<int> &v) {
		if (lx == rx) {
			if (lx < v.size()) values[x] = v[lx];
			return;
		}
		int mid = (lx + rx) >> 1;
		build(2 * x + 1, lx, mid, v); build(2 * x + 2, mid + 1, rx, v);

		values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
	}

	void build(vector<int> &v) {
		build(0, 0, size - 1, v);
	}

	void update(int x, int lx, int rx, int l, int r, int v) {
		pushdown(lx, rx, x);
		if (l > rx or r < lx) return;
		else if (lx >= l and rx <= r) {
			lazy[x] = v; pushdown(lx, rx, x); return;
		}

		int mid = (lx + rx) >> 1;
		update(2 * x + 1, lx, mid, l, r, v); update(2 * x + 2, mid + 1, rx, l, r, v);

		values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
	}

	void update(int l, int r, int v) {
		update(0, 0, size - 1, l, r, v);
	}

	int query(int x, int lx, int rx, int l, int r) {
		pushdown(lx, rx, x);
		if (l > rx or r < lx) return 1e18;
		if (lx >= l and rx <= r) return values[x];

		int mid = (lx + rx) >> 1;
		int a = query(2 * x + 1, lx, mid, l, r);
		int b = query(2 * x + 2, mid + 1, rx, l, r);
		return merge(a, b);
	}

	int query(int l, int r) {
		return query(0, 0, size - 1, l, r);
	}

};
