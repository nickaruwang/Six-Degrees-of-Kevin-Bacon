#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>

#include "utils.h"

using namespace std;

Graph :: Graph() {
	size = 0;
}

void Graph :: insert(string line) {
	stringstream sline(line);
	string mv;
	set<string> act;
	sline >> mv;
	string a;
	while (sline >> a) {
		movies[size].insert(a);
		actors[a].insert(size);
	}
	ids[size++] = mv;
	return;
}

vector<string> Graph :: shortestPath(string a1, string a2) {
	queue<vector<string>> q;
	vector<string> v(1, a1);
	set<string> visited;
	q.push(v);
	v.clear();
	while (q.size() > 0) {
		vector<string> f = q.front();
		q.pop();
		string last = f[f.size() - 1];
		if (last == a2) {
			return f;
		}
		set<int> mvs = actors[last];
		for (auto i = mvs.begin(); i != mvs.end(); i++) {
			set<string> acts = movies[*i];
			for (auto j = acts.begin(); j != acts.end(); j++) {
				if (visited.count(*j) == 0) {
					visited.insert(*j);
					vector<string> next(f);
					next.push_back(ids[*i]);
					next.push_back(*j);
					q.push(next);
				}
			}
		}
	}
	return v;
}

string Graph :: printpath(vector<string> v) {
	if (v.empty()) {
		return "Not present";
	}
	// string out = v[0];
	// for (size_t i = 1; i < v.size(); i++) {
	// 	out += " -(" + sharedMovie(v[i], v[i-1]) + ")- " + v[i];
	// }
	string out = "";
	for (size_t i = 0; i < v.size(); i++) {
		if (i % 2 == 1) {
			out += "-(" + v[i] + ")- ";
		}
		else {
			out += v[i] + " ";
		}
	}
	return out;
}

