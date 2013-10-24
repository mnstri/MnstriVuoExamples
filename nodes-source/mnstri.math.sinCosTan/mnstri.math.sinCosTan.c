/**
 * @file
 * mnstri.math.sinCosTan node implementation.
 *
 * @copyright Copyright © 2013 Månsteri.
 * This code may be modified and distributed under the terms of the MIT License.
 */

#include "node.h"

VuoModuleDetails({
    "name" : "Sin Cos Tan",
    "description" : "Sin Cos Tan",
    "keywords" : [ "math", "sin", "cos", "tan" ],
    "version" : "1.0.0",
    "node": {
        "isInterface" : false
    }
});

void nodeEvent
(
        VuoInputData(VuoReal, {"default":0.0}) input,
        VuoOutputData(VuoReal) s,
        VuoOutputData(VuoReal) c,
        VuoOutputData(VuoReal) t
 )
{
    *s = sin(input);
    *c = cos(input);
    *t = tan(input);
}
