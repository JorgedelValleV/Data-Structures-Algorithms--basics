// Jorge del Valle Sinam Pongol DG23
#include <iostream>
#include <vector>
using namespace std;

//{1<=N<=10000 ^p.t u:1<=u <N:-279<=v[u]<=1000}
//fun caso(N:ent,v[0,,,N)de ent)dev numpic:ent
//{(numpic = # j: 1<=j <N-1:v[j-1] < v[j] && v[j] > v[j+1])}
// I := 1<= i <= N-1 && (numpic = # j: 1<=j <i:v[j-1] < v[j] && v[j] > v[j+1])
// C:= N-i >=0
//inicializamos con i=1,numpic=0;
//restablecemos sumando uno a numpic si se da el caso
//avanzamos con ++i
//Coste caso peor:i recorre N-2 valores es decir, O(caso) = N

int picos(vector<int> & v, int N) {
	int numpic = 0;
	size_t i = 1;
	while (i < N-1) {
		if (v[i-1] < v[i] && v[i] > v[i+1]) {
			++numpic;
		}
		
		++i;
	}
	return numpic;
}
//{1<=N<=10000}
//fun caso(N:ent,v[0,,,N)de ent)dev numval:ent
//{(numval = # k: 1<=k <N-1:v[k-1] > v[k] && v[k] < v[k+1])}
// I := 1<= i <= N-1 && (numval = # k: 1<=k <i:v[k-1] > v[k] && v[k] < v[k+1])
// C:= N-i >=0
//inicializamos con i=1, nuval=0;
//restablecemos sumando uno a numval si se da el caso
//avanzamos con ++i
//Coste caso peor:i recorre N-2 valores es decir, O(caso) = N
int valles(vector<int> & v, int N) {
	int numval = 0;
	size_t i = 1;
	while (i < N - 1) {
		if (v[i - 1] > v[i] && v[i] < v[i + 1]) {
			++numval;
		}
		++i;
	}
	return numval;
}
void casos() {
	size_t N;
	cin >> N;
	vector<int> v(N);
	for (size_t i = 0; i < N; ++i) cin >> v[i];
	int pic = picos(v, N);
	int val = valles(v, N);
	cout << pic << ' ' << val << '\n';
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) { casos(); }
	system("PAUSE");
	return 0;
}