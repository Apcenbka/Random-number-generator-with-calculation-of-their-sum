#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;


int main() {
	 

	ofstream output("numbers.txt"); 
	if (!output) {
		cerr << "Error creates new file!" << endl;
		return 1;
	}
	
	for (int num = 0; num < 5; num++) {
		output << rand() % 10 << " " << endl;
	}
	output.close();
   
	
	ifstream input("numbers.txt");
	if (!input.is_open()) {
		cerr << "Error opening file!" << endl;
		return 1;
	}
	int a, res = 0;
	while (input >> a) {
		res += a;
	}
	string line;
	while (getline(input, line)) {
		cout << line << endl;
	}
	input.close();


	ofstream result("result.txt");
	result << "Sum all numbers: " << res << endl;
	cout << "Done! Sum of all numbers is written to result.txt" << endl;
	result.close();

	return 0;

}