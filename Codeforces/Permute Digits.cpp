#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector <ll> va, vb, bb, chk(10);
ll ans;
int dfs(int idx, int c) {
	if (va.size() == idx) return 1;
	for (int i = c ? vb[idx] : 9; i >= 0; i--) {
		if (!chk[i]) continue;
		ans = ans * 10 + i;
		chk[i]--;
		if (dfs(idx + 1, vb[idx] == i ? c : 0)) return 1;
		ans /= 10;
		chk[i]++;
	}
	return 0;
}
 
int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	ll temp = a;
	do {
		va.push_back(temp % 10);
		chk[temp % 10] ++;
	} while (temp /= 10);
	temp = b;
	do {
		bb.push_back(temp % 10);
	} while (temp /= 10);
	for (int i = bb.size() - 1; i >= 0; i--) vb.push_back(bb[i]);
	if (va.size() < vb.size()) {
		for (int i = 9; i >= 0;) {
			if (!chk[i]) {
				i--;
				continue;
			}
			ans = ans * 10 + i;
			chk[i]--;
		}
 
	}
	else
		dfs(0, 1);
	printf("%lld\n", ans);
	return 0;
}