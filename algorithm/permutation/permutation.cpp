#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack> 
#include <algorithm>
using namespace std;
class Node {
	public:
		int index;
		int depth;
		vector<int> origin_arr;
		vector<int> left_next_arr;
		vector<int> right_next_arr;
		Node(int index, int depth, vector<int> arr) {
			this->depth = depth;
			this->index = index;
			this->origin_arr = arr;
			left_next_arr.insert(left_next_arr.begin(),arr.begin(), arr.begin() + index);
			right_next_arr.insert(right_next_arr.begin(), arr.begin() + index+1, arr.end());

		}
};
int tree(int index, int depth,vector<int>arr,string&result) {
	Node node(index,depth,arr);
	//if (node.left_next_arr.size() == 0);

	if (node.origin_arr.size()==1) {
		//cout << node.depth;
		result += to_string(node.depth)+" ";
	}
	else {
		depth++;
		if (node.left_next_arr.size() >= 1) {
			
			index = max_element(node.left_next_arr.begin(), node.left_next_arr.end()) - node.left_next_arr.begin();
			tree(index, depth, node.left_next_arr,result);
		}
		//cout << node.depth;
		result += to_string(node.depth) + " ";
		if (node.right_next_arr.size() >= 1) {
			
			index = max_element(node.right_next_arr.begin(), node.right_next_arr.end()) - node.right_next_arr.begin();
			tree(index, depth, node.right_next_arr,result);
		}
	}

	return 0;
}
int main() {
	int cases;
	ifstream Fin("permutation.inp");
	Fin >> cases;
	string result = "";
	for (int loop = 0; loop < cases; loop++) {
		vector<int> number;
		int size;
		Fin >> size;
		for (int l = 0; l < size; l++) {
			int data;
			Fin >> data;
			number.push_back(data);
		}
		int index = max_element(number.begin(), number.end()) - number.begin();
		//cout << "frist_index" << index << endl;
		tree(index, 0, number,result);
		//cout << endl;
		result +="\n";
	}
	ofstream Fout("permutation.out");
	if(Fout.is_open()){
		Fout << result;
		Fout.close();
	}
	return 0;
}