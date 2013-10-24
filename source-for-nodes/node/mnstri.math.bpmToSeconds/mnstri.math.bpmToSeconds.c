/**
 * @file
 * mnstri.math.bpmToSeconds node implementation.
 *
 * @copyright Copyright © 2013 Månsteri.
 * This code may be modified and distributed under the terms of the MIT License.
 */

#include "node.h"

VuoModuleMetadata({
                "title" : "BPM to Seconds",
                "description" : "Converts a BPM (Beats Per Minute) value to a number you can feed to the Fire Periodically node.",
                "keywords" : [ "bpm", "metro" ],
                "version" : "1.0.0",
                "node": {
                "isInterface" : false
                }
            });

void nodeEvent
(
        VuoInputData(VuoReal, {"default":120.0}) bpm,
        VuoOutputData(VuoReal) seconds
 )
{
    *seconds = 60/bpm;
}
