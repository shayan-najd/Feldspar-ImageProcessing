#ifndef FROMCOLOREDTOBW_H
#define FROMCOLOREDTOBW_H

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


void fromColoredToBW(struct array * v0, struct array * out);


#endif // FROMCOLOREDTOBW_H
