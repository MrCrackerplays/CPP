#include <iostream>
#include "PmergeMe.hpp"
#define K 16

static void	mergeDeque(std::deque<unsigned long> &de, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	std::deque<unsigned long> LA (de.begin() + p, de.begin() + q + 1);
	std::deque<unsigned long> RA (de.begin() + q + 1, de.begin() + r + 1);
	int RIDX = 0;
	int LIDX = 0;
	for (int i = p; i <= r; i++) {
		if (RIDX == n2) {
			de[i] = LA[LIDX];
			LIDX++;
		} else if (LIDX == n1) {
			de[i] = RA[RIDX];
			RIDX++;
		} else if (RA[RIDX] > LA[LIDX]) {
			de[i] = LA[LIDX];
			LIDX++;
		} else {
			de[i] = RA[RIDX];
			RIDX++;
		}
	}
}

static void	insertDeque(std::deque<unsigned long> &de, int p, int q) {
	for (int i = p; i < q; i++) {
		unsigned long tempVal = de[i + 1];
		int j = i + 1;
		while (j > p && de[j - 1] > tempVal) {
			de[j] = de[j - 1];
			j--;
		}
		de[j] = tempVal;
	}
	std::deque<unsigned long> temp (de.begin() + p, de.begin() + q + 1);
}

void	sortDeque(std::deque<unsigned long> &de, int p, int r) {
	if (r - p > K) {
		int	q = (p + r) / 2;
		sortDeque(de, p, q);
		sortDeque(de, q + 1, r);
		mergeDeque(de, p, q, r);
	} else {
		insertDeque(de, p, r);
	}
}

static void	mergeVector(std::vector<unsigned long> &ve, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<unsigned long> LA (ve.begin() + p, ve.begin() + q + 1);
	std::vector<unsigned long> RA (ve.begin() + q + 1, ve.begin() + r + 1);
	int RIDX = 0;
	int LIDX = 0;
	for (int i = p; i <= r; i++) {
		if (RIDX == n2) {
			ve[i] = LA[LIDX];
			LIDX++;
		} else if (LIDX == n1) {
			ve[i] = RA[RIDX];
			RIDX++;
		} else if (RA[RIDX] > LA[LIDX]) {
			ve[i] = LA[LIDX];
			LIDX++;
		} else {
			ve[i] = RA[RIDX];
			RIDX++;
		}
	}
}

static void	insertVector(std::vector<unsigned long> &ve, int p, int q) {
	for (int i = p; i < q; i++) {
		unsigned long tempVal = ve[i + 1];
		int j = i + 1;
		while (j > p && ve[j - 1] > tempVal) {
			ve[j] = ve[j - 1];
			j--;
		}
		ve[j] = tempVal;
	}
	std::vector<unsigned long> temp (ve.begin() + p, ve.begin() + q + 1);
}

void	sortVector(std::vector<unsigned long> &ve, int p, int r) {
	if (r - p > K) {
		int	q = (p + r) / 2;
		sortVector(ve, p, q);
		sortVector(ve, q + 1, r);
		mergeVector(ve, p, q, r);
	} else {
		insertVector(ve, p, r);
	}
}
