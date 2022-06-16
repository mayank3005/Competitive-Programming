const int MOD = 1e3 + 7;
const int d = 256;

void RabinKarp(string &txt, string &pat) {
	int m = pat.length(), n = txt.length();

	int hashp = 0, hasht = 0; // hash values for pattern and text
	int h = 1; // used for rolling hash function
	int i, j;

	for (i = 0; i < m - 1; i++) {
		h = (h * d) % MOD;
	}

	for (i = 0; i < m; i++) {
		hashp = (hashp * d % MOD + pat[i]) % MOD;
		hasht = (hasht * d % MOD + txt[i]) % MOD;
	}

	for (i = 0; i < n - m; i++) {
		if (hashp == hasht) {
			for (j = 0; j < m; j++) {
				if (txt[i + j] != pat[j]) break;
			}
			if (j == m) cout << "pattern found at : " << i << nline;
		}
		if (i < n - m) {
			hasht = (d * (hasht - txt[i] * h) % MOD + txt[i + m]) % MOD;
			if (hasht < 0)
				hasht = hasht + MOD;
		}
	}
}
