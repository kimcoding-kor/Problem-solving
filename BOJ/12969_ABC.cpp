#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define vi vector <int>
using namespace std;

int main() {
	FIO;
	bool dp[30][30][30][450];
	memset(dp, 1, sizeof(dp));
	int n, k; cin >> n >> k;
	string s;
	function <bool(int, vi)> get_dp = [&](int cnt, vi abc) {
		if (abc[0] + abc[1] + abc[2] == n) {
			if (k != cnt) return false;
			cout << s << '\n';
			return true;
		}
		bool& ret = dp[abc[0]][abc[1]][abc[2]][cnt];
		if (!ret) return ret;
		FOR(i, 0, 2) {
			s += 'A' + i;
			int val = cnt;
			FOR(j, 0, i - 1) val += abc[j];
			abc[i]++;
			if (ret = get_dp(val, abc)) return true;
			s.pop_back(), abc[i]--;
		}
		return false;
	};
	if (!get_dp(0, vi(3,0))) cout << -1 << '\n';
	return 0;
}