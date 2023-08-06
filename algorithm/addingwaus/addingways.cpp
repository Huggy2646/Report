#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include <vector>
using namespace std;

int main() {
	freopen("addingways.inp", "r", stdin);
	freopen("addingways.out", "w", stdout);
	vector<vector<long long>> dp(21, vector<long long>(301, 0));
	for (long long n = 1; n < 301; n++) {
		dp[1][n] = 1;
	}
	for (long long n = 2; n < 301; n++) {
		dp [2][n] = n / 2;
	}
	for (long long i = 1; i < 21; i++) {
		dp[i][i] = 1;
	}
	
	for (long long k = 3; k < 21; k++) {
		for (long long n = k+1; n < 301; n++) {
			for (long long i = 1; i <= k; i++) {
				dp[k][n] += dp[i][n-k];
				//cout << "\t" << dp[i][n - k] <<" ";
			}
			dp[k][n] = dp[k][n] % 1000000007;
			//cout << endl;
			//cout << "k: " << k << " n:" << n<<" dp[k][n]"<<dp[k][n]<<endl;

		}
	}
	while (true) {
		int n;
		int k;
		cin >> n;
		cin >> k;
		if (n == 0 && k == 0) {
			break;
		}
		cout << dp[k][n] << endl;
	}
	return 0;

}
