#include<stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int A, D;
	scanf("%d %d", &A, &D);
	int a[11], d[11];
	while (A!=0 && D !=0) {
		for (int i = 0; i < A; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < D; i++) {
			scanf("%d", &d[i]);
		}
		sort(d, d+D);
		sort(a, a+A);
		if (a[0] == d[0]) {
			if (d[0] == d[1]) {
				printf("N\n");
			}
			else
				printf("Y\n");
		}
		else if (a[0]< d[0]){
			printf("Y\n");
		}
		else if (a[0]< d[1]){
			printf("Y\n");
		}
		else
			printf("N\n");
		
		
		scanf("%d %d", &A, &D);
		
	}
	
	
	return 0;
}
