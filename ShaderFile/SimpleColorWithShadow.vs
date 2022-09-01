#version 330 core
layout (location = 0) in vec3 aPos;

out vec4 lightClipSpacePos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 lightSpaceVP;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    lightClipSpacePos = lightSpaceVP *  model * vec4(aPos, 1.0);
}