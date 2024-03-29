// vertex shader

#version 150

uniform mat4 modelViewProjectionMatrix;
//uniform vec2 scalar;

in vec4 position;


void main(){
    gl_Position = modelViewProjectionMatrix * position;
}
