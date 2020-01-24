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
		int flag = 0;
		int n, d; cin >> n >> d;
		for (int i = 0; i * i <= 1000000000; i++) {
			if (n >= i + (int)ceil(1.0 * d / (i + 1))) {
				flag = 1;
				break;
			}
		}
		cout << (flag ? "YES" : "NO") << '\n';
	}
	return 0;
}