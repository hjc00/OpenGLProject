#version 330 core
out vec4 FragColor;


in vec4 lightClipSpacePos;
uniform sampler2D shadowMap;

float getShadow(vec4 lightClipSpacePos)
{
    vec3 ndc = lightClipSpacePos.xyz / lightClipSpacePos.w;
    ndc = ndc * 0.5 + 0.5;
    vec2 uv = ndc.xy;
    float depth = ndc.z;
    if(depth > 1.0)
    {
        return 0.0;
    }
    float shadowMapDepth = texture(shadowMap, uv).r;
    float bias = 0.0005;
    vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
    // float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.005);

    float shadow = 0;
    for(int x = -2; x <= 2; ++x)
    {
        for(int y = -2; y <= 2; ++y)
        {
            float pcfDepth = texture(shadowMap, uv + vec2(x, y) * texelSize).r; 
            shadow += depth - bias > pcfDepth ? 1.0 : 0.0;        
        }    
    }

    shadow /= 16.0;
    return shadow;
}


void main()
{   
    float shadow = getShadow(lightClipSpacePos);
    FragColor = vec4(0,0.8,0.1,1) * (1 - shadow);

}