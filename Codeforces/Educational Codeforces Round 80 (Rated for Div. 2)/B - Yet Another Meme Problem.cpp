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
		ll a, b; cin >> a >> b;
		ll i = 9, cnt = 0;
		for (; i <= b; i = (i * 10) + 9, cnt++);
		cout << a * cnt << '\n';
	}
	return 0;
}
