#include "BMPParser.h"
#include <fstream>
#include <iostream>

Result parseBMP(const std::string& filename, BMPImage& image) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return Result::FileNotFound;
    }

    file.read(reinterpret_cast<char*>(&image.fileHeader), sizeof(BMPFileHeader));
    if (image.fileHeader.bfType != 0x4D42) { // 'BM' in little-endian
        std::cerr << "Error: Invalid BMP format in file " << filename << std::endl;
        return Result::InvalidFormat;
    }
    file.read(reinterpret_cast<char*>(&image.infoHeader), sizeof(BMPInfoHeader));
    if (image.infoHeader.biBitCount != 24) {
        std::cerr << "Error: Unsupported BMP bit count in file " << filename << std::endl;
        return Result::InvalidFormat;
    }

    image.pixelData.resize(image.infoHeader.biSizeImage);
    file.seekg(image.fileHeader.bfOffBits, std::ios::beg);
    file.read(reinterpret_cast<char*>(image.pixelData.data()), image.infoHeader.biSizeImage);
    file.close();
    return Result::Success; 
}

Result writeBMP(const std::string& filename, const BMPImage& image) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing" << std::endl;
        return Result::WriteError;
    }

    file.write(reinterpret_cast<const char*>(&image.fileHeader), sizeof(BMPFileHeader));
    file.write(reinterpret_cast<const char*>(&image.infoHeader), sizeof(BMPInfoHeader));
    file.seekp(image.fileHeader.bfOffBits, std::ios::beg);
    file.write(reinterpret_cast<const char*>(image.pixelData.data()), image.infoHeader.biSizeImage);
    file.close();   
    return Result::Success; 
}