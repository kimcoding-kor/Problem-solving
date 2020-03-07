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
	int a, b; cin >> a >> b;
	FOR(i, 1, 10000) {
		int x = (int)(i * 0.08);
		int y = (int)(i * 0.1);
		if (x == a && y == b) return cout << i << '\n', 0;
	}
	cout << -1 << '\n';
	return 0;
}
