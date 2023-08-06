#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>

using namespace std;
int main() {
	freopen("card.inp", "r", stdin);
	freopen("card.out", "w", stdout);

	int cases;
	cin >> cases;
	while (cases!=0) {
		char turn;
		int data_n;
		cin >> data_n;
		vector<vector<int>>dp(data_n, vector<int>(data_n, 0));
		vector<int> data(data_n, 0);
		for (int i = 0; i < data_n; i++) {
			int d;
			cin >> d;
			data[i] = d;
		}
		if (data_n % 2 == 0) {
			turn = 'a';
		}

		else {
			turn = 'c';
			for (int i = 0; i < data_n; i++) {
				dp[i][i] = data[i];
			}
		}
		

		for (int i = 1; i < data_n; i++) { // col로 움직이는 갯수
			if (turn == 'a') {
				for (int j = 0; j < data_n - i; j++) {
					int row = j;
					int col = j + i;
					dp[row][col] = max(dp[row][col - 1] + data[col], dp[row + 1][col] + data[row]);
				}
				turn = 'c';
			}
			else {
				for (int j = 0; j < data_n - i; j++) {
					int row = j;
					int col = j + i;
					dp[row][col] = min(dp[row][col - 1], dp[row + 1][col]);
				}
				turn = 'a';
			}
		}
		cout << dp[0][data_n-1] << endl;
		cases--;
	}	
	
}
