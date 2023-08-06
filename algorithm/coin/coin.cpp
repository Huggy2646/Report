#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
vector<int> num(101,-1);
int coin_game(int a, int b, int c) {
	int xor_1;
	int xor_2;
	if (num[a] < 0) {
		if (a != 0) {
			num[a] = a % 4;

		}
	}
	if (num[b] < 0) {
		if (b != 0) {
			num[b] = b % 4;
		}
	}
	if (num[c] < 0) {
		if (c != 0) {
			num[c] = c % 4;
		}
	}

	if (num[a] == num[b]) {
		//cout << num[a]<<endl;
		//cout << num[b] <<endl;
		xor_1 = 0;
	}
	else
		xor_1 = 1;
	if (num[b] == num[c]) {
		//cout << num[b] << endl;
		//cout << num[c] << endl;
		xor_2 = 0;
	}
	else
		xor_2 = 1;

	//for (int i = 0; i < 10; i++) {
	//	cout << num[i] << endl;
	//}
	int result = xor_1 + xor_2;
	return result;

}
int main() {
	num[0] = 0;
	ifstream fr("coin.inp");
	int cases;
	fr >> cases;
	for (int i = 0; i < cases; i++) {
		int a, b, c;
		fr >> a >> b >> c;
		if (coin_game(a, b, c) != 0) {
			cout << 1<<endl;
		}
		else {
			cout << -1<<endl;
		}

	
	}
	return 0;
}