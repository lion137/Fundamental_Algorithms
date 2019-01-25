#include <iostream>
#include <vector>
#include <random>
template <typename T, typename I>
T partition(std::vector<T>, I, I);

int main () {
	std::vector<int> A = {1, 10, -9, 801, -388, 137, 123, -9};
	return 0;
}

template <typename T, typename I>
T partition(std::vector<T> a, I p, I r) {
	T t = a[r];
	I i = p - 1;
	for (I j = p; j < r;j++){
		if (a[j] <= t) {
			i += 1;
			std::swap(a[i], a[j]);
		}
	}
	std::swap(a[i + 1], a[r]);
	return i + 1;
}
