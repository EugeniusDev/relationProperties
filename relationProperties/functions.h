#pragma once
#include <iostream>
#include <string>
using namespace std;

bool allZeros(int** arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i][j] != 0 && i != j)
				return false;
		}
	}
	return true;
}

string reflexivityGet(int** arr, int size) {
	//check for reflexivity
	bool reflexive;
	for (int i = 0; i < size; i++) {
		if (arr[i][i] == 1)
			reflexive = true;
		else {
			reflexive = false;
			break;
		}
	}
	//check for antireflexivity
	if (!reflexive) {
		for (int i = 0; i < size; i++) {
			//check for non-reflexivity
			if (arr[i][i] != 0)
				return "not ";
		}
		return "anti";
	}
	else return "";
}

string symmetryGet(int** arr, int size, string reflexivityInfo) {
	bool symmetric;
	//checking if all elements are zeros
	if (allZeros(arr, size))
		return "not ";
	//check for symmetry
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i][j] == 1 && i != j) {
				if (arr[i][j] == arr[j][i])
					symmetric = true;
				else {
					symmetric = false;
					break;
				}
			}
		}
	}
	if (!symmetric) {
		//check if not symmetric
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (arr[i][j] == 1 && arr[i][j] == arr[j][i] && i != j) {
					return "not ";
				}
			}
		}
		if (reflexivityInfo == "anti")
			return "a";
		else return "anti";
	}
	else return "";
}

string transitivityGet(int** arr, int size) {
	bool trans = false;
	//check if all elements are 0
	if (allZeros(arr, size))
		return "not ";
	//check if transitive
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i][j] == 1 && i != j) {
				for (int k = 0; k < size; k++) {
					if (arr[j][k] == 1 && j != k) {
						if (arr[i][k] == 1 && i != k)
							trans = true;
						else {
							//check if antitransitive
							for (int l = 0; l < size; l++) {
								if (arr[j][l] == 1 && j != l) {
									if (arr[i][l] == 0 && i != l)
										trans = false;
									else return "not ";
								}
							}
						}
					}
				}
			}
		}
	}
	if (trans)
		return "";
	else return "anti";
}