#include <iostream>
#include <fstream>
#include <string>

std::string replaceLine(std::string line, const std::string& s1, const std::string& s2) {
    if (s1.empty())
        return line;

    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos) {
        line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
        pos += s2.length();
    }
    return line;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream infile(filename.c_str());
    if (!infile.is_open()) {
        std::cerr << "Error: cannot open input file." << std::endl;
        return 1;
    }

    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open()) {
        std::cerr << "Error: cannot create output file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) {
        outfile << replaceLine(line, s1, s2) << std::endl;
    }

    infile.close();
    outfile.close();

    return 0;
}
