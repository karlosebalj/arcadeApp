/*
 * Utils.h
 *
 *  Created on: Mar. 10, 2023
 *      Author: Schelby5
 */

#include "Utils.h"
#include <cmath>

bool IsEqual(float x, float y) {
    return fabsf(x-y) < EPSILON;
}

bool IsGreaterThanOrEqual(float x, float y) {
    return x > y || IsEqual(x, y);
}

bool IsLessThanOrEqual(float x, float y) {
    return x < y || IsEqual(x, y);
}


