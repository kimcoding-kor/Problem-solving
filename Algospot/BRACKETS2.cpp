#include <cstdio>
#include <cstring>
#include <stack>

bool solve(char* arr) {
	std::stack <char> st;
	int len = strlen(arr);
	for (int i = 0; i < len; i++) {
		char ch = arr[i];
		if (ch == '(' || ch == '{' || ch == '[') st.push(ch);
		else {
			if (st.empty()) return false;
			else if (st.top() == '(' && ch == ')') st.pop();
			else if (st.top() == '{' && ch == '}') st.pop();
			else if (st.top() == '[' && ch == ']') st.pop();
			else break;
		}
	}
	return st.empty() ? true : false;
}

int main() {
	int test; scanf("%d", &test); while (test--) {
		char arr[10005];
		scanf("%s", arr);
		solve(arr) ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}