#include<iostream>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;
int main() {
	int m, n;
	char t;
	int E[2] = { 0 }, V[2] = { 0 };
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> t;
			if (t == 'E') {
				E[0] = i;
				E[1] = j;
			}
			else if (t == 'V') {
				V[0] = i;
				V[1] = j;
			}
		}
	}
	cout << max(abs(E[0] - V[0]), abs(E[1] - V[1]));
	return 0;
}