#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<vector>
using namespace std;
int card_selection(vector<int> data_s, vector<int>& dp_vector,vector<int>&dp_vector_m2,int init,int step) {
	int a = -10000000, b = -10000000, c = -10000000;
	int m_2=init-2, m_3=init-3, m_4=init-4;
	if (dp_vector[init] != -1001 && step != -2) {
		return dp_vector[init];
	}
	else if (dp_vector_m2[init] != -1001 && step == -2) {
		return dp_vector_m2[init];
	}
	else if (init == 0 || init == 1 || init == 2) {
		dp_vector[init] = data_s[init];
		return data_s[init];
	}
	else {
		if (step == -2) {
			if (init == 3) {
				b = card_selection(data_s, dp_vector,dp_vector_m2, m_3, -3);
			}
			else{
				b = card_selection(data_s, dp_vector, dp_vector_m2, m_3, -3);
				c = card_selection(data_s, dp_vector, dp_vector_m2, m_4, -4);
			}
		}
		else {
			if (init == 3) {
				a = card_selection(data_s, dp_vector, dp_vector_m2, m_2, -2);
				b = card_selection(data_s, dp_vector, dp_vector_m2, m_3, -3);
			}
			else {
				a = card_selection(data_s, dp_vector, dp_vector_m2, m_2, -2);
				b = card_selection(data_s, dp_vector, dp_vector_m2, m_3, -3);
				c = card_selection(data_s, dp_vector, dp_vector_m2, m_4, -4);
			}

		}
		if (a > b) {
			if (a > c) {
				if (step ==-2) {
					dp_vector_m2[init] = a + data_s[init];
					return dp_vector_m2[init];
				}
				else {
					dp_vector[init] = a + data_s[init];
					return dp_vector[init];
				}
				
			}
			else {
				if (step == -2) {
					dp_vector_m2[init] = c + data_s[init];
					return dp_vector_m2[init];
				}
				else {
					dp_vector[init] = c + data_s[init];
					return dp_vector[init];
				}
			}
		}
		else {
			if (b > c) {
				if (step == -2) {
					dp_vector_m2[init] = b + data_s[init];
					return dp_vector_m2[init];
				}
				else {
					dp_vector[init] = b + data_s[init];
					return dp_vector[init];
				}
			}
			else {
				if (step == -2) {
					dp_vector_m2[init] = c + data_s[init];
					return dp_vector_m2[init];
				}
				else {
					dp_vector[init] = c + data_s[init];
					return dp_vector[init];
				}
			}
		}
	}
}
int main() {
	freopen("card.inp", "r", stdin);
	freopen("card.out", "w", stdout);
	int cases;
	cin >> cases;
	for (; cases > 0; cases--) {
		int data_num;
		cin >> data_num;
		vector<int> data_s;
		vector<int> dp_vector(data_num,-1001);
		vector<int> dp_vector_m2(data_num, -1001);

		for (; data_num > 0; data_num--) {
			int data;
			cin >> data;
			data_s.push_back(data);
		}
		//for (int i = 0; i < data_s.size(); i++) {
		//	cout << data_s[i] << ", ";
		//}
		/*cout << endl;*/
		int result = card_selection(data_s, dp_vector, dp_vector_m2,data_s.size()-1,0);
		cout << result<<endl;
	}
}