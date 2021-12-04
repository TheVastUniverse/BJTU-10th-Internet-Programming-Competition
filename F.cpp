#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int a[5010];
bool b[5010];
int res[5010];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != 1) {
			break;
		}
		cnt++;
	}
	cout << cnt << endl;
	for (int i = n - 1; i > 0; i--) {
		if (b[i] != true) {
			res[i] = a[i];
			b[i] = true;
			int tag = 0;
			for (int j = cnt; j < i; j++) {
				while ((a[j] != a[tag]) && (b[j] != true) && (a[j]!=a[i]) &&(a[i] % a[j] == 0)) {
					tag = j;
					b[j++] = true;
				}
			}
		}
	}
	sort(res, res + n);
	cout << res[n - cnt];
	for (int i = n - cnt + 1; i < n; i++) {
		cout << " " << res[i];
	}
	return 0;
}