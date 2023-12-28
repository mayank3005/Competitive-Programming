//  ----> Merge Sort trees are used when each node is required to have info about the underlying child elements   <--------
// Find the elements in a given range greater than a value k

struct segTree {

	int size;
	vector<vector<int>> values;

	vector<int> merge(vector<int>& a, vector<int>& b) {
		vector<int>c;
		int n1 = a.size(), n2 = b.size();
		int i = 0, j = 0;
		while (i < n1 and j < n2) {
			if (a[i] <= b[j]) c.push_back(a[i++]);
			else c.push_back(b[j++]);
		}
		while (i < n1) c.push_back(a[i++]);
		while (j < n2) c.push_back(b[j++]);
		return c;
	}

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		values.resize(2 * size);
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if (lx == rx) {
			values[x] = {a[lx]};
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
			values[x] = {v};
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

	int query(int x, int lx, int rx, int l, int r, int k) {
		if (lx > r or rx < l) return 0;
		if (lx >= l and rx <= r) {
			int ind = upper_bound(values[x].begin(), values[x].end(), k) - values[x].begin();
			return values[x].size() - ind;
		}
		int mid = (lx + rx) >> 1;
		return query(2 * x + 1, lx, mid, l, r, k) + query(2 * x + 2, mid + 1, rx, l, r, k);
	}

	int query(int l, int r, int k) {
		return query(0, 0, size - 1, l, r, k);
	}

};
