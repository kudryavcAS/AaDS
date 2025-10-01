#include <algorithm>
#include <fstream>
#include <vector>

int main()
{
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	std::vector<int> vec;
	int num;
	while (in >> num) {
		vec.push_back(num);
	
	}
	std::sort(vec.begin(), vec.end());
	auto endv = std::unique(vec.begin(), vec.end());
	vec.erase(endv, vec.end());

	long long sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		sum += vec[i];
	}
	out << sum;
	out.close();
	in.close();

}
