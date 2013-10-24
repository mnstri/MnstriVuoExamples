/**
 * @file
 * mnstri.math.modulo node implementation.
 *
 * @copyright Copyright © 2013 Månsteri.
 * This code may be modified and distributed under the terms of the MIT License.
 */

#include "node.h"

VuoModuleDetails({
                     "name" : "Modulo",
                     "description" : "Modulo",
                     "keywords" : [ "math", "modulo", "%" ],
                     "version" : "1.0.0",
                     "node": {
                         "isInterface" : false
                     }
                 });

void nodeEvent
(
        VuoInputData(VuoInteger, {"default":0}) a,
        VuoInputData(VuoInteger, {"default":0}) b,
        VuoOutputData(VuoInteger) modulo
)
{
    *modulo = a % b;
}
