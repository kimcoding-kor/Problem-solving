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
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		int arr[105] = {};
		FOR(i, 1, n) cin >> arr[i];
		int sum, flag = 0;
		FOR(i, 1, n) {
			sum = 0, flag = 0;
			FOR(j, i, n) {
				sum += arr[j];
				if (~sum & 1) {
					flag = 1;
					cout << j - i + 1 << '\n';
					FOR(k, i, j) cout << k << ' ';
					cout << '\n';
					break;
				}
			}
			if (flag) break;
		}
		if (!flag) cout << -1 << '\n';
	}
	return 0;
}