#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
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
		int a, b, c, n;
		cin >> a >> b >> c >> n;
		if((a + b + c + n) % 3) cout << "NO" << '\n';
		else {
			int val = (a + b + c + n) / 3;
			if (val >= a && val >= b && val >= c) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
	return 0;
}