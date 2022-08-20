#include<bits/stdc++.h>

using namespace std;

struct item {
	long long seg, pref, suff, sum;
};

struct segTree {

	int size;
	vector<item> values;

	item NEUTRAL_VALUE = {0, 0, 0, 0};

	item merge(item a, item b) {
		item c;
		c.seg = max({a.seg, b.seg, a.suff + b.pref});
		c.pref = max(a.pref, a.sum + b.pref);
		c.suff = max(b.suff, b.sum + a.suff);
		c.sum = a.sum + b.sum;
		return c;
	}

	item single(int x) {
		if (x <= 0) return {0, 0, 0, x};
		return {x, x, x, x};
	}

	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		values.resize(2 * size);
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if (lx == rx) {
			if (lx < a.size()) values[x] = single(a[lx]);
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

	void set(int i, int v, int x, int lx, int rx) {
		if (lx == rx) {
			values[x] = single(v);
			return;
		}
		int mid = (lx + rx) >> 1;
		if (i <= mid) set(i, v, 2 * x + 1, lx, mid);
		else set(i, v, 2 * x + 2, mid + 1, rx);
		values[x] = merge(values[2 * x + 1] , values[2 * x + 2]);
	}

	void set(int i, int v) {
		set(i, v, 0, 0, size - 1);
	}

	item calc(int x, int lx, int rx, int l, int r) {
		if (lx > r or rx < l) return NEUTRAL_VALUE;
		if (lx >= l and rx <= r) return values[x];
		int mid = (lx + rx) >> 1;
		item s1 = calc(2 * x + 1, lx, mid, l, r);
		item s2 = calc(2 * x + 2, mid + 1, rx, l, r);
		return merge(s1, s2);
	}

	item calc(int l, int r) {
		return calc(0, 0, size - 1, l, r);
	}

};

int main() {

	int n, m; cin >> n >> m;

	segTree st;
	st.init(n);

	vector<int> a(n);
	for (int &i : a) cin >> i;

	st.build(a);

	item ans = st.calc(0, n - 1);
	cout << max(0LL, ans.seg) << endl;

	while (m--) {
		int i, v; cin >> i >> v;
		st.set(i, v);
		item ans = st.calc(0, n - 1);
		cout << max(ans.seg, 0LL) << endl;
	}

	return 0;
}
