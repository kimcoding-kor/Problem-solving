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
		int n, m; cin >> n >> m;
		int arr[105], p[105] = {}, x;
		FOR(i, 1, n) cin >> arr[i];
		FOR(i, 1, m) cin >> x, p[x] = 1;
		int flag = 1, a, b;
		while (flag) {
			a = 0 , b = 0;
			FOR(i, 1, n - 1) {
				if (arr[i] > arr[i + 1]) a = 1;
				if (p[i] && arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]), b = 1;
			}
			if (!a) { flag = 0; break; }
			if (!b) break;
		}
		cout << (flag ? "NO\n" : "YES\n");
	}
	return 0;
}