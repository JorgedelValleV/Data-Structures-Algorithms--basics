#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int rec(vector<int> const & v, int c, int f) {
	if (c + 1 >= f) {
		return v[c];
	}
	else {
		int m = (c + f) / 2;
		if (v[m] < v[m-1])return rec(v, m, f);
		else return rec(v, c, m);
	}
}



bool resuelveCaso() {
	int n;
	cin >> n;
	if (!cin)return false;
	vector<int> v(n);
	for (int i = 0; i < v.size(); ++i) {
		cin >> v[i];
	}
	
	int sol = rec(v, 0, v.size());
	cout << sol << "\n";
	return true;
}
int main() {
	while (resuelveCaso());		
	system("Pause");
	return 0;
}