#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void data_txt(vector<string> &A, vector<int> &B, vector<int> &C){
	ifstream F("data.txt");
	string a;
	int b, c;
	while(!F.eof()){
		F >> a >> b >> c;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
	}
	F.close();
}
int main(){
	vector<string> A; // A - name of the maintenance that needs to be done. 
	vector<int> B, C; // B - the last time the maintenance was done. C - maintenance frequency
	data_txt(A, B, C);
	cout << "Maintenance needed at the moment:" << endl;
	for(int i = 0; i < A.size() - 1; i++){
		cout << A.at(i) << " " << B.at(i) << " " << C.at(i) << endl;	
	}
        return 0;
}

