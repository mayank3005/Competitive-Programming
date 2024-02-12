const int N = 2e5 + 2;
int arr[N];

struct node {
	int lazy_add, lazy_set, sum;
	node(int s = 0, int l = 0, int r = 0) {
		lazy_add = l, lazy_set = r, sum = s;
	}
};

node merge(node &a, node &b) {
	return node(a.sum + b.sum);
}

node tree[4 * N];

void push_down(int curr, int child) {
	if (tree[curr].lazy_set) {
		tree[child].lazy_set = tree[curr].lazy_set;
		tree[child].lazy_add = 0;
	} else {
		if (tree[child].lazy_set) {
			tree[child].lazy_set += tree[curr].lazy_add;
		} else {
			tree[child].lazy_add += tree[curr].lazy_add;
		}
	}
}

void push(int x, int lx, int rx) {
	if (tree[x].lazy_set == 0 and tree[x].lazy_add == 0) return;
	if (lx != rx) {
		push_down(x, x << 1); push_down(x, x << 1 | 1);
	}
	if (tree[x].lazy_add) {
		tree[x].sum += (rx - lx + 1) * tree[x].lazy_add;
		tree[x].lazy_add = 0;
	}
	if (tree[x].lazy_set) {
		tree[x].sum = (rx - lx + 1) * tree[x].lazy_set;
		tree[x].lazy_set = 0;
	}
}

void build(int x, int lx, int rx) {
	if (lx == rx) {
		tree[x] = node(arr[lx]);
		return;
	}
	int mid = (lx + rx) >> 1;
	build(2 * x, lx, mid); build(2 * x + 1, mid + 1, rx);
	tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
}

void update(int x, int lx, int rx, int l, int r, int val, int u_type) {
	push(x, lx, rx);
	if (l > rx or r < lx) return;
	if (lx >= l and rx <= r) {
		if (u_type == 0) {
			tree[x].lazy_set = val;
		} else {
			tree[x].lazy_add += val;
		}
		push(x, lx, rx);
		return;
	}
	int mid = (lx + rx) >> 1;
	update(2 * x, lx, mid, l, r, val, u_type); update(2 * x + 1, mid + 1, rx, l, r, val, u_type);
	tree[x] = merge(tree[2 * x], tree[2 * x + 1]);
}

node query(int x, int lx, int rx, int l, int r) {
	push(x, lx, rx);
	if (l > rx or r < lx) return node();
	if (lx >= l and rx <= r) return tree[x];
	int mid = (lx + rx) >> 1;
	node left = query(2 * x, lx, mid, l, r);
	node right = query(2 * x + 1, mid + 1, rx, l, r);
	return merge(left, right);
}
