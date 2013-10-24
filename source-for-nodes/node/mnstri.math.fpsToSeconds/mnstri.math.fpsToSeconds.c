/**
 * @file
 * mnstri.math.bpmToseconds node implementation.
 *
 * @copyright Copyright © 2013 Månsteri.
 * This code may be modified and distributed under the terms of the MIT License.
 */

#include "node.h"

VuoModuleMetadata({
    "title" : "FPS to Seconds",
    "description" : "Converts an FPS (Frames Per Second) value to a number you can feed to the Fire Periodically node.",
    "keywords" : [ "fps", "metro" ],
    "version" : "1.0.0",
    "node": {
        "isInterface" : false
    }
});

void nodeEvent
(
        VuoInputData(VuoReal, {"default":60.0}) fps,
        VuoOutputData(VuoReal) seconds
 )
{
    *seconds = 1/fps;
}
