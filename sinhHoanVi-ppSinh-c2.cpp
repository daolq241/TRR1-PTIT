#include<iostream>>
using namespace std;
int n = 4, a[1000];
bool OK = true;

init(){
	for(int i = 1; i <= n; i++) {
		a[i] = i;
	}
}
display() {
	for(int i = 1; i<=n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
bool checkIsFinal(){
	for(int i =1 ;i<=n; i++) {
		if(a[i] != n-i+1) return false;
	}
	return true;
}
gen(){
	int j = n-1;
	while(a[j] > a[j+1]) 
		j--;
	if(j>0) {
		int k = n;
		while(a[k] < a[j]) k--;
		swap(a[j], a[k]);
		int r = j+1, s = n;
		while(r < s) {
			swap(a[r], a[s]);
			r++;
			s--;
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

