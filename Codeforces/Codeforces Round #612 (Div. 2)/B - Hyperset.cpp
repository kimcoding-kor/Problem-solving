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
 
int n, k, ans;
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	map <string, int> m;
	string* arr = new string[n + 1];
	FOR(i, 1, n) {
		string s; cin >> s;
		for(auto & j : s)
			j = (j == 'S') ? '0' : (j == 'E') ? '1' : '2';
		arr[i] = s;
	}
	FOR(i, 1, n) {
		FOR(j, i + 1, n) {
			string s = "";
			FOR(x, 0, k - 1) {
				if (arr[i][x] == arr[j][x]) s += arr[i][x];
				else {
					char ch = '3' + '0' * 2 - (max(arr[i][x], arr[j][x]) + min(arr[i][x], arr[j][x]));
					s += ch;
				}
			}
			ans += (m.find(s) != m.end());
		}
		m[arr[i]] = 1;
	}
	cout << ans << '\n';
	return 0;
}