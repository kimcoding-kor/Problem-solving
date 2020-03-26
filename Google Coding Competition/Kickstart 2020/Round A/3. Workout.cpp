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
		int n, k, ans = 0; cin >> n >> k;
		priority_queue <pair <int, pii>> pq;
		int pre; cin >> pre;
		FOR(i, 2, n) {
			int x; cin >> x;
			pq.push({ x - pre, {x - pre, 1} });
			pre = x;
		}
		FOR(i, 1, k) {
			auto now = pq.top(); pq.pop();
			now.sd.sd++;
			int x = (now.sd.fs % now.sd.sd) ? 1 : 0;
			pq.push({ now.sd.fs / now.sd.sd + x, {now.sd.fs, now.sd.sd} });
		}
		cout << "Case #" << t << ": " << pq.top().fs << '\n';
	}
	return 0;
}