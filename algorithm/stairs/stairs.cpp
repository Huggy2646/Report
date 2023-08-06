#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class baejji {
	int max_floor;
	int home_floor;
	int goal;
	int ev_count = 0;
public:
	baejji(int max_floor, int home_floor, int goal) {
		this->max_floor = max_floor;
		this->home_floor = home_floor;
		this->goal = goal;
	}
	string result() {
		return to_string(ev_count);
	}
	int count() {
		if (goal < max_floor - home_floor) {
			ev_count++;
			return 0;
		}
		else {
			if (home_floor >= goal) {
				ev_count++;
				return 0;
			}
			goal -= (max_floor-1);
			ev_count++;
			while (true) {
				if (goal <= 0) {
					return 0;
				}
				goal -= (max_floor - 1);
				ev_count++;
			}

		}

	}

};
int main() {
	int num;
	vector<baejji> multiverse_baejji;
	string result;
	ifstream Fin("stairs.inp");
	Fin >> num;

	for (int i = 0; i < num; i++) {
		int m, f, n;
		Fin >> m;
		Fin >> f;
		Fin >> n;
		baejji other_baejji(m, f, n);
		multiverse_baejji.push_back(other_baejji);
	}
	//show
	for (int i = 0; i < num; i++) {
		multiverse_baejji[i].count();
		if (i == num - 1) {
			result += multiverse_baejji[i].result();
		}
		else
			result+=multiverse_baejji[i].result()+="\n";
	}
	ofstream writeFile("stairs.out");
	if (writeFile.is_open()) {
		writeFile << result;
		writeFile.close();
	}
	return 0;
}