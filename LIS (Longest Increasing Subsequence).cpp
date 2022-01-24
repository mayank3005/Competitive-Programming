int lis(vector<int> const& v) {
	int n = v.size();
	const int INF = 1e9;
	vector<int> d(n + 1, INF);
	d[0] = -INF;

	for (int i = 0; i < n; i++) {
		int j = upper_bound(d.begin(), d.end(), v[i]) - d.begin();
		if (d[j - 1] < v[i] && v[i] < d[j])
			d[j] = v[i];
	}

	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (d[i] < INF)
			ans = i;
	}
	return ans;
}

// --------------------------------------------------------------------------------------------------------

// Returning the subsequence itself

vector<int> lis(vector<int> const& v) {
	int n = v.size();
	const int INF = 1e9;
	vector<int> d(n + 1, INF), ind(n + 1, 0), p(n, -1);
	d[0] = -INF;

	for (int i = 0; i < n; i++) {
		int j = upper_bound(d.begin(), d.end(), v[i]) - d.begin();
		if (d[j - 1] < v[i] && v[i] < d[j]) {
			d[j] = v[i]; ind[j] = i; p[i] = ind[j - 1];
			if (j == 1) p[i] = -1;
		}
	}

	int pos = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] == INF) {
			pos = i; break;
		}
	}

	vector<int> subseq;
	while (pos != -1) {
		subseq.push_back(v[pos]);
		pos = p[pos];
	}
	reverse(subseq.begin(), subseq.end());

	return subseq;
}
