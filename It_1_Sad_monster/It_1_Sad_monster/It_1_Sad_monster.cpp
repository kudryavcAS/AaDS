#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
	std::iostream::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	short n;
	double a, b, c, d;

	std::cin >> n;
	std::cin >> a >> b >> c >> d;
	std::cout << std::fixed << std::setprecision(17);

	std::vector<double> dayprob(n + 2, 0.0), next_dayprob(n + 2, 0.0);
	dayprob[1] = 1;

	double prob, inc_prob, dec_prob, same_prob;

	for (int i = 0; i < n; i++) {
		fill(next_dayprob.begin(), next_dayprob.end(), 0.0);

		for (int x = 0; x <= n; x++) {
			prob = dayprob[x];

			if (prob == 0) { continue; }
			if (x == 0) {
				next_dayprob[0] += dayprob[0];
			}
			else {
				inc_prob = a + b / x;
				dec_prob = c - d / x;
				same_prob = 1 - inc_prob - dec_prob;

				next_dayprob[x + 1] += prob * inc_prob;
				next_dayprob[x] += prob * same_prob;
				next_dayprob[x - 1] += prob * dec_prob;

			}

		}
		dayprob.swap(next_dayprob);
		std::cout << dayprob[0] << "\n";

	}
}