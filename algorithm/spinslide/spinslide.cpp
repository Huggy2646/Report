#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>

using namespace std;


class puzzle {
	vector<vector<char>> puz;
	int spin_slide_count;
	vector<char> p;
	int puz_size;
	public:
		
		puzzle(int puzzle_size, int spin_slide_count, ifstream &Fin) {
			this->puz_size = puzzle_size;
			this->spin_slide_count = spin_slide_count;
			for (int i = 0; i < puzzle_size; i++) {
				string s;
				Fin >> s;
				for (int j = 0; j < s.size(); j++) {
					p.push_back(s[j]);
				}
				puz.push_back(p);
				p.clear();
				
			}//for

		}
		// show
		string show() {
			string result="";
			for (int i = 0; i < puz_size; i++) {
				for (int j = 0; j < puz_size; j++) {
					result+=puz[i][j];
				}
				result += "\n";
			}
			result += "\n";
			return result;
		}

		void spin_slide() {
			
			queue<char> point;
			queue<char> block;

			vector<vector<char>> zero_puzzle(puz_size, vector<char>(puz_size, 0));
			for (int count = 0; count < spin_slide_count; count++) {
				for (int i = 0; i < puz_size; i++) {
					for (int j = 0; j < puz_size; j++) {
						zero_puzzle[j][puz_size - 1 - i] = puz[i][j];
					}
				}
				for (int i = 0; i < puz_size; i++) {
					for (int j = 0; j < puz_size; j++) {
						if (zero_puzzle[j][i] == '.') {
							point.push('.');

						}
						else {
							block.push(zero_puzzle[j][i]);
						}
					}
					for (int k = 0; k < puz_size; k++) {
						if (!point.empty()) {
							puz[k][i] = point.front();
							point.pop();
							continue;
						}
						else if (point.empty() && !block.empty()) {
							puz[k][i] = block.front();
							block.pop();
						}

					}
				}
			}

			
			//puz = zero_puzzle;
		}
		~puzzle() {};
};

int main() {
	ifstream Fin("spinslide.inp");
	vector<puzzle> puzzles;
	int count;
	int puzzle_size;
	int spin_slide_count;
	Fin >> count;

	for (int i = 0; i < count; i++) {
		Fin >> puzzle_size;
		Fin >> spin_slide_count;
		puzzle pzl(puzzle_size, spin_slide_count,Fin);
		puzzles.push_back(pzl);
	}
	

	for (int i = 0; i < puzzles.size(); i++) {
		puzzles[i].spin_slide();
	}
	
	ofstream writeFile("spinslide.out");
	if (writeFile.is_open()) {
		for (int i = 0; i < puzzles.size(); i++) {
			writeFile << "Case #" << i + 1 << ":"<<endl;
			writeFile << puzzles[i].show();
		}
		writeFile.close();
	}
	
	return 0;
}