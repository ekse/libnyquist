
#include <stddef.h>
#include <stdint.h>
#include <vector>

#include "libnyquist/Decoders.h"


using namespace nqr;

void Fuzz_Decoder(const uint8_t* data, size_t data_size)
{
    NyquistIO loader;
    AudioData fileData;
    
    std::vector<uint8_t> v;

    v.assign(data, data + data_size);

    loader.Load(&fileData, "ogg", v);
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t data_size)
{
    if (data_size < 16)
        return 0;
    
    Fuzz_Decoder(data, data_size);
    
    return 0;
}