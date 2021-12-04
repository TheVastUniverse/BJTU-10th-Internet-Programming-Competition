#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
long long res[1010][1010];
void calC() {
	for (int i = 0; i <= 1000; i++) {
		res[i][0] = res[i][i] = 1;
	}
	for (int i = 2; i <= 1000; i++) {
		for (int j = 0; j <= i / 2; j++) {
			res[i][j] = (res[i - 1][j] + res[i - 1][j - 1]) % 13331;
			res[i][i - j] = res[i][j];
		}
	}
}
int main() {
	long long n, m, p;
	long long num = 0;
	cin >> n >> m >> p;
	calC();
	//cout << res[100][5];
	for (int i = 1; i <= p; i++) {
		for (int a = 0; a <= i && a <= n; a++) {
			if (i - a > m) {
				continue;
			}
			num += (res[n][a] * res[m][i - a]) % 13331;
		}
	}
	num = num % 13331;
	cout << num;
	return 0;
}