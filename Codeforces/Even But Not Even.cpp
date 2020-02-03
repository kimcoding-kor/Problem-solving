#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
 
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int test; cin >> test; while (test--) {
		int n;
		cin >> n;
		char ch[3005];
		cin >> ch;
		vi v(3005);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			v[i] = (ch[i] - '0');
			sum += v[i];
		}
		int idx = n - 1;
		for (; idx >= 0; idx--) {
			if (v[idx] & 1) {
				idx--;
				break;
			}
			sum -= v[idx];
			v[idx] = -1;
		}
		for (; idx >= 0; idx--) {
			if (!(sum & 1)) break;
			if (!(v[idx] & 1)) continue;
			sum -= v[idx];
			v[idx] = -1;
		}
		if (idx < 0) cout << "-1\n";
		else {
			for (int i = 0; i < n; i++)
				if(v[i] != -1) cout << v[i];
			cout << '\n';
		}
	}
	return 0;
}