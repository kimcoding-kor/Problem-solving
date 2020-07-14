#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int main() {
	FIO;
	string a, b;
	cin >> a >> b;
	a = " " + a;
	b = " " + b;

	int alen = a.size(), blen = b.size();

	int dp[45][45] = {};

	FOR(i, 1, alen - 1) FOR(j, 1, blen - 1) {
		if (a[i] == b[j])
			dp[i][j] = dp[i - 1][j - 1] + 1;
		else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	}

	stack <char> st;
	for (int i = alen - 1, j = blen - 1; dp[i][j] ;) {
		if (dp[i - 1][j] == dp[i][j]) i--;
		else if(dp[i][j - 1] == dp[i][j])j--;
		else {
			st.push(a[i]);
			i--, j--;
		}
	}

	while (st.size()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}