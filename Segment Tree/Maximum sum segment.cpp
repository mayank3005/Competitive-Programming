struct item {
	int val;
};

struct segTree {

	int size;
	vector<item> values;

	item NEUTRAL_VALUE = {0};

	item merge(item a, item b) {
		item c; c.val = a.val + b.val; return c;
	}

	item single(int x) {
		return {x};
	}

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		values.resize(2 * size);
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if (lx == rx) {
			if (lx < (int)a.size()) values[x] = single(a[lx]);
			return;
		}
		int mid = (lx + rx) >> 1;
		build(a, 2 * x + 1, lx, mid);
		build(a, 2 * x + 2, mid + 1, rx);
		values[x] = merge(values[2 * x + 1] , values[2 * x + 2]);
	}

	void build(vector<int> &a) {
		build(a, 0, 0, size - 1);
	}

	void update(int i, int v, int x, int lx, int rx) {
		if (lx == rx) {
			values[x] = single(v);
			return;
		}
		int mid = (lx + rx) >> 1;
		if (i <= mid) update(i, v, 2 * x + 1, lx, mid);
		else update(i, v, 2 * x + 2, mid + 1, rx);
		values[x] = merge(values[2 * x + 1] , values[2 * x + 2]);
	}

	void update(int i, int v) {
		update(i, v, 0, 0, size - 1);
	}

	item query(int x, int lx, int rx, int l, int r) {
		if (lx > r or rx < l) return NEUTRAL_VALUE;
		if (lx >= l and rx <= r) return values[x];
		int mid = (lx + rx) >> 1;
		item s1 = query(2 * x + 1, lx, mid, l, r);
		item s2 = query(2 * x + 2, mid + 1, rx, l, r);
		return merge(s1, s2);
	}

	item query(int l, int r) {
		return query(0, 0, size - 1, l, r);
	}

};
