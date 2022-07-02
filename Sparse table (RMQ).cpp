const int MAXN = 2e5;
const int K = 25; // K>=log2[n]
int table[MAXN][K + 1];
int lg[MAXN];

void buildLog(int N) {
	lg[1] = 0;
	for (int i = 2; i <= N; i++) {
		lg[i] = 1 + lg[i / 2];
	}
}

void build(vector<int> &v) {
	int N = v.size();
	for (int l = N - 1; l >= 0; l--) {
		for (int w = 0; w < 25; w++) {
			int r = l + (1 << w) - 1;
			if (r >= N) break;
			if (w == 0) table[l][0] = v[l];
			else table[l][w] = min(table[l][w - 1], table[l + (1 << (w - 1))][w - 1]);
		}
	}
}

int query(int l, int r) {
	int w = r - l + 1;
	int power = lg[w];
	return min(table[l][power], table[r - (1 << power) + 1][power]);
}
