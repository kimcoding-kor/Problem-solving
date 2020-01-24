#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define mod ((ll)1e9+7)
#define MAX 200005

struct FT {
	vector <ll> tree;
	int tree_size;
	FT(int n) : tree_size(n) {
		tree.resize(tree_size + 1);
	}
	void update(int idx, ll diff) {
		while (idx <= tree_size) {
			tree[idx] += diff;
			idx += (idx & -idx);
		}
	}
	ll query(int idx) {
		ll ans = 0;
		while (idx) {
			ans += tree[idx];
			idx -= (idx & -idx);
		}
		return ans;
	}
};

int main() {
	int n; scanf("%d", &n);
	FT ft_sum(MAX), ft_cnt(MAX);
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		ll x; scanf("%lld", &x);
		x++;
		if (i > 1) {
			ll left = x * ft_cnt.query(x - 1) - ft_sum.query(x - 1);
			ll right = (ft_sum.query(MAX) - ft_sum.query(x) - x * (ft_cnt.query(MAX) - ft_cnt.query(x)));
			ans = ans * ((left + right) % mod) % mod;
		}
		ft_cnt.update(x, 1LL);
		ft_sum.update(x, x);
	}
	printf("%lld\n", ans);
	return 0;
}