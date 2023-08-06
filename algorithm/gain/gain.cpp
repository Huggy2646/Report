#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string result_s;
	int number;
	int size = 0;
	int data = 0;
	int result = 0;
	ifstream Fin("gain.inp");
	Fin >> number;
	for (int num = 0; num < number; num++) {
		Fin >> size;
		vector<int> v;
		for (int i = 0; i < size; i++) {
			Fin >> data;
			v.push_back(data);
		}
		sort(v.begin(), v.end());
		result = v[size-1]- v[0] + v[size - 2] - v[1];
		result_s += to_string(result)+="\n";
		result = 0;

	}
	ofstream wf("gain.out");
	if(wf.is_open()){
		wf << result_s;
		wf.close();
	}
}