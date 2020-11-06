#include<iostream>
using namespace std;
int n = 5, k = 3, a[1000];
init(){
	for (int i = 1; i <= k; i++) {
		a[i] = i;
	}
}
display(){
	for(int i = 1; i <=k; i++) {
		cout << a[i] << " ";
	}
	cout  << endl;
}
bool checkIsFinal(){
	for(int i = k; i >=1; i--) {
		if(a[i] != n-k+i) return false;
	}
	return true;
}
gen(){
	int i = k;
	if(i > 0 && a[i] == n-k+i)
	  i--;
	if(i>0) {
		a[i] ++;
		for(int j = i+1; j <= k; j++){
			a[j] = a[i] + j - i;
		}	
	}	
}

int main() {
	init();
	display(); 
	while(!checkIsFinal()) {
		gen();
		display();
	}
	return 0;
}

