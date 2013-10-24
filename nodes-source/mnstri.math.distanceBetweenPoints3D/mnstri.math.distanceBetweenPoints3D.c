/**
 * @file
 * test.vuoize node implementation.
 *
 * @copyright Copyright © 2012–2013 Kosada Incorporated.
 * This code may be modified and distributed under the terms of the MIT License.
 * For more information, see http://vuo.org/license.
 */

#include "node.h"

VuoModuleDetails({
                     "name" : "Distance Between Points 3D",
                     "description" : "Calculates the distance between two points.",
                     "keywords" : ["math", "distance"],
					 "version" : "1.0.0",
					 "dependencies" : [ ],
					 "node": {
						 "isInterface" : false
					 }
				 });

void nodeEvent
(
        VuoInputData(VuoReal, {"default":0.0}) x1,
        VuoInputData(VuoReal, {"default":0.0}) y1,
        VuoInputData(VuoReal, {"default":0.0}) z1,
        VuoInputData(VuoReal, {"default":0.0}) x2,
        VuoInputData(VuoReal, {"default":0.0}) y2,
        VuoInputData(VuoReal, {"default":0.0}) z2,
        VuoOutputData(VuoReal) distance
)
{
    *distance = sqrt (((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) + ((z2-z1)*(z2-z1)));
}
