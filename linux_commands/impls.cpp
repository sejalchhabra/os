#include<iostream>
using namespace std;

int main(int a, char** cmd){
	string s=cmd[1];
	if(s == "ls")
		system("ls");
	else if(s== "cat")
		system("cat impls.cpp");
	else if(s == "wc")
		system("wc impls.cpp");
	else if(s == "cp")
		system("cp ./impls.cpp ./tmp");
	else if(s == "mv")
		system("mv ./test.cpp ./tmp");
	else if(s == "rm")
		system("rm ./tmp/impls.cpp");
	else if(s == "pwd")
		system("pwd");
	else if(s == "mkdir")
		system("mkdir tmp1");
	else if(s == "rmdir")
		system("rmdir tmp1");
	else if(s == "cd")
		system("cd ./tmp");
	return 0;
}
