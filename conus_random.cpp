#include "conus_random.hpp"

#include "Random123/philox.h"
#include "conus.hpp"


ConusUniform::ConusUniform(long lseed, int N):
    galsim::BaseDeviate(lseed), buf_len(N), buf_ptr(N) {}


void ConusUniform::fill_buff() {

    buf = std::unique_ptr<double>(
                generateRandomsCPU<double>(buf_len)
            );

    buf_ptr = 0;
}


double ConusUniform::generate1() {

    buf_ptr++;
    if (buf_ptr < buf_len) return buf.get()[buf_ptr];

    fill_buff();
}
