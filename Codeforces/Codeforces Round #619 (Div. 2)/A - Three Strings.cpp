#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define vi vector <int>
#define vvi vector <vi>
#define pii pair<int,int>
#define ll long long
#define vector <ll,ll> vll;
#define all(x) (x).begin(), (x).end()
#define fs first
#define sd second
#define eb emplace_back
using namespace std;
 
int main() {
	FIO;
	int t; cin >> t; while (t--) {
		string a, b, c;
		cin >> a >> b >> c;
		int flag = 1;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != c[i] && b[i] != c[i]) flag = 0;
		}
		cout << (flag ? "YES\n" : "NO\n");
	}
	return 0;
}