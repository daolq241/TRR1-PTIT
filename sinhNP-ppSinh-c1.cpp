#include<iostream>
using namespace std;
int n = 4, a[1000];
bool OK = true;
void init(){
	for(int i =1; i <= n; i++) {
		a[i] = 0;
	}
}
void result() {
	for(int i =1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void gen() {
	int i = n;
	while(i>0 && a[i] == 1) {
		a[i] = 0;
		i--;
	}
	if(i > 0)  a[i] = 1;
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

