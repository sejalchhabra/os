#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
#endif

#include <fstream>
#include <iomanip>
#include <signal.h>
using namespace std;

void _ls(const char *dir,int op_a,int op_l)
{
	struct dirent *d;
	DIR *dh = opendir(dir);
	if (!dh)
	{
		if (errno = ENOENT)
		{
			perror("Directory doesn't exist");
		}
		else
		{
			perror("Unable to read directory");
		}
		exit(EXIT_FAILURE);
	}
	while ((d = readdir(dh)) != NULL)
	{
		if (!op_a && d->d_name[0] == '.')
			continue;
		printf("%s  ", d->d_name);
		if(op_l) printf("\n");
	}
	if(!op_l)
	printf("\n");
}

string GetCurrentWorkingDir( void ) {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  string current_working_dir(buff);
  return current_working_dir;
}

int main(int argc, char *argv[]){
    switch(atoi(argv[1])){
        case 1: if (argc == 2) //ls
                _ls(".",0,0);
            else{
                if (argv[2][0] == '-')
                {
                    int op_a = 0, op_l = 0;
                    char *p = (char*)(argv[1] + 1);
                    while(*p){
                        if(*p == 'a') op_a = 1;
                        else if(*p == 'l') op_l = 1;
                        else{
                            perror("Option not available");
                            exit(EXIT_FAILURE);
                        }
                        p++;
                    }
                    _ls(".",op_a,op_l);
                }
            }
        break;
        case 2: cout << GetCurrentWorkingDir() << endl; //pwd
        break;
        case 3: for(int i = 2; i < argc; i++)  //cat
            {
                ifstream file(argv[i]);
                if(file.fail())
                {
                    cerr << "Error opening file.\n";
                    return 1;
                }
                string tp;
                while(getline(file,tp))
                    cout << tp<<endl;
                file.close();
            }
        break;
        case 4: {ifstream file("linux_commands.c"); //wc
            if (argc == 3){
                file.close();
                ifstream file(argv[2]);
            }
            int	chars = 0;
	    int	lines = 1;
            int	words = 0;
            bool in_word = false;
            int	c;
            while ((c = file.get()) != EOF)
            {
                chars++;
                switch (c)
                {
                    case '\n':
                        lines++;
                    case ' ':
                    case '\t':
                        in_word = false;
                        break;
                    default:
                        if (!in_word)
                        {
                            in_word = true;
                            words++;
                        }
                        break;
                }
            }
            file.close();
            cout << setw(8) << lines << setw(8) << words << setw(8) << chars << endl;
        }
        break;
        case 5: {int del = remove("textFile.txt");       //rm
            if (!del)
                printf("The file is Deleted successfully\n");
            else
                printf("the file is not Deleted\n");
        }
        break;
        case 6: {pid_t retVal;                          //kill
            retVal = fork();
            if(retVal > 0){
                int i = 0;
                while(i++ < 5){
                    printf("in the parent process.\n");
                    sleep(1);
                }
                kill(retVal, SIGKILL);
            } else if (retVal == 0){
                int i = 0;
                while(i++ < 15){
                    printf("In the child process.\n");
                    sleep(1);
                }
            } else {
                printf("Something bad happened.");
                exit(EXIT_FAILURE);
            }
        }
        break;
	}
	return 0;
}
