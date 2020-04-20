#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(ll a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(ll a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define vi vector <ll>
#define vvi vector <vi>
#define ll long long
#define vll vector <ll>
#define vvl vector <vll>
#define db double
#define vd vector <db>
#define vvd vector <vd>
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define eb emplace_back
#define ep emplace
#define fs first
#define sd second
#define mod ((ll)1e9)
#define EPS 1e-9
using namespace std;

int main() {
	FIO;
	ll test; cin >> test;

	FOR(t, 1, test) {
		string ans;
		ll x, y; cin >> x >> y;
		ll xx[50] = {}, yy[50] = {}, flag = 1;
		ll xxx = 0, yyy = 0;
		if (x < 0) x = -x, xxx = 1;
		if (y < 0) y = -y, yyy = 1;
		if ((x & 1) == (y & 1)) flag = 0;
		else {
			if (x & 1) xx[0] = 1;
			else yy[0] = 1;
			FOR(i, 1, 31){
				if ((1ll << i) > x && (1ll << i) > y)
					break;
				if ((1ll << i) & ~x && (1ll << i) & ~y) {
					if ((1ll << i - 1) & x) {
						xx[i - 1] = -1;
						xx[i] = 1;
						x |= 1ll << i;
					}
					else if ((1ll << i - 1) & y) {
						yy[i - 1] = -1;
						yy[i] = 1;
						y |= 1ll << i;
					}
					else {
						flag = 0;
						break;
					}
				}
				else if ((1ll << i) & x && (1ll << i) & y) {
					if ((1ll << i - 1) & x) {
						xx[i - 1] = -1;
						xx[i] = 0;
						yy[i] = 1;
						x += 1ll << i + 1;
						x ^= 1ll << i;
					}
					else if ((1ll << i - 1) & y) {
						yy[i - 1] = -1;
						yy[i] = 0;
						xx[i] = 1;
						y += 1ll << i + 1;
						y ^= 1ll << i;
					}
				}
				else {
					xx[i] = ((1ll << i) & x) > 0;
					yy[i] = ((1ll << i) & y) > 0;
				}
			}
		}
		cout << "Case #" << t << ": ";
		if (!flag) cout << "IMPOSSIBLE";
		else {
			FOR(i, 0, 40) {
				if (!xx[i] && !yy[i]) break;
				if (!xx[i]) {
					if(!yyy) cout << (yy[i] == 1  ? 'N' : 'S');
					else cout << (yy[i] == 1 ? 'S' : 'N');
				}
				else {
					if(!xxx) cout << (xx[i] == 1 ? 'E' : 'W');
					else cout << (xx[i] == 1 ? 'W' : 'E');
				}
			}
		}
		cout << '\n';
	}
	return 0;
}