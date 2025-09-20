#include <iostream>
#include <vector>

const int MOD = 1000000007;

long long modpow(long long a, long long b) {
	long long result = 1;
	while (b > 0) {
		if (b & 1) result = (result * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return result;
}

int main() {

	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, k;
	std::cin >> n >> k;

	long long num = 1, denom = 1;
	if (n - k < k) k = n - k;

	for (int i = 1; i <= k; i++) {
		num = num * ((n - i + 1)) % MOD;
		denom = (denom * i) % MOD;

	}

	long long result = (num * modpow(denom, MOD - 2)) % MOD;
	std::cout << result;
}