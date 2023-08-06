#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
int n;
int m;
string result;

void grid_path_bfs(vector<vector<int>>& grid, vector<vector<int>>& save_grid) {
	for (int i = 1; i < n ; i++) {
		for (int j = 1; j < m ; j++) {
			if (grid[i][j] != -1) {
				if (save_grid[i - 1][j] < save_grid[i][j - 1]) {
					if(save_grid[i - 1][j]==-1)
						save_grid[i][j] = save_grid[i][j-1] + grid[i][j];
					else
						save_grid[i][j] = save_grid[i-1][j] + grid[i][j];
				}
				else {

					if (save_grid[i][j - 1] == -1 && save_grid[i - 1][j] == -1) 
						save_grid[i][j] = -1;
					
					else if (save_grid[i][j-1] == -1)
						save_grid[i][j] = save_grid[i - 1][j] + grid[i][j];
					else
						save_grid[i][j] = save_grid[i][j - 1] + grid[i][j];
					
				}
			
			}
		}
	}
	
}
void path(vector<vector<int>>save_grid) {
	
	pair<int, int> pr;
	stack<pair<int, int>>st;
	int row = n - 1;
	int col = m - 1;
	result += to_string(save_grid[row][col]);
	result += "\n";
	st.push(make_pair(row, col));
	if (save_grid[row][col] == -1) {
		result = "No path.";
	}
	else {
		while (row != 0 || col != 0) {
			if (row == 0) {
				st.push(make_pair(row, --col));
			}
			else if (col == 0) {
				st.push(make_pair(--row, col));
			}
			else if (save_grid[row - 1][col] <= save_grid[row][col - 1]) {
				if (save_grid[row - 1][col] == -1) {
					st.push(make_pair(row, --col));
				}
				else
					st.push(make_pair(--row, col));
			}
			else {
				if (save_grid[row][col-1] == -1) {
					st.push(make_pair(--row, col));
				}
				else
					st.push(make_pair(row, --col));
			}

		}
		while (st.empty() != true) {
			pr = st.top();
			row = pr.first;
			col = pr.second;
			result += "(";
			result += to_string(row);
			result += " ";
			result += to_string(col);
			result += ")";
			result += "\n";
			st.pop();
		}
	
	}
}
int main() {
	ifstream fr("gridpath.inp");
	fr >> n;
	fr >> m;
	vector<vector<int>> grid(n,vector<int>(m,0));
	vector<vector<int>> save_grid(n,vector<int>(m,-1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int data;
			fr >> data;
			grid[i][j] = data;
		}
	}
	save_grid[0][0] = grid[0][0];
	for (int i = 1; i < n; i++) {
		if (grid[i][0] == -1) {
			break;
		}

		save_grid[i][0] = save_grid[i - 1][0] + grid[i][0];
		
	}
	for (int i = 1; i < m; i++) {
		if (grid[0][i] == -1) {
			break;
		}
		save_grid[0][i] = save_grid[0][i - 1] + grid[0][i];
	}
	grid_path_bfs(grid, save_grid);
	path(save_grid);
	ofstream fw("gridpath.out");
	while (fw.is_open()) {
		fw << result;
		fw.close();
	}
}