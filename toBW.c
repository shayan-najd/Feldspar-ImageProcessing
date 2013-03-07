#include "toBW.h"
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


void toBW(struct array * v0, struct array * out)
{
    uint32_t len0;

    len0 = getLength(v0);
    initArray(out, sizeof(int32_t), len0);
    for(uint32_t v1 = 0; v1 < len0; v1 += 1)
    {
        if((at(int32_t,v0,v1) < 200))
        {
            at(int32_t,out,v1) = 1;
        }
        else
        {
            at(int32_t,out,v1) = 0;
        }
    }
}

