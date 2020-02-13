#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int,int>
#define ll long long
#define fs first
#define sd second
#define eb emplace_back
using namespace std;
 
int main() {
	FIO;
	int t; cin >> t; while (t--) {
		string s; cin >> s;
		int ans = 0;
		int cnt = 0, flag = 0;
		for (auto i : s) {
			if (i == '1') flag = 1;
			if (flag && i == '0') ans++;
		}
		for (int i = s.size() - 1; i >= 0; i--) {
			if (flag && s[i] == '0') ans--;
			if (s[i] == '1') break;
		}
		cout << ans << '\n';
	}
	return 0;
}