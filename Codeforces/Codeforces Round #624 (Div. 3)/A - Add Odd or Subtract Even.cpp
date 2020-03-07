#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(a,b,c) for(int a = (b); a <= (c); a++)
#define RFOR(a,b,c) for(int a = (b); a >= (c); a--)
#define all(x) (x).begin(), (x).end()
#define vi vector <int>
#define vvi vector <vi>
#define ll long long
#define vll vector <ll>
#define pii pair<int,int>
#define eb emplace_back
#define fs first
#define sd second
using namespace std;
 
int main() {
	FIO;
	int t; cin >> t; while (t--) {
		int a, b; cin >> a >> b;
		if (a == b) cout << 0 << '\n';
		else if (a < b) {
			if ((a + b) & 1) cout << 1 << '\n';
			else cout << 2 << '\n';
		}
		else {
			if ((a + b) & 1) cout << 2 << '\n';
			else cout << 1 << '\n';
		}
	}
	return 0;
}