#include "BMPProcessor.h"

Result changeBrightness(BMPImage& image, int delta) {
    // TODO: temporary c++ implementation, to be replaced with assembly code
    for (size_t i = 0; i < image.pixelData.size(); ++i) {
        int pixelValue = static_cast<int>(image.pixelData[i]) + delta;
        image.pixelData[i] = static_cast<uint8_t>(std::max(0, std::min(255, pixelValue)));
    }
    return Result::Success; 
}