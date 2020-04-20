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
#define mod ((int)1e9)
#define EPS 1e-9
using namespace std;

int main() {
	FIO;
	int test; cin >> test;
	int d[4][2] = { {0,-1}, { 0,1}, {1,0},{-1,0} };

	auto ctoi = [&](char x) {
		if (x == 'N') return 0;
		if (x == 'S') return 1;
		if (x == 'E') return 2;
		if (x == 'W') return 3;
	};

	function <pii(int&, string& s)> f = [&](int& i, string& s) {
		pii ret = { 0,0 };
		
		while(i < s.size()) {
			if (s[i] > '1' && s[i] <= '9') {
				char ch = s[i];
				pii val = f(i += 2, s);
				ret.fs = (1ll * ret.fs + 1ll * (ch - '0') * val.fs + mod) % mod;
				ret.sd = (1ll * ret.sd + 1ll * (ch - '0') * val.sd + mod) % mod;
			}
			else if (s[i] == ')') return ret;
			else {
				ret.fs = (ret.fs + d[ctoi(s[i])][0] + mod) % mod;
				ret.sd = (ret.sd + d[ctoi(s[i])][1] + mod) % mod;
			}
			++i;
		}

		return ret;
	};

	FOR(t, 1, test) {
		string s; cin >> s;
		int c = 0;
		pii ans = f(c, s);
		cout << "Case #" << t << ": " << ans.fs + 1 << ' ' << ans.sd + 1 << '\n';
	}
	return 0;
}