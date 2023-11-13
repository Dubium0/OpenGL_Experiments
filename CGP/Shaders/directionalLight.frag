#version 330 core
out vec4 FragColor;  

in vec3 Normal;
in vec3 FragPos;  
in vec2 TexCoords;

struct Light { 
    vec3 direction;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct Material {
    //vec3 ambient;
    //vec3 diffuse;
    sampler2D diffuse;
    sampler2D specular;
    sampler2D emission;
    float shininess;
}; 

uniform Light lightMaterial;
uniform Material objectMaterial;
uniform vec3 viewPos;
uniform float emissionPower;
uniform float time;

void main()
{   
    // ambient light
 
    vec3 ambient = lightMaterial.ambient * vec3( texture(objectMaterial.diffuse,TexCoords));
    
    
    // diffuse light
    vec3 norm = normalize(Normal);
    vec3 lightDirection = normalize(-lightMaterial.direction);
    float diff = max(dot(norm,lightDirection),0.0);
    vec3 diffuse = diff*lightMaterial.diffuse* vec3( texture(objectMaterial.diffuse,TexCoords));
    //specular light
    
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDirection, norm); 
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), objectMaterial.shininess);
    vec3 specularMap  =vec3(texture(objectMaterial.specular,TexCoords ));
    vec3 specular = lightMaterial.specular * spec * specularMap ; 
     vec3 emission = vec3(0.0);
    if(specularMap.x !=0.0){

     emission  =vec3(texture(objectMaterial.emission,TexCoords + vec2(0.0,1.0)*time /5.0)) * emissionPower;
    }

   
   
    vec3 result = specular + ambient  + diffuse+emission;
    FragColor = vec4(result,1.0);
}