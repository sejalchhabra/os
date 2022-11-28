#include <iostream>		
#include <fstream>		
#include <iomanip>		
using namespace std;

int main(int argc, char **argv){
	ifstream file(argv[1]);			// (a)

	int	chars = 0;				// (b)
	int	lines = 1;
	int	words = 0;
	bool	in_word = false;
	int	c;

	while ((c = file.get()) != EOF){
		chars++;				// (e)

		switch (c){				// (f)
			case '\n':			// (g)
				lines++;
			case ' ':			// (h)
			case '\t':
				in_word = false;
				break;
			default:			// (i)
				if (! in_word)		// (j)
				{
					in_word = true;
					words++;
				}
				break;
		}
	}
	cout << setw(8) << lines << " Lines" <<
		setw(8) << words << " Words" <<
		setw(8) << chars << " Characters" <<endl;

	return 0;
}
