#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
 
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define all(x) (x).begin(), (x).end()
 
typedef vector <int> vi;
typedef vector <vi> vvi;
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m; cin >> n >> m;
	string a[25], b[25];
	FOR(i, 0, n - 1) cin >> a[i];
	FOR(i, 0, m - 1) cin >> b[i];
	string c[405];
	int s = 0, t = 0;
	FOR(i, 0, n * m - 1) {
		c[i] = a[s] + b[t];
		s = (s + 1) % n;
		t = (t + 1) % m;
	}
	int q; cin >> q;
	for (int i = 1,x; i <= q; i++) {
		cin >> x;
		cout << c[(x - 1) % (n * m)] << '\n';
	}
	return 0;
}