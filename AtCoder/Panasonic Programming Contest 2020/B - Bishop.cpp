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
using namespace std;

int main() {
	FIO;
	ll a, b;
	cin >> a >> b;
	if (min(a, b) == 1) return cout << 1 << '\n', 0;
	ll ans = 0;
	ans += (a / 2) * b;
	if (a & 1) ans += (b + 1) / 2;
	cout << ans << '\n';
	return 0;
}
