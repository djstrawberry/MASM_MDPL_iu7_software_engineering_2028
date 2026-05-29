#ifndef BMP_PARCER_H
#define BMP_PARCER_H

#include "Result.h"
#include "BMPStruct.h"
#include <cstdint>
#include <vector>
#include <string>

Result parseBMP(const std::string& filename, BMPImage& image);
Result writeBMP(const std::string& filename, const BMPImage& image);

#endif // BMP_PARCER_H