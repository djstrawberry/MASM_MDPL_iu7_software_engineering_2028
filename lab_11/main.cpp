#include "BMPParser.h"
#include "BMPProcessor.h"
#include "Result.h"

static Result checkArgs(int argc);

int main(int argc, char **argv) {
    Result ec = checkArgs(argc);
    if (ec != Result::Success) return static_cast<int>(ec);

    BMPImage image;
    ec = parseBMP(argv[1], image);
    if (ec != Result::Success) return static_cast<int>(ec);

    int brightnessDelta = std::stoi(argv[3]);
    ec = changeBrightness(image, brightnessDelta);
    if (ec != Result::Success) return static_cast<int>(ec);

    ec = writeBMP(argv[2], image);
    if (ec != Result::Success) return static_cast<int>(ec);
    return 0;
}

static Result checkArgs(int argc) {
    if (argc != 4)
        return Result::InvalidFormat;
    return Result::Success;
}