#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
//#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
 
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define all(x) (x).begin(), (x).end()
 
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long ll;
typedef vector <ll> vl;
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		int a, b, c, flag = 0;
		for (int i = 2; i * i <= n; i++) {
			if (n % i) continue;
			a = i;
			for (int j = i + 1; j * j <= n / i; j++) {
				if ((n / i) % j) continue;
				b = j;
				c = n / i / j;
				if ((a == b) || (b == c) || (a == c)) continue;
				else {
					cout << "YES\n" << a << ' ' << b << ' ' << c << '\n';
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
		if (!flag) cout << "NO" << '\n';
	}
	return 0;
}