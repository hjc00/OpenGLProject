#version 330 core
in vec3 Normal;  
in vec3 FragPos;  
in vec2 TexCoords; 

out vec4 color;

struct Material
{
    sampler2D diffuse;
    sampler2D specular;
    sampler2D emit;
    float shininess;
};

uniform Material material;
uniform vec3 viewPos; 

struct DirLight{
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
uniform DirLight dirLight;

/////////////////////////////////////////////////////////
struct PointLight{
    vec3 position;
    float constant;
    float linear;
    float quadratic;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
#define NUM_OF_POINT_LIGHT 4
uniform PointLight pointLights[NUM_OF_POINT_LIGHT];
/////////////////////////////////////////////////////////
struct SpotLight{
    vec3 position;
    vec3 spotDir;
    float cutOff;
    float outerCutOff;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
uniform SpotLight spotLight;
/////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////
vec3 getDirLight(DirLight light,vec3 norm, vec3 viewDir){

    vec3 lightDir = normalize(-light.direction);

    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
        
    // Diffuse       
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));  
        
    // Specular
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));

    return ambient + diffuse + specular;
}

vec3 getPointLight(PointLight light,vec3 norm,vec3 viewDir){  // todo 优化代码
 
    // return ambient + diffuse + specular;
    vec3 lightDir = normalize(light.position - FragPos);
    // 漫反射着色
    float diff = max(dot(norm, lightDir), 0.0);
    // 镜面光着色
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // 衰减
    float distance    = length(light.position - FragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + 
                 light.quadratic * (distance * distance));    
    // 合并结果
    vec3 ambient  = light.ambient  * vec3(texture(material.diffuse, TexCoords));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.diffuse, TexCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
    
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}

vec3 getSpotLight(SpotLight light, vec3 viewPos){
    vec3 lightDir = normalize(light.position - FragPos);
    float theta = dot(lightDir, normalize(-light.spotDir));
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff) / epsilon,0.0, 1.0);

     vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords));
        
    // Diffuse 
    vec3 norm = normalize(Normal);        
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));  
    
    // Specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));

    diffuse *= intensity;
    specular *= intensity;
      
    return ambient + diffuse + specular;
}

float near = 0.1; 
float far  = 100.0; 

float LinearizeDepth(float depth) 
{
    float z = depth * 2.0 - 1.0; // back to NDC 
    return (2.0 * near * far) / (far + near - z * (far - near));    
}

void main()
{
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);

    vec3 result;
    result = getDirLight(dirLight,norm,viewDir);

    for(int i = 0;i < NUM_OF_POINT_LIGHT;i++){
         result += getPointLight(pointLights[i],norm,viewDir);
    }
    result += getSpotLight(spotLight,viewPos);

    color = vec4(result,1.0);
    //color = vec4(vec3(gl_FragCoord.z), 1.0);

}