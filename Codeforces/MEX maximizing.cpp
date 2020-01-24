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
 
map <pair <int, int>, int> m;
vi v;
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int q, x;
	cin >> q >> x;
	v = vi(x);
	for (int i = 0; i < x; i++) m[{0, i}] = 0;
	for (int i = 1; i <= q; i++) {
		int a; cin >> a;
		a %= x;
		auto it = m.lower_bound({ v[a],a });
		m[{it->first.first + 1, a}] = 1;
		m.erase(it);
		v[a]++;
		cout << m.begin()->first.second + x * m.begin()->first.first << '\n';
	}
	return 0;
}