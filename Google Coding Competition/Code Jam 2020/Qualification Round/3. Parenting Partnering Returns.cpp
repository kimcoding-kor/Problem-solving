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
#define pic pair<int,char>
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
		string ans;
		int n; cin >> n;
		vector <pair<pii, int>> v, vv;
		FOR(i, 0, n - 1) {
			int a, b; cin >> a >> b;
			v.push_back({ { a,b }, i });
		}
		sort(all(v));
		ans.resize(n);

		priority_queue <pic, vector <pic>, greater <pic>> pq;

		FOR(i, 0, n - 1) {
			while (pq.size() && pq.top().fs <= v[i].fs.fs) pq.pop();
			char ch;
			if ((int)pq.size() == 0) ch = 'C';
			else if ((int)pq.size() == 1) {
				if (pq.top().sd == 'J')
					ch = 'C';
				else ch = 'J';
			}
			else {
				ans = "IMPOSSIBLE";
				break;
			}
			pq.ep(v[i].fs.sd, ch);
			ans[v[i].sd] = ch;
		}

		cout << "Case #" << t << ": " << ans << '\n';
	}
	return 0;
}