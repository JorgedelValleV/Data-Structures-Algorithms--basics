// Jorge del Valle Sinam Pongol DG23
#include <iostream>
#include <vector>
using namespace std;



void caso(vector<int> & v, int N,int A,int & c,int & f) {
	int ind = 0; c = 0; f = 0; int s = 0;
	while (ind != N ) {
		if (v[ind] <= A) {
			s = ind + 1;
		}
		if (f - c < ind+1 - s) {
			f = ind+1;
			c = s;
		}
		++ind;
	}
	--f;
}
void casos() {
	int N; int A;
	cin >> N >> A;
	vector<int> v(N);
	for (int i = 0; i < N; ++i) cin >> v[i];
	int f, c;
	caso(v, N, A, c, f);
	cout << c << ' ' << f << '\n';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) { casos(); }
	system("PAUSE");
 	return 0;
}