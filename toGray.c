#include "toGray.h"
#include "feldspar_c99.h"
#include "feldspar_array.h"
#include "feldspar_future.h"
#include "ivar.h"
#include "taskpool.h"
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <complex.h>


void toGray(struct array * v0, struct array * out)
{
    uint32_t len0;
    struct array v7 = {0};

    len0 = (getLength(v0) / 3);
    initArray(out, sizeof(int32_t), 0);
    for(uint32_t v6 = 0; v6 < len0; v6 += 1)
    {
        int32_t v11;
        uint32_t v10;
        struct array e1 = {0};

        v10 = (v6 * 3);
        v11 = ((int32_t)(truncf((((((float)(at(int32_t,v0,v10))) * 0.30000001192092896f) + (((float)(at(int32_t,v0,(v10 + 1)))) * 0.5899999737739563f)) + (((float)(at(int32_t,v0,(v10 + 2)))) * 0.10999999940395355f)))));
        initArray(&e1, sizeof(int32_t), 1);
        for(uint32_t v9 = 0; v9 < 1; v9 += 1)
        {
            at(int32_t,&e1,v9) = v11;
        }
        initArray(&v7, sizeof(int32_t), (getLength(out) + 1));
        copyArray(&v7, out);
        copyArrayPos(&v7, getLength(out), &e1);
        initArray(out, sizeof(int32_t), getLength(&v7));
        copyArray(out, &v7);
    }
    freeArray(&v7);
}

