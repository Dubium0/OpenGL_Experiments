#version 330 core
out vec4 FragColor;  

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;

struct DirLight{
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight{
    vec3 position;
    
    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
#define NR_POINT_LIGHTS 2

struct SpotLight{
    vec3 position;
    vec3 direction;

    float cutOff;
    float outerCutOff;
    
    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;


};


struct Material{
    sampler2D diffuse0;
    sampler2D specular0;
    
    float shininess;

};
uniform DirLight directionalLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform SpotLight spotLight;
uniform Material material;
uniform vec3 viewPos;

vec3 CalcDirLight( DirLight ligth,vec3 normal, vec3 viewDir){

    vec3 lightDir = normalize(-ligth.direction);
    //diffuse
    float diff = max(dot(normal, lightDir),0.0);
    //specular
    vec3 reflectDir = reflect(-lightDir,normal);
    float spec = pow(max(dot(viewDir, reflectDir),0.0),material.shininess);
    // combination
    vec3 ambient =ligth.ambient * texture(material.diffuse0, TexCoords).rgb;
    vec3 diffuse =ligth.diffuse * diff *texture(material.diffuse0, TexCoords).rgb;
    vec3 specular =ligth.specular * spec*texture(material.specular0, TexCoords).rgb;

    return (ambient + diffuse + specular);

}


vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir) {
    vec3 lightDir= normalize( light.position - fragPos);
    // diffuse
    float diff = max(dot(normal, lightDir),0.0);
    // specular
    vec3 reflectDir= reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir),0.0),material.shininess);
    // attenuation
    float distance_  = length(light.position - fragPos);
    float attenuation = 1.0 /
                       (light.constant + light.linear * distance_ + light.quadratic*(distance_*distance_));
    // combination
    vec3 ambient = light.ambient * texture(material.diffuse0,TexCoords).rgb;
    vec3 diffuse = light.diffuse * diff *texture(material.diffuse0,TexCoords).rgb;
    vec3 specular = light.specular * spec *texture(material.specular0,TexCoords).rgb;
    
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return (ambient + diffuse + specular);

}

vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir) {
    vec3 lightDir= normalize( light.position - fragPos);
    // diffuse
    float diff = max(dot(normal, lightDir),0.0);
    // specular
    vec3 reflectDir= reflect(-lightDir, normal); 
    float spec = pow(max(dot(viewDir, reflectDir),0.0),material.shininess);
    // attenuation
    float distance_  = length(light.position - fragPos);
    float attenuation = 1.0 /
                       (light.constant + light.linear * distance_ + light.quadratic*(distance_*distance_));
    // cut off
    float theta = dot(lightDir, normalize(-light.direction)); 
    float epsilon = (light.cutOff- light.outerCutOff);
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0,1.0);
    // combination
    vec3 ambient = light.ambient * texture(material.diffuse0,TexCoords).rgb;
    vec3 diffuse = light.diffuse * diff *texture(material.diffuse0,TexCoords).rgb;
    vec3 specular = light.specular * spec *texture(material.specular0,TexCoords).rgb;


    ambient *= attenuation*intensity;
    diffuse *= attenuation *intensity;
    specular *= attenuation *intensity;

    return (ambient + diffuse + specular);

}

void main()
{   
    
    vec3 norm = normalize(Normal);
    vec3 viewDir= normalize(viewPos - FragPos);

    // directional
    vec3 result = CalcDirLight(directionalLight,norm,viewDir);
    // point lights

    for(int i = 0; i< NR_POINT_LIGHTS; i++) {
        result += CalcPointLight(pointLights[i],norm,FragPos,viewDir);
    }
    // spot light
    result += CalcSpotLight(spotLight,norm,FragPos,viewDir);
  
    FragColor =  vec4(result,1.0);

}


