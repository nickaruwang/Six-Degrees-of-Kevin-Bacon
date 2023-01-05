#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "utils.h"

using namespace std;

int main(int argc, char** argv) {
	if (argc < 3) {
		throw invalid_argument("USAGE: ./sixdegrees <INPUTFILE> <OUTFILE>");
	}
	ifstream input;
	input.open(argv[1]);
	ofstream output;
	output.open(argv[2]);

	ifstream movielist;
	string line;
	Graph g = Graph();
	movielist.open("cleaned_movielist.txt");
	while (getline(movielist, line)) {
		g.insert(line);
	}

	while (getline(input, line)) {
		string a1;
		string a2;
		stringstream sline(line);
		sline >> a1 >> a2;
		if (g.actors[a1].empty()) {
			output << "Not present" << endl;
			continue;
		}
		// CHECK IF A1 IN GRAPH
		vector<string> sp = g.shortestPath(a1, a2);
		output << g.printpath(sp) << endl;
	}

	input.close();
	output.close();
	return 0;
}
