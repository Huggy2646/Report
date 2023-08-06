#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string result;
int num = 0;
class Bitmap {
public:
	vector<char>l_u;
	vector<char>r_u;
	vector<char>l_d;
	vector<char>r_d;
	vector<char>map;
	int n;
	int m;
	int m_step;
	int n_step;
	int n_n_step;
	int m_m_step;
	Bitmap(string format, int n, int m, vector<char> map) {
		this->n = n;
		this->m = m;
		/*vector<char>map(bit.begin(), bit.end());*/
		this->map = map;
		if (m % 2 == 0)
			this->m_step = m / 2;
		else
			this->m_step = m / 2 + 1;
		m_m_step = m - m_step;
		if (n % 2 == 0)
			this->n_step = n / 2;
		else
			this->n_step = n / 2 + 1;
		n_n_step = n - n_step;

	}
	void devision() {
		int curr_step = 0;
		//왼쪽 위 영역
		for (int i = 0; i < n_step; i++) {
			l_u.insert(l_u.end(), map.begin() + curr_step, map.begin() + curr_step + m_step);
			curr_step += m;

		}
		//오른쪽 위 영역
		curr_step = m_step;
		for (int i = 0; i < n_step; i++) {
			r_u.insert(r_u.end(), map.begin() + curr_step, map.begin() + curr_step + m_m_step);
			curr_step += m;
		}
		//왼쪽 아래
		curr_step = m * n_step;
		for (int i = 0; i < n - n_step; i++) {
			l_d.insert(l_d.end(), map.begin() + curr_step, map.begin() + curr_step + m_step);
			curr_step += m;
		}
		curr_step = (m * n_step) + (m_step);
		//오른쪽 아래
		for (int i = 0; i < n - n_step; i++) {
			r_d.insert(r_d.end(), map.begin() + curr_step, map.begin() + curr_step + m_m_step);
			curr_step += m;
		}
	}
};
class Bitmap_b_to_d {
public:
	vector<char> l_u;
	vector<char> r_u;
	vector<char> l_d;
	vector<char> r_d;
	int min_n;
	int max_n;
	int min_m;
	int max_m;
	int mid_n;
	int mid_m;
	Bitmap_b_to_d(int min_n, int max_n, int min_m, int max_m) {
		this->min_n = min_n;
		this->max_n = max_n;
		this->min_m = min_m;
		this->max_m = max_m;
		if ((max_n - min_n) % 2 == 0) {
			this->mid_n = (min_n + (max_n - min_n)) / 2;
		}
		else {

			this->mid_n = (min_n + (max_n - min_n) / 2) + 1;
		}
		if ((max_m - min_m) % 2 == 0) {
			this->mid_m = min_m + (max_m - min_m) / 2;
		}
		else {
			this->mid_m = (min_m + (max_m - min_m) / 2) + 1;
		}
	}
		void division() {
			//왼쪽위
			l_u.push_back(min_n);
			l_u.push_back(mid_n);
			l_u.push_back(min_m);
			l_u.push_back(mid_m);
			//오른위
			r_u.push_back(min_n);
			r_u.push_back(mid_n);
			r_u.push_back(mid_m+1);
			r_u.push_back(max_m);
			//왼쪽아래
			l_d.push_back(mid_n+1);
			l_d.push_back(max_n);
			l_d.push_back(min_m);
			l_d.push_back(mid_m);
			//오른아래
			r_d.push_back(mid_n+1);
			r_d.push_back(max_n);
			r_d.push_back(mid_m+1);
			r_d.push_back(max_m);
		}
		

	

};
bool zero_one(vector<char>map) {
	if (map.size() != 0) {
		if (find(map.begin(), map.end(), '0') != map.end()) {
			if (find(map.begin(), map.end(), '1') != map.end()) {
				result += "D";
				num++;
				if (num == 50) {
					result += "\n";
					num = 0;
				}
				return false;
			}
			else {
				result += "0";
				num++;
				if (num == 50) {
					result += "\n";
					num = 0;
				}
				return true;
			}
		}
		else {
			result += "1";
			num++;
			if (num == 50) {
				result += "\n";
				num = 0;
			}
			return true;
		}
	}
	else
		return true;
}
void re_b(string format, int n, int m, vector<char> map) {
	Bitmap bm(format, n, m, map);
	if (zero_one(bm.map) == false) {
		bm.devision();
		re_b(format, bm.n_step, bm.m_step, bm.l_u);
		re_b(format, bm.n_step, bm.m_m_step, bm.r_u);
		re_b(format, bm.n_n_step, bm.m_step, bm.l_d);
		re_b(format, bm.n_n_step, bm.m_m_step, bm.r_d);
	}
}
void re_d(string format, int min_n, int max_n, int min_m,int max_m,vector<vector<char>>&map, vector<char>data,int &i) {
	char c = data[i];
	i++;
	Bitmap_b_to_d bbtd(min_n, max_n, min_m, max_m);
	if (c == 'D') {
		bbtd.division();
		re_d(format, bbtd.l_u[0], bbtd.l_u[1], bbtd.l_u[2], bbtd.l_u[3], map, data, i);
		c = data[i-1];
		for (int k = bbtd.l_u[0]; k < bbtd.l_u[1]; k++) {
			for (int j = bbtd.l_u[2]; j < bbtd.l_u[3]; j++) {
				map[k][j] = c;
			}

		}
		re_d(format, bbtd.r_u[0], bbtd.r_u[1], bbtd.r_u[2], bbtd.r_u[3], map, data, ++i);
		
		c = data[i];
		cout << i << endl;
		for (int k = bbtd.r_u[0]; k < bbtd.r_u[1]; k++) {
			for (int j = bbtd.r_u[2]; j < bbtd.r_u[3]; j++) {
				map[k][j] = c;
			}

		}
		
		re_d(format, bbtd.l_d[0], bbtd.l_d[1], bbtd.l_d[2], bbtd.l_d[3], map, data, ++i);
		
		c = data[i];
		cout << i << endl;
		for (int k = bbtd.l_d[0]; k < bbtd.l_d[1]; k++) {
			for (int j = bbtd.l_d[2]; j < bbtd.l_d[3]; j++) {
				map[k][j] = c;
			}

		}
		
		re_d(format, bbtd.r_d[0], bbtd.r_d[1], bbtd.r_d[2], bbtd.r_d[3], map, data, i);
		
		c = data[i];
		cout << i << endl;
		for (int k = bbtd.r_d[0]; k < bbtd.r_d[1]; k++) {
			for (int j = bbtd.r_d[2]; j < bbtd.r_d[3]; j++) {
				map[k][j] = c;
			}

		}
	}
	else {
		
	}

}
string format="-1";
int main() {
	ifstream Fr("bitmap.inp");
	while (Fr.is_open()) {

		
		int n;
		int m;
		string bit;
		if(format=="-1")
			Fr >> format;
		if (format == "#")
			break;
		else if (format == "B") {
			result += "D ";
		}
		else
			result += "B ";
		Fr >> n;
		Fr >> m;
		result += to_string(n) += " ";
		result += to_string(m) += "\n";
		if (n * m > 50 && format == "B") {
			for (int i = 0; i < (n * m / 50) + 1; i++) {
				string s;
				Fr >> s;
				bit += s;
			}
			vector<char>map(bit.begin(), bit.end());
			re_b(format, n, m, map);
		}
		else if (format == "D") {
			string s;
			int max_n = n;
			int min_n = 0;
			int max_m = m;
			int min_m = 0;
			int mid_n = -1;
			int mid_m = -1;
			while (true) {
				Fr >> s;
				if (s != "D" && s != "B" && s != "#") {
					bit += s;
				}
				else{
					format = s;
					break;
				}
			}
			vector<vector<char>>map(n, vector<char>(m, -1));
			vector<char>data(bit.begin(), bit.end());
			int i = 0;
			re_d(format, min_n, max_n, min_m, max_m, map, data,i);
		}

		else {
			Fr >> bit;
		}

	}
	ofstream fw("bitmap.out");
	if (fw.is_open()) {
		fw << result;
		fw.close();
	}
	return 0;
}