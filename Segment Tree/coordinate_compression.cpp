#include<bits/stdc++.h>
using namespace std;

/* clang-format off */
namespace _DEBUG_UTIL_ { void print(const char *x) {} void print(bool x) { cerr << (x ? "T" : "F"); } void print(char x) { cerr << '\'' << x << '\''; } void print(signed short int x) { cerr << x; } void print(unsigned short int x) { cerr << x; } void print(signed int x) { cerr << x; } void print(unsigned int x) { cerr << x; } void print(signed long int x) { cerr << x; } void print(unsigned long int x) { cerr << x; } void print(signed long long int x) { cerr << x; } void print(unsigned long long int x) { cerr << x; } void print(float x) { cerr << x; } void print(double x) { cerr << x; } void print(long double x) { cerr << x; } void print(string x) { cerr << '\"' << x << '\"'; } template <size_t N> void print(bitset<N> x) { cerr << x; } void print(vector<bool> x) { int f = 0; cerr << '{'; for (bool i : x) { cerr << (f++ ? "," : ""); cerr << (i ? "T" : "F"); } cerr << "}"; } /* Template Datatypes Declarations */ template <typename T> void print(T x); template <typename T> void print(vector<vector<T>> mat); template <typename T, size_t N> void print(T (&arr)[N]); template <typename T, size_t N, size_t M> void print(T (&mat)[N][M]); template <typename F, typename S> void print(pair<F, S> x); template <typename T> void print(priority_queue<T> pq); template <typename T> void print(priority_queue<T, vector<T>, greater<T>> pq); template <typename T> void print(stack<T> st); template <typename T> void print(queue<T> q); /* Template Datatypes Definitions */ template <typename T> void print(T x) { int f = 0; cerr << '{'; for (auto i : x) cerr << (f++ ? "," : ""), print(i); cerr << "}"; } template <typename T> void print(vector<vector<T>> mat) { int f = 0; cerr << "{\n"; for (auto i : mat) cerr << (f++ ? ",\n" : ""), print(i); cerr << "}\n"; } template <typename T, size_t N> void print(T (&arr)[N]) { int f = 0; cerr << '{'; for (auto &i : arr) cerr << (f++ ? "," : ""), print(i); cerr << "}"; } template <typename T, size_t N, size_t M> void print(T (&mat)[N][M]) { int f = 0; cerr << "{\n"; for (auto &i : mat) cerr << (f++ ? ",\n" : ""), print(i); cerr << "}\n"; } template <typename F, typename S> void print(pair<F, S> x) { cerr << '('; print(x.first); cerr << ','; print(x.second); cerr << ')'; } template <typename T> void print(priority_queue<T> pq) { int f = 0; cerr << '{'; while (!pq.empty()) cerr << (f++ ? "," : ""), print(pq.top()), pq.pop(); cerr << "}"; } template <typename T> void print(priority_queue<T, vector<T>, greater<T>> pq) { int f = 0; cerr << '{'; while (!pq.empty()) cerr << (f++ ? "," : ""), print(pq.top()), pq.pop(); cerr << "}"; } template <typename T> void print(stack<T> st) { int f = 0; cerr << '{'; while (!st.empty()) cerr << (f++ ? "," : ""), print(st.top()), st.pop(); cerr << "}"; } template <typename T> void print(queue<T> q) { int f = 0; cerr << '{'; while (!q.empty()) cerr << (f++ ? "," : ""), print(q.front()), q.pop(); cerr << "}"; } /* Printer */ template <typename T> void printer(const char *name, T &&head) { cerr << name << " = "; print(head); cerr << "]\n"; } template <typename T, typename... V> void printer(const char *names, T &&head, V &&...tail) { int bracket = 0, i = 0; while (names[i] != ',' or bracket != 0) { if (names[i] == '(') bracket++; else if (names[i] == ')') bracket--; i++; } cerr.write(names, i) << " = "; print(head); cerr << " ||"; printer(names + i + 1, tail...); } /* PrinterArr */ template <typename T> void printerArr(const char *name, T arr[], int N) { cerr << name << " : {"; for (int i = 0; i < N; i++) { cerr << (i ? "," : ""), print(arr[i]); } cerr << "}]\n"; } }
#ifndef ONLINE_JUDGE
#define debug(...) cerr << __LINE__ << ": [", _DEBUG_UTIL_::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(arr, n) cerr << __LINE__ << ": [", _DEBUG_UTIL_::printerArr(#arr, arr, n)
#else
#define debug(x...)
#define debugArr(arr, n)
#endif
template<class A, class B> std::ostream& operator << (std::ostream &os, const std::pair<A, B> p) { os << p.first << ' ' << p.second; return os; } template<class A, class B> std::istream& operator >> (std::istream &is, std::pair<A, B> &p) { is >> p.first >> p.second; return is; } template<class A> std::ostream& operator << (std::ostream &os, const std::vector<A> vec) { int sz = vec.size(); for (int i = 0; i < sz; i++) { os << vec[i]; if (i < sz - 1) { os << ' '; } } return os; } template<class A> std::istream& operator >> (std::istream &is, std::vector<A> &vec) { int sz = vec.size(); for (int i = 0; i < sz; i++) { is >> vec[i]; } return is; }
/* clang-format on */

#define int   long long
#define pii	  pair<int,int>
#define nline '\n'

const int N = 4e5 + 5;
int arr[N]; vector<int> vals;

struct node {
	int sum;
	node(int s = 0) {
		sum = s;
	}
};

node merge(node &a, node &b) {
	return node(a.sum + b.sum);
}

node tree[4 * N];

void build(int x, int lx, int rx) {
	if (lx == rx) {
		tree[x] = node(); return;
	}
	int mid = (lx + rx) >> 1;
	build(x << 1, lx, mid); build(x << 1 | 1, mid + 1, rx);
	tree[x] = merge(tree[x << 1], tree[x << 1 | 1]);
}

void update(int x, int lx, int rx, int pos, int val) {
	if (pos<lx or pos>rx) return;
	if (lx == rx) {
		tree[x] = node(tree[x].sum + val); return;
	}
	int mid = (lx + rx) >> 1;
	update(x << 1, lx, mid, pos, val); update(x << 1 | 1, mid + 1, rx, pos, val);
	tree[x] = merge(tree[x << 1], tree[x << 1 | 1]);
}

int comp(int x) {
	int ind = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
	return ind;
}

node query(int x, int lx, int rx, int l, int r) {
	if (lx > r or rx < l) return node();
	if (lx >= l and rx <= r) return tree[x];
	int mid = (lx + rx) >> 1;
	node left = query(x << 1, lx, mid, l, r);
	node right = query(x << 1 | 1, mid + 1, rx, l, r);
	return merge(left, right);
}

void solve() {

	build(1, 0, N - 1);

	int n, q; cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; vals.push_back(arr[i]);
	}
	vector<vector<int>> rec;
	for (int i = 0; i < q; i++) {
		char t;
		int a, b;
		cin >> t >> a >> b;
		rec.push_back({t == '?', a, b});
		if (t == '!') vals.push_back(b);
	}
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());

	for (int i = 0; i < n; i++) { update(1, 0, N - 1, comp(arr[i]), 1); }

	for (auto &u : rec) {
		u[1]--;
		if (u[0] == 0) {
			update(1, 0, N - 1, comp(arr[u[1]]), -1);
			arr[u[1]] = u[2];
			update(1, 0, N - 1, comp(arr[u[1]]), 1);
		} else {
			cout << query(1, 0, N - 1, 0, comp(u[2])).sum - query(1, 0, N - 1, 0, comp(u[1])).sum << '\n';
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

	return 0;
}
