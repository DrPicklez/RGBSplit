// fragment shader

#version 150

uniform sampler2DRect sampleRed;
uniform sampler2DRect sampleGreen;
uniform sampler2DRect sampleBlue;
uniform vec2 scalar;    //dont like this
out vec4 outputColor;

void main()
{
    float a = 1.0;
    //gl_FragCoord *= scalar;
    vec4 redTex = texture(sampleRed,gl_FragCoord.xy * scalar);
    vec4 greenTex = texture(sampleGreen, gl_FragCoord.xy * scalar);
    vec4 blueTex = texture(sampleBlue, gl_FragCoord.xy * scalar);
    outputColor = vec4(redTex.r, greenTex.g, blueTex.b, a);
}
