#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	vector <int> v(n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	sort(v.begin() + 1, v.end());
	int i;
	for (i = n; i > 0; i--)
		if (!(k % v[i])) break;
	printf("%d\n", k / v[i]);
	return 0;
}