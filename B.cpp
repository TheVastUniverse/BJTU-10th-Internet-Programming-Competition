#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
long long x[100010], v[100010];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld%lld", &x[i],&v[i]);
	}
	int i = 1;
	long long maxl = v[0];
	while (maxl >= x[i] && i < n) {
		maxl = maxl + v[i];
		i++;
	}
	long long k;
	scanf("%lld", &k);
	for (int s = 0; s < k; s++) {
		int Q;
		scanf("%d", &Q);
		if (Q <= maxl) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}