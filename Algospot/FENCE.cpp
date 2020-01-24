#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		int n, ans = 0;
		scanf("%d", &n);
		vector <int> v(n + 2);
		stack <int> st;
		for (int i = 1; i <= n; i++)
			scanf("%d", &v[i]);
		for (int i = 0; i <= n + 1; i++) {
			while (!st.empty() && v[i] < v[st.top()]) {
				int now = st.top(); st.pop();
				int area = v[now] * (i - st.top() - 1);
				ans = max(ans, area);
			}
			st.push(i);
		}
		printf("%d\n", ans);
		v.clear();
		while (!st.empty()) st.pop();
	}
	return 0;
}