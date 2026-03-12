#include <iostream>
#include <fstream>
#include <string>

static bool replaceLine(std::string &line, const std::string &from, const std::string &to)
{
    bool changed = false;
    std::size_t pos = 0;

    while ((pos = line.find(from, pos)) != std::string::npos)
    {
        line.erase(pos, from.length());
        line.insert(pos, to);
        pos += to.length();
        changed = true;
    }

    return changed;
}

int main(int ac, char *av[])
{
    if (ac != 4)
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    const std::string filename = av[1];
    const std::string s1 = av[2];
    const std::string s2 = av[3];

    if (filename.empty())
    {
        std::cerr << "Error: filename is empty." << std::endl;
        return 2;
    }

    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return 3;
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: could not open input file." << std::endl;
        return 4;
    }

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: could not create output file." << std::endl;
        return 5;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        replaceLine(line, s1, s2);
        outputFile << line;
        if (!inputFile.eof())
            outputFile << std::endl;
    }

    return 0;
}
