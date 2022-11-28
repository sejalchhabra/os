#include <algorithm>
#include <sys/stat.h>
#include <sys/types.h>
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv){
    if (mkdir(argv[1], 0777) == -1)
        cerr << "Error : " << strerror(errno) << endl;

    else
        cout << "Directory created\n";
}
