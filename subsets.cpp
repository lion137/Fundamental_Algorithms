#include <iostream>
#include <vector>

using namespace std;

//find subsets of the set of n - 1 elements
void subsets(int k, int n, vector<int> s) {
	if (k == n) {
		for (auto & a : s)
			cout << a << " ";
		cout << "\n";
	} else {
		subsets(k + 1, n, s);
		s.push_back(k);
		subsets(k + 1, n, s);
		s.pop_back();
	  }
}


int main() {
	vector<int> p;
	subsets(0, 2, p); // -> 1, 0, 0 1, {}
	cout << "{}\n";
	cout << "\n";
	return 0;
}
