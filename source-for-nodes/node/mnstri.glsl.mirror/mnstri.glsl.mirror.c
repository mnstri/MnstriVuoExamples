/**
 * @file
 * mnstri.glsl.mirror node implementation.
 *
 * @copyright Copyright © 2014 Månsteri.
 * This code may be modified and distributed under the terms of the MIT License.
 * Based on https://www.shadertoy.com/view/XdSGD3 by asalga
 */

#include "node.h"

#include "VuoImageRenderer.h"

VuoModuleMetadata({
                     "title" : "Mirror",
                     "description" : "Mirror effect",
					 "keywords" : [ ],
					 "version" : "1.0.0",
					 "dependencies" : [
						 "VuoImageRenderer"
					 ],
					 "node": {
						 "isInterface" : false
					 }
				 });

#include "node.h"

static const char * fragmentShaderSource = VUOSHADER_GLSL_SOURCE(120,
	// Inputs
	uniform sampler2D texture;
    uniform float mirrorMode;
    uniform vec2 resolution;
	varying vec4 fragmentTextureCoordinate;

	void main()
	{
        //vec4 frag = texture2D(texture, fragmentTextureCoordinate.xy);

        vec2 p = gl_FragCoord.xy/resolution.xy;

            // No Mirror
            // mirrorMode == 0

            // Left Mirror
            if(mirrorMode == 1){
                p.x -= step(0.5, p.x) * (p.x-0.5) * 2.0;
            }

            // Right Mirror
            if(mirrorMode == 2){
                p.x += step(p.x, 0.5) * (0.5-p.x) * 2.0;
            }

            // Top Mirror
            if(mirrorMode == 3){
                p.y -= step(p.y, 0.5) * (p.y-.5) * 2.0;
            }

            // Bottom Mirror
            if(mirrorMode == 4){
                p.y += step(0.5, p.y) * (0.5-p.y) * 2.0;
            }

            // Quad Mirror
            if(mirrorMode == 5){
                p.x += step(p.x, 0.5) * (0.5-p.x) * 2.0;
                p.y += step(0.5, p.y) * (0.5-p.y) * 2.0;
            }

            gl_FragColor = texture2D(texture, p);

	}
);


struct nodeInstanceData
{
	VuoShader shader;
	VuoGlContext glContext;
	VuoImageRenderer imageRenderer;
};

struct nodeInstanceData * nodeInstanceInit(void)
{
	struct nodeInstanceData * instance = (struct nodeInstanceData *)malloc(sizeof(struct nodeInstanceData));
	VuoRegister(instance, free);

	instance->glContext = VuoGlContext_use();

    instance->shader = VuoShader_make("GLSL Mirror", VuoShader_getDefaultVertexShader(), fragmentShaderSource);
	VuoRetain(instance->shader);

	instance->imageRenderer = VuoImageRenderer_make(instance->glContext);
	VuoRetain(instance->imageRenderer);

	return instance;
}

void nodeInstanceEvent
(
		VuoInstanceData(struct nodeInstanceData *) instance,
		VuoInputData(VuoImage) image,
        VuoInputData(VuoInteger, {"default":1,"suggestedMin":0,"suggestedMax":5,"suggestedStep":1}) mirrorMode,
        //VuoInputData(VuoPoint2d, {"default":{"x":512.0,"y":512.0},"suggestedStep":{"x":1.0,"y":1.0}}) resolution,

		VuoOutputData(VuoImage) adjustedImage
)
{
	if (! image)
		return;

	// Associate the input image with the shader.
	VuoShader_resetTextures((*instance)->shader);
	VuoShader_addTexture((*instance)->shader, (*instance)->glContext, "texture", image);

	// Feed parameters to the shader.
    VuoShader_setUniformFloat((*instance)->shader, (*instance)->glContext, "mirrorMode", mirrorMode);
    //VuoShader_setUniformPoint2d((*instance)->shader, (*instance)->glContext, "resolution", resolution);
    VuoShader_setUniformPoint2d((*instance)->shader, (*instance)->glContext, "resolution", VuoPoint2d_make(image->pixelsWide, image->pixelsHigh));
    //VuoShader_setUniformFloat((*instance)->shader, (*instance)->glContext, "green", green);
    //VuoShader_setUniformFloat((*instance)->shader, (*instance)->glContext, "blue", blue);

	// Render.
	*adjustedImage = VuoImageRenderer_draw((*instance)->imageRenderer, (*instance)->shader, image->pixelsWide, image->pixelsHigh);
}

void nodeInstanceFini(VuoInstanceData(struct nodeInstanceData *) instance)
{
	VuoRelease((*instance)->shader);
	VuoRelease((*instance)->imageRenderer);
	VuoGlContext_disuse((*instance)->glContext);
}
