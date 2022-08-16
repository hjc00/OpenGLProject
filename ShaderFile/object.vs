#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

out vec3 Normal;  // 输出Normal法向量给片段着色器使用
out vec3 FragPos;  // 顶点在世界空间的位置，输出给片段着色器求出光线的方向
out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0f);
    FragPos = vec3(model * vec4(position, 1.0f));
    Normal = mat3(transpose(inverse(model))) * normal;
    TexCoords = texCoords;
}