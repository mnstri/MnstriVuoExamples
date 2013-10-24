/**
 * @file
 * Input Splitter node implementation.
 *
 * @copyright Copyright © 2013 Månsteri.
 * This code may be modified and distributed under the terms of the MIT License.
 */

#include "node.h"

VuoModuleMetadata({
                     "title" : "Input Splitter (Image)",
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
        VuoInputData(VuoImage) inputImage,
        VuoOutputData(VuoImage) outputImage
)
{
    *outputImage = inputImage;
}
