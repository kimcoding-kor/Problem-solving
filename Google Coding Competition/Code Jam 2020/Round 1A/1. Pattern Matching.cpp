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
#define mod 998244353
#define EPS 1e-9
using namespace std;

int main() {
	FIO;
	int test; cin >> test;
	FOR(t, 1, test) {
		int n; cin >> n;
		string st, ed, mid;
		int flag = 0;
		while (n--) {
			string s; cin >> s;
			int si = -1, ei = s.length();
			FOR(i, 0, ei - 1) {
				if (s[i] == '*') break;
				if (st.size() < i + 1) st += s[i];
				else if (st[i] != s[i]) {
					flag = 1;
					break;
				}
				si++;
			}
			RFOR(i, s.size() - 1, si + 1) {
				if (s[i] == '*') break;
				if (ed.size() < s.size() - i) ed = s[i] + ed;
				else if (ed[ed.size() - (s.size() - i - 1) - 1] != s[i]) {
					flag = 1;
					break;
				}
				ei--;
			}
			FOR(i, si + 1, ei - 1) {
				if (s[i] != '*') mid += s[i];
			}
		}
		if(flag) cout << "Case #" << t << ": " << '*' << '\n';
		else cout << "Case #" << t << ": " << st << mid << ed << '\n';
	}
	return 0;
}