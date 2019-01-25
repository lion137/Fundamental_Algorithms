#include <iostream>
#include <vector>
#include <random>
void Swap(int a[], int l, int r);
template <typename T, typename I>
T partition(std::vector<T>, I s, I p);
int partition2(int a[], int s, int p);
int partition_random(int a[], int s, int p);
int quick_select(int a[], int s, int n, int k);
int quick_select2(int a[], int s, int n, int k);
float median(int a [], int n);
void printAr(int a[], int n);
void quicksort(int a[], int s, int n) {
	if (s < n) {
		int r = partition_random(a, s, n);
		quicksort(a, s, r - 1);
		quicksort(a, r + 1, n);
	}
} 
// ----------------MAIN-----------------
int main() {
	int A[8] = {1, 10, -9, 801, -388, 137, 123, -9};
	printAr(A, 8);
	int s = 8;
	for (int i = 1; i < 9;i++){
		int e = quick_select2(A, 0, 8, i);
		std::cout << i <<"th largest:"<< e << " \n";
	}
	std::cout << median(A, 8) << " <- median";
	std::cout << "\n";
	quicksort(A, 0, 8);
	printAr(A, 8);
	std::cout << "\n";

	return 0;
}
// ----------------MAIN-----------------
void printAr(int a[], int n) {
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << "\n";
}
void Swap(int a[], int l, int r){
	int tmp = a[l];
	a[l] = a[r];
	a[r] = tmp;
	
}


int quick_select(int a[], int s, int n, int k) {
	if (n == 1) {return a[1];}
	else {
		int r = partition2(a, s, n);
		if (k < r) {
			return quick_select(a, 1, r - 1, k);
		}
		else if (k > r) {
			return quick_select(a, r + 1, n, k - r);
		}
		else {
			return a[r];
		}
	}
}

int partition2(int a[], int p, int r) {
	int t = a[r];
	int i = p - 1;
	for (int j = p; j < r;j++){
		if (a[j] <= t) {
			i += 1;
			//Swap(a, i, j);
			std::swap(a[i], a[j]);
		}
	}
	//Swap(a, i + 1, r);
	std::swap(a[i + 1], a[r]);
	return i + 1;
}

int quick_select2(int a[], int s, int n, int k) {

		int r = partition_random(a, s, n);
		if (r - s == k - 1) {return a[r];}
		else {
		
		if (k - 1 < r - s) {
			return quick_select2(a, s, r - 1, k);
		}
		else  {
			return quick_select2(a, r + 1 , n, k - r + s - 1);
		}
	}
}

int partition_random(int a[], int p, int r) {
	std::random_device rd;     
	std::mt19937 rng(rd());   
	std::uniform_int_distribution<int> uni(p, r); 
	auto rn = uni(rng);
	std::swap(a[r], a[rn]);
	return partition2(a, p, r);
}

float median(int a [], int n) {
	if (n % 2 == 1)
		return quick_select2(a, 0, n - 1, n / 2 + 1);
	int l = n / 2;
	int r = n / 2 + 1;
	return (1.0 * (quick_select2(a, 0, n - 1, l) + 
			quick_select2(a, 0, n - 1, r))) / 2;
	
}

// generics
template <typename T, typename I>
I partition(std::vector<T> a, I p, I r){
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









