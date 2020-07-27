#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
	FIO;
	int n, sum = 0, cnt = 0;
	cin >> n;
	
	FOR(i, 1, n) {
		int x;
		cin >> x;
		sum += x;
		cnt += x / 2;
	}

	if (sum % 3 || sum / 3 > cnt)
		cout << "NO\n";
	else cout << "YES\n";
	return 0;
}