#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec4 lightClipSpacePos;

uniform sampler2D mainTex;
uniform sampler2D shadowMap;

float getShadow(vec4 lightClipSpacePos)
{
    vec3 ndc = lightClipSpacePos.xyz / lightClipSpacePos.w;
    ndc = ndc * 0.5 + 0.5;
    vec2 uv = ndc.xy;
    float depth = ndc.z;
    float shadowMapDepth = texture(shadowMap, uv).r;
    if(shadowMapDepth > depth){
        return 0.0;
    }
    else {
        return 1.0;
    }
}

void main()
{   
    vec4 texColor = texture(mainTex, TexCoords);
    if(texColor.a < 0.1)
        discard;
    
    float shadow = getShadow(lightClipSpacePos);
    FragColor = texColor * (1 - shadow);

}