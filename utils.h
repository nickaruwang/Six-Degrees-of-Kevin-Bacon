#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class Graph {
	public:
		int size;
		unordered_map<int, set<string>> movies; // maps movie to set of actors
		unordered_map<string, set<int>> actors; // maps actor to movies
		unordered_map<int, string> ids; // maps movie to an int ID

		Graph();
		void insert(string);
		vector<string> shortestPath(string, string);

		string printpath(vector<string>);
};
