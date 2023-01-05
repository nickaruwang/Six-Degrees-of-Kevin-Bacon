#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char **argv) {
	ifstream f1, f2;
	f1.open(argv[1]);
	f2.open(argv[2]);
	string line1, line2;
	int line = 0;
	while (getline(f1, line1) || getline(f2, line2)) {
		line++;
		cout << line1 << endl;
		cout << line2 << endl;
		cout << endl;
		if ((line1 == "") != (line2 == "")) {
			cout << "Different file lengths" << endl;
			break;
		}
		stringstream sline1(line1), sline2(line2);
		int x = 0, y = 0;
		string buf;
		while (sline1 >> buf) {
			if (x % 2 == 1) {
				continue;
			}
			x++;
		}
		while (sline2 >> buf) {
			if (y % 2 == 1) {
				continue;
			}
			y++;
		}
		
		if (x != y) {
			cout << "Line: " << line << ", " << x << " and " << y << endl;
		}
	}


	f1.close();
	f2.close();
	return 0;
}