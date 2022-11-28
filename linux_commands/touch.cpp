#include<stdio.h>
int main(int argc, char** arg){
	FILE *f;
	f = fopen(arg[1],"w");
	fclose(f);
	return 0;
}
