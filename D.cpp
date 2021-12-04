#include<iostream>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int mod = 998244353;
const int maxn = 1000010;
int a[1000010];
typedef long long LL;
//求组合数的方法
//https://blog.csdn.net/qq_40772692/article/details/81835414?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.no_search_link&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1.no_search_link
LL fac[maxn];//乘阶表
LL power(LL a, LL b) {//快速幂
	a %= mod;
	LL ans = 1;
	while (b) {
		if (b & 1)ans = (ans * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return ans;
}
LL inv(LL a) {//返回逆元（费马小定理）
	return power(a, mod - 2) % mod;
}
void solve() {//计算乘阶表
	fac[0] = 1;
	for (int i = 1; i <= maxn - 1; i++) {
		fac[i] = (fac[i - 1] * i) % mod;
	}
}
LL comb(int n, int k) {//返回组合数（组合数公式）
	if (k > n)return 0;
	return (fac[n] * inv(fac[k]) % mod * inv(fac[n - k]) % mod) % mod;
}

int main() {
	solve();
	int n;
	LL p;
	LL num = 0;
	scanf("%d", &n);
	//cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		//cin >> a[i];
		sum += a[i];
	}
	scanf("%lld", &p);
	//cin >> p;
	for (int i = 1; i <= p; i++) {
		num = (num + comb(sum, i)) % mod;
	}
	num = num % mod;
	printf("%lld", num);
	//cout << num;
	return 0;
}