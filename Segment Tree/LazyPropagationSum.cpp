const int N = 2e5 + 5;
int tree[4 * N], lazy[4 * N];

void build(int si, int sl, int sr, vector<int> &v) {
	if (sl == sr) {
		tree[si] = v[sl]; lazy[si] = 0; return;
	}
	int mid = (sl + sr) >> 1;
	build(2 * si + 1, sl, mid, v);
	build(2 * si + 2, mid + 1, sr, v);
	tree[si] = tree[2 * si + 1] + tree[2 * si + 2]; lazy[si] = 0;
}

void update(int si, int sl, int sr, int l, int r, int val) {

	if (lazy[si]) {
		int dx = lazy[si]; lazy[si] = 0;
		tree[si] += dx * (sr - sl + 1);
		if (sl != sr) {
			lazy[2 * si + 1] += dx, lazy[2 * si + 2] += dx;
		}
	}

	if (sr<l or sl>r) return ;
	if (sl >= l and sr <= r) {
		tree[si] += (sr - sl + 1) * val;
		if (sl != sr) {
			lazy[2 * si + 1] += val, lazy[2 * si + 2] += val;
		}
		return;
	}

	int mid = (sl + sr) >> 1;
	update(2 * si + 1, sl, mid, l, r, val);
	update(2 * si + 2, mid + 1, sr, l, r, val);
	tree[si] = tree[2 * si + 1] + tree[2 * si + 2];
}
