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
	//FIO;
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		int arr[50005] = {}, x[50005], f = 0;
		FOR(i, 1, n) {
			scanf("%1d", &x[i]);
			if (!f && x[i] == 1) {
				f = 1;
				arr[i] = 1;
			}
			else if(!f) arr[i] = x[i] / 2;
		}
		FOR(i, 1, n) cout << arr[i];
		cout << '\n';
		FOR(i, 1, n) cout << x[i] - arr[i];
		cout << '\n';
	}
	return 0;
}