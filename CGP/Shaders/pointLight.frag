#version 330 core
out vec4 FragColor;  

in vec3 Normal;
in vec3 FragPos;  
in vec2 TexCoords;

struct Light { 
    vec3 position;  
  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
	
    float constant;
    float linear;
    float quadratic;
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


void main()
{   
    // ambient light
 
    vec3 ambient = lightMaterial.ambient * texture(objectMaterial.diffuse,TexCoords).rgb;
 
    
    // diffuse light
    vec3 norm = normalize(Normal);
    vec3 lightDirection = normalize( lightMaterial.position - FragPos);
    float diff = max(dot(norm,lightDirection),0.0);
    vec3 diffuse = diff*lightMaterial.diffuse* texture(objectMaterial.diffuse,TexCoords).rgb;
    //specular light
    
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDirection, norm); 
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), objectMaterial.shininess);
    vec3 specularMap  =texture(objectMaterial.specular,TexCoords ).rgb;
    vec3 specular = lightMaterial.specular * spec * specularMap ;
    

   
    float _distance    = length(lightMaterial.position - FragPos);
    float attenuation = 1.0 / (lightMaterial.constant + lightMaterial.linear * _distance + lightMaterial.quadratic * (_distance * _distance));   

    diffuse  *= attenuation;
    specular *= attenuation;  
 
    vec3 result = specular + ambient  + diffuse  ;
    FragColor = vec4(result,1.0);
}