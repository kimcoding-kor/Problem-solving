#include <cstdio>
int button[10][5] = { {0,1,2,-1,-1},{3,7,9,11,-1},{4,10,14,15,-1},{0,4,5,6,7},{6,7,8,10,12},{0,2,14,15,-1},{3,14,15,-1,-1},{4,5,7,14,15},{1,2,3,4,5},{3,4,5,9,13} };
int arr[16], temp[10], ans;

void dfs(int level) {
	if (level == 10) {
		int chk[16], sum = 0;
		for (int i = 0; i < 16; i++) chk[i] = arr[i];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < temp[i]; j++) {
				sum++;
				for (int k = 0; k < 5; k++) {
					if (button[i][k] == -1) break;
					chk[button[i][k]] = chk[button[i][k]] + 3;
					if (chk[button[i][k]] == 15) chk[button[i][k]] = 3;
				}
			}
		}
		int i;
		for (i = 0; i < 16; i++)
			if (chk[i] != 12) break;
		if (i == 16) ans = ans > sum ? sum : ans;
		return;
	}
	for (int i = 0; i <= 3; i++) {
		temp[level] = i;
		dfs(level + 1);
	}
}

int main() {
	int test; scanf("%d", &test);
	while (test--) {
		for (int i = 0; i < 16; i++)
			scanf("%d", &arr[i]);
		ans = 1e9;
		dfs(0);
		if (ans == 1e9) printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}