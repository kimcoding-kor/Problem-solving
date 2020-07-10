#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int main() {
	FIO;
	int n, k;
	string s, ans;
	cin >> n >> k >> s;
	
	for (auto i : s) {
		while (k && ans.size() && ans.back() < i) {
			ans.pop_back();
			k--;
		}
		if(ans.length() < n - k) ans += i;
	}

	cout << ans << '\n';
	return 0;
}