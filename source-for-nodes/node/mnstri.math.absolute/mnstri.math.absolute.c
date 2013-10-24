/**
 * @file
 * mnstri.math.absolute node implementation.
 *
 * @copyright Copyright © 2013 Månsteri.
 * This code may be modified and distributed under the terms of the MIT License.
 */

#include "node.h"

VuoModuleMetadata({
                     "title" : "Absolute",
                     "description" : "Absolute",
                     "keywords" : [ "math", "absolute", "abs", "modulus" ],
                     "version" : "1.0.1",
                     "node": {
                         "isInterface" : false
                     }
                 });

void nodeEvent
(
        VuoInputData(VuoReal, {"default":0.0}) inputValue,
        VuoOutputData(VuoReal) absoluteValue
)
{
    *absoluteValue = fabs(inputValue);
}
