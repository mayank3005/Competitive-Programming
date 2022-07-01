#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// less_equal<int> --> multiset

int main() {

	pbds st;

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		st.insert(x);
	}

	for (auto i : st) cout << i << " ";
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << i << " : " << *st.find_by_order(i) << endl;
	}

	cout << "No. of elements smaller than 6 " << st.order_of_key(6) << endl;
	cout << "No. of elements smaller than 1 " << st.order_of_key(1) << endl;
	cout << "No. of elements smaller than 10 " << st.order_of_key(10) << endl;

	cout << "Lower bound of 4 : " << *st.lower_bound(4) << endl;
	cout << "Lower bound of 10 : " << *st.lower_bound(10) << endl;
	cout << "Lower bound of 11 : " << *st.lower_bound(11) << endl;


	cout << "Upper bound of 2 : " << *st.upper_bound(2) << endl;
	cout << "Upper bound of 6 : " << *st.upper_bound(6) << endl;
	cout << "Upper bound of 10 : " << *st.upper_bound(10) << endl;

	cout << (end(st) == st.upper_bound(11)) << endl;

// 	o_set.order_of_key(r+1) – o_set.order_of_key(l) : find number of elements between l and r

	return 0;
}
