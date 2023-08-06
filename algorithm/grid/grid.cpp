#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;
string beautiful(int n,int m,vector<int>paints) {
	vector<int> possible_painting_n;
	vector<int> possible_painting_m;
	bool tree_up_n = false;
	bool tree_up_m = false;
	string result = "No";
	for (int i = 0; i < paints.size(); i++) {
		if (paints[i] / n >=2) {
			possible_painting_n.push_back(paints[i] / n);
			if (paints[i] / n >= 3)
				tree_up_n = true;
		}
		if (paints[i] / m >= 2) {
			possible_painting_m.push_back(paints[i] / m);
			if (paints[i] / m >= 3)
				tree_up_m = true;
		}
		if (n % 2 == 0) {
			if (m <= accumulate(possible_painting_n.begin(), possible_painting_n.end(), 0)) {
				result = "Yes";
			}
			
		}
		else {
			if (tree_up_n) {
				if (m <= accumulate(possible_painting_n.begin(), possible_painting_n.end(), 0)) {
					result = "Yes";
				}
			}
		}
		if (m % 2 == 0) {
			if (n <= accumulate(possible_painting_m.begin(), possible_painting_m.end(), 0)) {
				result = "Yes";
			}
		}
		else {
			if (tree_up_m) {
				if (n <= accumulate(possible_painting_m.begin(), possible_painting_m.end(), 0)) {
					return "Yes";
				}
			}
		}
		
	}
	return result;
}
int main() {
	int num;
	string result;
	ifstream Fin("grid.inp");
	Fin >> num;
	for (int i = 0; i < num; i++) {
		int n;
		int m;
		int paint_num;
		vector<int> paints;
		Fin >> n;
		Fin >> m;
		Fin >> paint_num;
		for (int j = 0; j < paint_num; j++) {
			int paint;
			Fin >> paint;
			paints.push_back(paint);
		}
		result += beautiful(n, m, paints);
		result += "\n";
	}
	ofstream Fout("grid.out");
	if (Fout.is_open()) {
		Fout << result;
		Fout.close();
	}
}