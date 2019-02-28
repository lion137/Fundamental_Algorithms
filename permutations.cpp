#include <iostream>
#include <vector>

using namespace std;

void printList(vector<int> v);
vector<int> remainder(vector<int> a, int i);
vector<int> append(vector<int> a, int elem);

//show all the permuatations of the vector r, s = {}
void recPermutation(vector<int> s, vector<int> r) {
	if (r.empty()) {
		printList(s);
	} 
	else {
		for (int i = 0; i < r.size(); i++) {
			vector<int> n = append(s, r[i]);
			vector<int> rem = remainder(r, i);
			recPermutation(n, rem);
		}
	}
}

// wrapper function, shows all the permuatations of a
void showPermutations(vector<int> a) {
	vector<int> e = {};
	recPermutation(e, a)
}

int main() {
	showPermutations(vector<int>{1, 2, 3});
	/* ->
	 1 2 3 
	 1 3 2 
	 2 1 3 
	 2 3 1 
	 3 1 2 
	 3 2 1 
	 */ 
	return 0;
}

vector<int> remainder(vector<int> a, int i) {
	vector<int> tmp;
	for (int k = 0; k < a.size(); k++) {
		if (k != i)
			tmp.push_back(a[k]);
	}
	return tmp;
	
}

vector<int> append(vector<int> a, int elem) {
	vector<int> tmp;
	a.push_back(elem);
	tmp = a;
	return tmp;
}

void printList(vector<int> v) {
	for (auto & e : v)
		cout << e << " ";
	cout <<"\n";
}
