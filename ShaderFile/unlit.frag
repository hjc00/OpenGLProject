#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D mainTex;

void main()
{   
    vec4 texColor = texture(mainTex, TexCoords);
    if(texColor.a < 0.1)
        discard;
    FragColor = texColor;

}