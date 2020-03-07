#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define vi vector <int>
#define vvi vector <vi>
#define ll long long
#define vll vector <ll>
#define vvl vector <vll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define eb emplace_back
#define ep emplace
#define fs first
#define sd second
using namespace std;

int main() {
	FIO;
	//int t; cin >> t; while (t--) {
		string s;
		cin >> s;
		stack <int> st;
		queue <int> q;
		vi ans;
		int len = (int)s.size();
		FOR(i, 0, len - 1) {
			if (s[i] == '(') q.ep(i);
		}
		int cnt = len;
		RFOR(i, len - 1, 0) {
			if (s[i] == ')') {
				if (q.empty()) break;
				int a = q.front(); q.pop();
				if (a > i) break;
				
				ans.eb(i);
				ans.eb(a);
				cnt -= 2;
			}
		}
		sort(all(ans));
		if ((int)ans.size()) {
			cout << 1 << '\n';
			cout << (int)ans.size() << '\n';
			for (int i : ans) cout << i + 1 << ' ';
		}
		else cout << 0 << '\n';
	//}
	return 0;
}