#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, a, b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int test; cin >> test;
	FOR(t, 1, test) {
		string s, ans;
		cin >> s;
		stack <int> st;
		for (auto i : s) {
			int x = i - '0';
			while (st.size() > x) st.pop(), ans += ')';
			while (st.size() < x) st.emplace(x), ans += '(';
			ans += i;
		}
		while (st.size()) st.pop(), ans += ')';
		cout << "Case #" << t << ": " << ans << '\n';
	}
	return 0;
}