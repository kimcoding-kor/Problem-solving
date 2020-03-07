#include <cstdio>
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
 
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int test; cin >> test; while (test--) {
		int n; cin >> n;
		int ans = 0;
		while (n >= 10) {
			ans += (n / 10) * 10;
			int temp = n / 10;
			n %= 10, n += temp;
		}
		cout << ans + n << '\n';
	}
	return 0;
}