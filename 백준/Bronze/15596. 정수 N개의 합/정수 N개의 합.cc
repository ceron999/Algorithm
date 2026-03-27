#include <vector>
using namespace std;
long long sum(std::vector<int>& a) {
	long long ans = 0;

	vector<int>::iterator ptr;

	for (ptr = a.begin(); ptr != a.end(); ptr++)
	{
		ans += *ptr;
	}

	return ans;
}
