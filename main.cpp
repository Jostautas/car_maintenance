#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void data_txt(vector<string> &A, vector<int> &B, vector<int> &C, vector<int> &D){
	ifstream F("data.txt");
	string a;
	int b, c, d;
	while(!F.eof()){
		F >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
	F.close();
}
void print_out(vector<string> A, vector<int> B, vector<int> C, vector<int> D){
	time_t t = time(0);
	tm* now = localtime(&t);
	int k = 0;
	for(int i = 0; i < A.size() - 1; i++){
		if(((now->tm_year + 1900) * 12 + now->tm_mon + 1) >= (B.at(i) * 12 + C.at(i) + D.at(i))){
			if(k == 0)
				cout << "Maintenance needed at the moment:" << endl;
			cout << A.at(i) << endl;
			k++;
		}
	}
	if(k == 0)
		cout << "No maintenance needed ant the moment" << endl;

}
int main(){
	vector<string> A; // A - name of the maintenance that needs to be done. 
	vector<int> B, C, D; // B - the last time the maintenance was done(year). C - the last time the maintenance was done(month). D - maintenance frequency
	data_txt(A, B, C, D);
	print_out(A, B, C, D);
	return 0;
}

