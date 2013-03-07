#include "fromColoredToBW.h"
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


void fromColoredToBW(struct array * v0, struct array * out)
{
    struct array v12 = {0};
    uint32_t len0;
    struct array v2 = {0};
    uint32_t len2;

    /* SrcLoc {srcFilename = "~/IP.hs", srcLine = 36, srcColumn = 1} (vector length) */
    len0 = (getLength(v0) / 3);
    initArray(&v12, sizeof(int32_t), 0);
    for(uint32_t v1 = 0; v1 < len0; v1 += 1)
    {
        int32_t v11;
        uint32_t v10;
        struct array e1 = {0};

        /* SrcLoc {srcFilename = "~/IP.hs", srcLine = 29, srcColumn = 1} */
        v10 = (v1 * 3);
        /* SrcLoc {srcFilename = "~/IP.hs", srcLine = 16, srcColumn = 1} */
        /* SrcLoc {srcFilename = "~/IP.hs", srcLine = 20, srcColumn = 1} */
        /* SrcLoc {srcFilename = "~/IP.hs", srcLine = 24, srcColumn = 1} */
        v11 = ((int32_t)(truncf((((((float)(at(int32_t,v0,v10))) * 0.30000001192092896f) + (((float)(at(int32_t,v0,(v10 + 1)))) * 0.5899999737739563f)) + (((float)(at(int32_t,v0,(v10 + 2)))) * 0.10999999940395355f)))));
        initArray(&e1, sizeof(int32_t), 1);
        for(uint32_t v4 = 0; v4 < 1; v4 += 1)
        {
            /* SrcLoc {srcFilename = "~/IP.hs", srcLine = 29, srcColumn = 1} */
            at(int32_t,&e1,v4) = v11;
        }
        initArray(&v2, sizeof(int32_t), (getLength(&v12) + 1));
        copyArray(&v2, &v12);
        copyArrayPos(&v2, getLength(&v12), &e1);
        initArray(&v12, sizeof(int32_t), getLength(&v2));
        copyArray(&v12, &v2);
    }
    /* SrcLoc {srcFilename = "~/IP.hs", srcLine = 36, srcColumn = 1} (vector length) */
    len2 = getLength(&v12);
    initArray(out, sizeof(int32_t), len2);
    for(uint32_t v5 = 0; v5 < len2; v5 += 1)
    {
        /* SrcLoc {srcFilename = "~/IP.hs", srcLine = 11, srcColumn = 1} (vector element) */
        /* SrcLoc {srcFilename = "~/IP.hs", srcLine = 36, srcColumn = 1} (vector element) */
        if((at(int32_t,&v12,v5) < 200))
        {
            at(int32_t,out,v5) = 1;
        }
        else
        {
            at(int32_t,out,v5) = 0;
        }
    }
    freeArray(&v12);
    freeArray(&v2);
}

