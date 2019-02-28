#include <iostream>
#include <vector>

using namespace std;



//find all the variations with repetitions of the subset of n - 1 elements
void variations(int n, vector<int> p, vector<bool> c) {
	if (p.size() == (size_t) n) {
		for (auto & e : p)
			cout << e << " ";
		cout << "\n";
	 } else {
		 for (int i = 0; i < n; i++) {
			 if (c[i])
				continue;
			 c[i] == true;
			 p.push_back(i);
			 variations(n, p, c);
			 c[i] = false;
			 p.pop_back();
		 }
	   }
}


int main() {
	vector<int> p;
	vector<bool> c(2);
	variations(2, p, c); // => 0 0, 0 1, 1 0, 1 1
	cout << "\n";
	return 0;
}
