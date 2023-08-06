#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;
long row;
long col;

void T_F(long t, long size) {
	row = 0;
	col = 0;
	long target = t - 1;
	long curr_num = 0;
	bool b = false;
	long data_r = 0;
	long data_c = 0;
	long k = 0;
	while (true) {
		if (curr_num < size) {
			data_c += size - 1;
			curr_num += size - 1;
		}
		else {
			data_c += size;
			curr_num += size;
		}
		/*cout << "(" << data_r << "," << data_c << ")" << endl;*/
		if (curr_num >= target) {
			/*cout << curr_num;*/
			data_c -= (curr_num - target);
			row = data_r;
			col = data_c;
			break;
		}
		size--;

		data_r += size;
		curr_num += size;
		/*cout << "(" << data_r << "," << data_c << ")" << endl;*/
		if (curr_num >= target) {
			/*cout << curr_num;*/
			data_r -= (curr_num - target);
			row = data_r;
			col = data_c;
			break;
		}

		data_c -= size;
		curr_num += size;
		/*cout << "(" << data_r << "," << data_c << ")" << endl;*/
		if (curr_num >= target) {
			/*cout << curr_num;*/
			data_c += (curr_num - target);
			row = data_r;
			col = data_c;
			break;
		}
		//data_2++;
		size--;

		data_r -= size;
		curr_num += size;
		/*cout << "(" << data_r << "," << data_c << ")" << endl;*/
		if (curr_num > target) {
			/*cout << curr_num;*/
			data_r += (curr_num - target);

			row = data_r;
			col = data_c;
			break;
		}
	}
}

int main() {
	ifstream Fin("snail.inp");
	long num;
	long size;
	long r_1;
	long r_2;
	long c_1;
	long c_2;
	string s;
	Fin >> num;

	for (long i = 0; i < num; i++) {
		Fin >> size;
		long a;
		long b;
		Fin >> a;
		Fin >> b;
		T_F(a, size);
		r_1 = row;
		c_1 = col;
		/*cout << "("<< row <<"," << col<<")" << endl;*/

		T_F(b, size);
		r_2 = row;
		c_2 = col;
		/*cout << "(" << row << "," << col << ")" << endl;*/

		if (abs(r_1 - r_2) == abs(c_1 - c_2)) {
			s += "YES";
			s += "\n";
		}
		else {
			s += "NO";
			s += "\n";
		}


	}
	ofstream wf("snail.out");
	if (wf.is_open()) {
		wf << s;
		wf.close();
	}
	return 0;
}