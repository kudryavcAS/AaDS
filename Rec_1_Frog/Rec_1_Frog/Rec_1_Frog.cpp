#include <iostream>
#include <vector>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int n;
	std::cin >> n;

	std::vector<int> gnats(n + 1);
	std::vector<long long> amount(n + 1, -1);
	std::vector<int> prev_wlily(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		std::cin >> gnats[i];
	}
	amount[1] = gnats[1];
	prev_wlily[1] = 0;

	if (n == 1) {
		std::cout << gnats[1] << "\n";
		std::cout << 1;
		return 0;
	}
	if (n == 2) {
		std::cout << -1;
		return 0;
	}

	amount[3] = gnats[1] + gnats[3];
	prev_wlily[3] = 1;

	if (n >= 4) {
		amount[4] = gnats[1] + gnats[4];
		prev_wlily[4] = 1;
	}

	for (int i = 5; i <= n; i++) {
		long long var1 = amount[i - 2];
		long long var2 = amount[i - 3];

		if (var1 > var2) {
			amount[i] = gnats[i] + var1;
			prev_wlily[i] = i - 2;
		}
		else {
			amount[i] = gnats[i] + var2;
			prev_wlily[i] = i - 3;
		}
	}
	std::cout << amount[n] << '\n';

	std::vector<int> track;

	for (int cur = n; cur != 0; cur = prev_wlily[cur]) {
		track.push_back(cur);
	}

	std::reverse(track.begin(), track.end());
	for (int i = 0; i < track.size(); i++) {
		std::cout << track[i] << " ";

	}

}
