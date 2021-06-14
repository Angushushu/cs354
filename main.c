#include <stdio.h>
void func();

int x = 1;
int y;
int z = 3;

int main(){
	printf("x,y,z before func(): %i,%i,%i\n",x,y,z);
	func();
	printf("x,y,z after func(): %i,%i,%i\n",x,y,z);
	printf("%d\n", x + y + z);
	return 0;
}
