// Finding the nth Fibonacci number using matrix exponentiation where the first two numbers are given

#include<bits/stdc++.h>

using namespace std;

#define int   long long
#define pii	  pair<int,int>
#define nline '\n'

const int mod = 1e9 + 7;

void mul(vector<vector<int>> &res, vector<vector<int>>& I) {
	vector<vector<int>> ans(2, vector<int>(2, 0));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ans[i][j] = (ans[i][j] + (res[i][k] * I[k][j]) % mod) % mod;
			}
		}
	}
	res = ans;
}

int fib(vector<int> v, int n) {
	if (n <= 1) return v[n];
	vector<vector<int>> I = {{1, 0}, {0, 1}};
	vector<vector<int>> T = {{0, 1}, {1, 1}};
	while (n) {
		if (n & 1) mul(I, T), n--;
		else mul(T, T), n /= 2;
	}
	return (v[0] * I[0][0] % mod + v[1] * I[1][0] % mod) % mod;

}

void solve() {

	int n;
	vector<int> v(2);
	cin >> v[0] >> v[1] >> n;

	cout << fib(v, n) << nline;

}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}

	return 0;
}
