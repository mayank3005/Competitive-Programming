	stack<int> st;
	vector<int> nge(n, -1);

	for (int i = n - 1; i >= 0; i--) {
		if (st.empty()) {
			st.push(v[i]); continue;
		}
		while (!st.empty() and v[i] > st.top()) {
			st.pop();
		}
		if (!st.empty()) nge[i] = st.top();
		st.push(v[i]);
	}
