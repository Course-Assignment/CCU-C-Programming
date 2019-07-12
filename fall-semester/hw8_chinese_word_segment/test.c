#include <stdio.h>
#include <stdlib.h>

int main(){
	char a[] = "我肏你媽的";
	char b[] = "幹你娘機掰";
	char *c = a;
	char *d = b;
	int i;
	for(i = 0; i < 5; i++){
		printf("%s\n", c);
		printf("%s\n", d);
		c = c+3;
		d = d+3;
	}
}
