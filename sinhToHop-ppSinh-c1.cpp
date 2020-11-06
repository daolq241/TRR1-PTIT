#include<iostream>
using namespace std;
int n = 5, k = 3, a[1000];
bool OK = true;
void init(){
	for(int i =1; i <= k; i++) {
		a[i] = i;
	}
}
void result() {
	for(int i =1; i <= k; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
gen() {
	int i = k;
	while(i > 0 && a[i] == n-k+i) {
		i--;
	}
	if(i > 0) {
		a[i]++;
		for(int j = i +1; j <= k; j++) {
			a[j] = a[i] + j - i;
		}
	}
	else OK = false;
}
int main() {
	init();
	while(OK) {
		result();
		gen();
	}
	return 0;
}

