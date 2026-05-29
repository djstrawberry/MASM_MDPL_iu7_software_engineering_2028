#include "BMPProcessor.h"

Result changeBrightness(BMPImage& image, int delta) {
    uint8_t* pixelData = image.pixelData.data();
    size_t size = image.pixelData.size();
    size_t iters = size / 32;
    size_t remainder = size % 32;

    uint8_t deltaBuffer[32];
    std::fill_n(deltaBuffer, 32, static_cast<uint8_t>(delta));

    uint8_t* ptr = pixelData;
    if (delta >= 0) {
        asm volatile (
            "vmovdqu (%2), %%ymm1\n\t"
            "1:\n\t"
            "vmovdqu (%0), %%ymm0\n\t"
            "vpaddusb %%ymm1, %%ymm0, %%ymm0\n\t"
            "vmovdqu %%ymm0, (%0)\n\t"
            "addq $32, %0\n\t"
            "decq %1\n\t"
            "jnz 1b\n\t"
            : "+r"(ptr), "+r"(iters)
            : "r"(deltaBuffer)
            : "ymm0", "ymm1", "memory"
        );
    } else {
        asm volatile (
            "vmovdqu (%2), %%ymm1\n\t"
            "1:\n\t"
            "vmovdqu (%0), %%ymm0\n\t"
            "vpsubusb %%ymm1, %%ymm0, %%ymm0\n\t"
            "vmovdqu %%ymm0, (%0)\n\t"
            "addq $32, %0\n\t"
            "decq %1\n\t"
            "jnz 1b\n\t"
            : "+r"(ptr), "+r"(iters)
            : "r"(deltaBuffer)
            : "ymm0", "ymm1", "memory"
        );
    }

    for (size_t i = 0; i < remainder; ++i)
        ptr[i] = static_cast<uint8_t>(std::min(255, std::max(0, ptr[i] + delta)));

    return Result::Success; 
}