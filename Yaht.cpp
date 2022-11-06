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
#define VERSION "1.0"

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

string evalDice(string S);

int main() {
	auto t1 = high_resolution_clock::now();
	cout << "Yacht v" << VERSION << "!\n\n";
	//string path = "Test.txt";
	string path = "Try.txt";
	vector<string> raw_data = loadData(path);
	vector<string> solution;

	for (int i = 1; i < raw_data.size(); i++) {

		string str = evalDice(raw_data[i]);
		solution.push_back(str);
		cout << raw_data[i] << " : " << str << endl;
	}
	cout << "\nSolution: " << joinVector(solution, " ") << endl;;

	/***********************/
	auto t2 = high_resolution_clock::now();
	auto ms_int = duration_cast<milliseconds>(t2 - t1);
	cout << "Execution time: " << ms_int.count() << " ms" << endl;
}

string evalDice(string S) {
	vector<int> set = splitToInt(S, " ");
	vector<int> map(6, 0);
	for (auto& i : set) {
		map[i - 1]++;
	}
	sort(map.begin(), map.end());
	reverse(map.begin(), map.end());
	string text;
	if (*max_element(map.begin(), map.end()) == 1) {
		if (find(set.begin(), set.end(), 6) != set.end()) {
			text = "big-straight";
		}
		else {
			text = "small-straight";
		}
	}
	else {
		switch (map[0]) {
		case 5:
			text = "yacht";
			break;
		case 4:
			text = "four";
			break;
		case 3:
			if (map[1] == 2) {
				text = "full-house";
			}
			else {
				text = "three";
			}
			break;
		case 2:
			if (map[1] == 2) {
				text = "two-pairs";
			}
			else {
				text = "pair";
			}
			break;
		}
	}

	return text;
}
