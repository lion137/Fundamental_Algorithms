#include <iostream>
#include <vector>
#include <random>

int partition(int a[], int s, int p);
int partition_random(int a[], int s, int p);
int quick_select(int a[], int s, int n, int k);
float median(int a [], int n);
void printAr(int a[], int n);
void quicksort(int a[], int s, int n); 

int main() {
	int A[8] = {1, 10, -9, 801, -388, 137, 123, -9};
	printAr(A, 8);
	int s = 8;
	for (int i = 1; i < 9;i++){
		int e = quick_select(A, 0, 8, i);
		std::cout << i <<"th smallest:"<< e << " \n";
	}
	std::cout << median(A, 8) << " <- median";
	std::cout << "\n";
	quicksort(A, 0, 8);
	printAr(A, 8);
	std::cout << "\n";
	return 0;
}

int partition(int a[], int p, int r) {
	int t = a[r];
	int i = p - 1;
	for (int j = p; j < r;j++){
		if (a[j] <= t) {
			i += 1;
			std::swap(a[i], a[j]);
		}
	}
	std::swap(a[i + 1], a[r]);
	return i + 1;
}

int quick_select(int a[], int s, int n, int k) {
		int r = partition_random(a, s, n);
		if (r - s == k - 1) {return a[r];}
		else {
		
		if (k - 1 < r - s) {
			return quick_select(a, s, r - 1, k);
		}
		else  {
			return quick_select(a, r + 1 , n, k - r + s - 1);
		}
	}
}

int partition_random(int a[], int p, int r) {
	std::random_device rd;     
	std::mt19937 rng(rd());   
	std::uniform_int_distribution<int> uni(p, r); 
	auto rn = uni(rng);
	std::swap(a[r], a[rn]);
	return partition(a, p, r);
}

float median(int a [], int n) {
	if (n % 2 == 1)
		return quick_select(a, 0, n - 1, n / 2 + 1);
	int l = n / 2;
	int r = n / 2 + 1;
	return (1.0 * (quick_select(a, 0, n - 1, l) + 
			quick_select(a, 0, n - 1, r))) / 2;
	
}

void quicksort(int a[], int s, int n) {
	if (s < n) {
		int r = partition_random(a, s, n);
		quicksort(a, s, r - 1);
		quicksort(a, r + 1, n);
	}
}

void printAr(int a[], int n) {
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << "\n";
}









