// https://www.codeabbey.com/index/task_view/yacht-or-dice-poker
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <chrono>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "0.0"

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

int main() {
	auto t1 = high_resolution_clock::now();
	cout << "Yacht v" << VERSION << "!\n\n";
	string path = "Test.txt";
	//string path = "Try.txt";
	vector<string> raw_data = loadData(path);
	vector<string> solution;

	for (int i = 1; i < raw_data.size(); i++) {

		cout << raw_data[i] << " : " << endl;
	}
	cout << "\nSolution: " << joinVector(solution, " ") << endl;;

	/***********************/
	auto t2 = high_resolution_clock::now();
	auto ms_int = duration_cast<milliseconds>(t2 - t1);
	cout << "Execution time: " << ms_int.count() << " ms" << endl;
}
