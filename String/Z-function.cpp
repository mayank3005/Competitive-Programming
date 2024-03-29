vector<int> z_function(string &s) {
	int n = s.length();
	vector<int> z(n, 0);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n and s[i + z[i]] == s[z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = z[i] + i - 1;
	}
	return z;
}
