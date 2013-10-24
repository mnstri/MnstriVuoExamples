/**
 * @file
 * Input Splitter node implementation.
 *
 * @copyright Copyright © 2013 Månsteri.
 * This code may be modified and distributed under the terms of the MIT License.
 */

#include "node.h"

VuoModuleDetails({
                     "name" : "Input Splitter (3D Point)",
                     "description" : "Splits input port to multiple output cables.",
                     "keywords" : [ "input splitter" ],
                     "version" : "1.0.0",
                     "dependencies" : [ ],
					 "node": {
						 "isInterface" : false
					 }
				 });

void nodeEvent
(
        VuoInputData(VuoPoint3d, {"default":{"x":0, "y":0, "z":0}}) input,
        VuoOutputData(VuoPoint3d) output
)
{
    *output = input;
}
