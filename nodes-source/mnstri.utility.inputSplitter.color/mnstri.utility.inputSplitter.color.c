/**
 * @file
 * Input Splitter node implementation.
 *
 * @copyright Copyright © 2013 Månsteri.
 * This code may be modified and distributed under the terms of the MIT License.
 */

#include "node.h"

VuoModuleDetails({
                     "name" : "Input Splitter (Color)",
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
        VuoInputData(VuoColor,{"default":{"r":1,"g":1,"b":1,"a":1}}) input,
        VuoOutputData(VuoColor) output
)
{
    *output = input;
}
