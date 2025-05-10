#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <numeric>
#include <assert.h>

const std::string IMAGE_PATH = "/opt/TensorRT-8.6.1.6/data/mnist/1.pgm";

inline void readPGMFile(const std::string& fileName, uint8_t* buffer, int inH, int inW)
{
    std::ifstream infile(fileName, std::ifstream::binary);
    assert(infile.is_open() && "Attempting to read from a file that is not open.");
    std::string magic, w, h, max;
    infile >> magic >> w >> h >> max;
    infile.seekg(1, infile.cur);
    infile.read(reinterpret_cast<char*>(buffer), inH * inW);
}

int main(void)
{
    int inputH = 28;
    int inputW = 28;

    std::vector<uint8_t> fileData(inputH * inputW);
    readPGMFile(IMAGE_PATH, fileData.data(), inputH, inputW);

    // Print an ascii representation
    std::cout << "PGM:" << std::endl;
    for (int i = 0; i < inputH * inputW; i++)
    {
        std::cout << (" .:-=+*#%@"[fileData[i] / 26]) << (((i + 1) % inputW) ? "" : "\n");
    }
    std::cout << std::endl;
    
    return 0;
}