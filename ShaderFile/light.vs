#version 330 core
layout (location = 0) in vec3 position;

out vec3 ourColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 offset;

void main()
{
    gl_Position = projection * view * model * vec4((position + offset), 1.0f);
}