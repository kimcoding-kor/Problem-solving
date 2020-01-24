#include <cstdio>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef vector <int> vi;
typedef struct p {
	int a, b, c;
}p;

vector <p> temp;
stack <string> ans;
vi par, uf;

int find(int x) {
	return uf[x] ? uf[x] = find(uf[x]) : x;
}

string uni(int a, int b, int chk) {
	if (!chk) {
		uf[a] = par[a];
		return "";
	}
	a = find(a); b = find(b);
	return a == b ? "YES" : "NO";
}

int main() {
	int n, q; scanf("%d %d", &n, &q);
	uf = par = vi(n + 1);
	temp.resize(n + q);
	for (int i = 2; i <= n; i++) scanf("%d", &par[i]);
	for (int i = 1,x; i < n + q; i++) {
		scanf("%d", &x);
		if (x) scanf("%d %d", &temp[i].b, &temp[i].c);
		else scanf("%d", &temp[i].b);
		temp[i].a = x;
	}
	for (int i = n + q - 1; i >= 1; i--) {
		if (temp[i].a)
			ans.push(uni(temp[i].b, temp[i].c, 1));
		else uni(temp[i].b, -1, 0);
	}
	while (!ans.empty()) {
		printf("%s\n", ans.top().c_str());
		ans.pop();
	}
	return 0;
}