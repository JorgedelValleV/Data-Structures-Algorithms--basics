//Sinama Pongol
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//{1<=N<=1000000 ^ p.t u:0<=u <N:-1000000<=v[u]<=1000000 ^ (sum t:0<= t <N:|v[u]|)<=10^9}
//fun caso(N:ent,v[0,,,N)de ent)dev dia:ent
//{(dia = min m: 0<=m <N ^ resul(v, 0, N, m)=(min h : 0<=h<N-1: resul(v,0,N,h):m}////{(dia = min m: 0<=j <N:|vec[m]-vec[N-1]|}
//sum(v, x, y)=(sum k:x<=k <y:v[k])
//resul(v, x, y, z) = sum(v,x,z)-sum(v,z,y)

//bucle1
// I := 0<= j <= N && vec[j]=sum(v,0,j+1)
// C:=N-j >=0


//bucle2
// I := 0<= i <= N && val = (min r : 0<=r<=i: mitad-sum(v,0,r+1) && mitad=vec[N-1]/2 )&& dia = (min s: 0<=s<=i+1 ^ mitad-sum(v,0,s)=val: s)
/*¬b:= i = N
Fcota := C = N - i >= 0
->avanzar := i++
*/
/*Inicializar<mitad,val,dia,i,sum>=<tot/2,tot/2,0,0,0>
*/
/*mientras indice!= N-1 hacer
¿Restablecer?
R:=(I)indice+1/indice
*/
/*
si val>x ->val= x ,y  dia = i+1		(x=|mitad - vec[i]|)
*/

//Coste caso peor:j recorre N valorese i recorre N-1 es decir, O(caso) = N + N-1= 2N-1

int caso(vector<int> & v, int N) {
	float derecha = 0;
	for (int j = 0; j < N; ++j) {
		derecha += v[j];
	}
	float izquierda = 0;
	for (int k = 0; k < N; ++k) {
		izquierda += v[k];
		derecha -= v[k];
		v[k] = abs(izquierda - derecha);
	}
	int min = v[N-1];
	int i = 0;
	int dia = 0;
	while (i < N - 1 ) {
		if (v[i] < min) {
			min = v[i];
			dia = i + 1;
		}
		++i;
	}
	return dia;
}
bool casos() {
	int N;
	cin >> N;
	if (N == 0)return false;
	vector<int> v(N);
	for (int i = 0; i < N; ++i) cin >> v[i];
	int dia = caso(v, N);
	cout << dia << '\n';
	return true;
}

int main() {
	while (casos());
	return 0;
}