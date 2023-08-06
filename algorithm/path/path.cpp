#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<vector>
#include<stack>;
using namespace std;
int m, n, k;

class Cost {
	public:
		int r_c=0;
		int d_c=0;
		bool x=0;
		Cost(bool x = false,int r_c=0, int d_c=0) {
			this->r_c = r_c;
			this->d_c = d_c;
			this->x = x;
		}
};
void path_tracking(vector<vector<vector<int>>>& cost_dp,vector<stack<pair<int,int>>>& path) {
	for (int i = 0; i < k; i++) {
		int row = m - 1;
		int col = n - 1;
		if (i == 3) {
			cout << 3;
		}
		if (cost_dp[row][col][i] != 0) {
			while (row != 0 || col != 0) {
				//������ col������ ��
				if (row == 0) {
					path[i].push(make_pair(row, col - 1));
					col--;
				}
				else if (col == 0) {
					path[i].push(make_pair(row - 1, col));
					row--;
				}
				else {
					int l = cost_dp[row][col-1][i];
					int u = cost_dp[row-1][col][i];
					if (cost_dp[row - 1][col][i] == 0) {
						path[i].push(make_pair(row, col - 1));
						col--;
					}
					else if (cost_dp[row][col-1][i] == 0) {
						path[i].push(make_pair(row - 1, col));
						row--;
					}
					else if (u < l) {
						path[i].push(make_pair(row-1, col));
						row--;
					}
					else {
						path[i].push(make_pair(row, col - 1));
						col--;
					}
				}


				
			}
		}
	}

}
void cost_cal(vector<vector<vector<int>>>& cost_dp, vector<vector<Cost>>& cost) {
	//���������� ��ó��
	int count = 0;
	for (int i = 1; i < n; i++) {
			if (cost[0][i].x == true) {
				count++;
				cost_dp[0][i][count] = cost_dp[0][i - 1][count-1] + cost[0][i - 1].r_c;
			}
			else {
				cost_dp[0][i][count] = cost_dp[0][i - 1][count] + cost[0][i - 1].r_c;
			}
	}
	count = 0;
	//�Ʒ�
	for (int i = 1; i < m; i++) {
		if (cost[i][0].x == true) {
			count++;
			cost_dp[i][0][count] = cost_dp[i - 1][0][count - 1] + cost[i - 1][0].d_c;
		}
		else {
			cost_dp[i][0][count] = cost_dp[i - 1][0][count] + cost[i - 1][0].d_c;
		}
	}
	// cost ���
	
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			// cost ���ϱ�
			for (int l = 0; l < k; l++) {
				// �� �Ʒ� ����ġ ������, k=1���� k=k;
				int c_1=cost_dp[i][j - 1][l], c_2= cost_dp[i-1][j][l];
				// ����ġ�� 0�̸� ���°�ζ� �׳� 0�� ����
				if (c_1 != 0)
					c_1 += cost[i][j-1].r_c;
				if(c_2 != 0)
					c_2 += cost[i-1][j].d_c;
				// �� �� 0�̸� 0�� dp���̺� ���� �� �� �ϳ��� 0�̸� ������ ����ġ�� dp���̺� ����
				if (c_1 == 0 && c_2 == 0) {
					cost_dp[i][j][l] = 0;
				}
				else if (c_1 != 0 && c_2 == 0) {
					cost_dp[i][j][l] = c_1;
				}
				else if (c_1 == 0 && c_2 != 0) {
					cost_dp[i][j][l] = c_2;
				}
				//�� �� ���� cost�� dp���̺� ����
				else if (c_1 < c_2)
					cost_dp[i][j][l] = c_1;
				else
					cost_dp[i][j][l] = c_2;
			}

			// ���� x�̸� ���������� ��ĭ shift ���� �ڸ��� 0���� �ʱ�ȭ
			if (cost[i][j].x == true) {
				vector<int> buff(k, 0);
				for (int l = 1; l < k; l++) {
					buff[l] = cost_dp[i][j][l-1];
				}
				cost_dp[i][j] = buff;

			}
		}
	}

}
void path_num(vector<vector<vector<int>>>& data_table, vector<vector<Cost>>& cost) {
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			//origin_data
			for (int l = 0; l < k; l++) 
				data_table[i][j][l] = data_table[i][j - 1][l] + data_table[i - 1][j][l];

			if (cost[i][j].x == true) {
				//move_data;
				//���ο� ���͸� ���� buffer����
				vector<int> new_v(k,0);
				// ���ο� ���Ϳ� ���������� �ֱ�(index==1~������)
				for (int l = 1; l < k; l++) {
					new_v[l] = data_table[i][j][l - 1];
				}
				// ���ο���� �� == ���� �������� ��-1 so, ������ ������ ������ �� ���� ���ؾ� ��
				new_v[k - 1] + data_table[i][j][k - 1];
				data_table[i][j] = new_v;
				
			}
		}
	}
}
int main() {
	freopen("path.inp", "r", stdin);
	//freopen("path.out", "w", stdout);
	int cases;
	cin >> cases;
	for (int num=0; num < cases; num++) {
		cout << "Test Case No:"<< num+1<<endl;
		cin >> m >> n >> k;
		vector<vector<vector<int>>> data_table(m, vector<vector<int>>(n, vector<int>(k, 0)));
		vector<vector<vector<int>>> cost_dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
		vector<vector<Cost>> cost(m,vector<Cost>(n));
		vector<stack<pair<int, int>>>path(k);
		//x�� ǥ��� ��ǥ �Է�
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			Cost c(true);
			cost[x][y] = c;
		}
		//����ġ �Է�
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n - 1; j++) {
				cin >> cost[i][j].r_c;
			}
		}
		for (int i = 0; i < m-1; i++) {
			for (int j = 0; j < n; j++) {
				cin >> cost[i][j].d_c;
			}
		} 
		//���μ��� ��ó��
		int count=-1;
		for (int i = 1; i < n; i++) {
			if (cost[0][i].x == false) {
				if (count == -1)
					count++;
				data_table[0][i][count] = 1;
			}
			else
				data_table[0][i][++count] = 1;
		}
		count = -1;
		for (int i = 1; i < m; i++) {
			if (cost[i][0].x == false) {
				data_table[i][0][count] = 1;
			}
			else
				data_table[i][0][++count] = 1;
		}
		/*cout << cost[0][0].d_c;*/
		path_num(data_table, cost);
		cost_cal(cost_dp, cost);
		path_tracking(cost_dp, path);
		//dp table cout
		//for (int i = 0; i < m; i++) {
		//	for (int j = 0; j < n; j++) {
		//		for (int l = 0; l < k; l++) {
		//			cout << cost_dp[i][j][l]<<",";
		//		}
		//		cout << "   ";
		//	}
		//	cout << endl;
		//}
		for (int i = 0; i < k-1; i++) {
			if (path[i].empty());
			else {
				cout << "k:" << i << " count:"<< data_table[m-1][n-1][i-1] << " cost:"<<cost_dp[m-1][n-1][i]<<endl;
				while (!path[i].empty()) {
					cout <<"(" << path[i].top().first << "," << path[i].top().second <<")" << "->";
					path[i].pop();
				}
				cout << "(" << m - 1 << "," << n - 1 << ")";
				cout << endl;
			}


		}
	}
	return 0;
}