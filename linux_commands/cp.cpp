#include <iostream>
#include <fstream>
#include <cstdio>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Usage: moderncp srcfile destfile\n";
        return 1;
    }
    std::ifstream in{argv[1]};
    std::remove(argv[2]);
    std::ofstream out{argv[2]};
    if (!out) {
        std::cerr << "Could not create output file " << argv[2] << '\n';
        return 1;
    }
    static constexpr std::size_t buffsize{1024};
    char buffer[buffsize];
    while (in.read(buffer, buffsize)) {
        out.write(buffer, buffsize);
    }
    out.write(buffer, in.gcount());
}
