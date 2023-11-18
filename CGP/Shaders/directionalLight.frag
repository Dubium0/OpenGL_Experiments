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
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    sampler2D diffuse0;
    sampler2D specular0;
    
    float shininess;
}; 

uniform Light lightMaterial;
uniform Material material;
uniform vec3 viewPos;
uniform bool isColorShading;

void main()
{   
    if(isColorShading){
         // ambient light
 
        vec3 ambient = lightMaterial.ambient *  material.ambient;
    
    
        // diffuse light
        vec3 norm = normalize(Normal);
        vec3 lightDirection = normalize(-lightMaterial.direction);
        float diff = max(dot(norm,lightDirection),0.0);
        vec3 diffuse = diff*lightMaterial.diffuse* material.diffuse;
        //specular light
    
        vec3 viewDir = normalize(viewPos - FragPos);
        vec3 reflectDir = reflect(-lightDirection, norm); 
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
        vec3 specularMap  =material.specular;
        vec3 specular = lightMaterial.specular * spec * specularMap ;
    

    
   
        vec3 result = specular + ambient  + diffuse;
        FragColor = vec4(result,1.0);





    
    }else{
        // ambient light
 
        vec3 ambient = lightMaterial.ambient * vec3( texture(material.diffuse0,TexCoords));
    
    
        // diffuse light
        vec3 norm = normalize(Normal);
        vec3 lightDirection = normalize(-lightMaterial.direction);
        float diff = max(dot(norm,lightDirection),0.0);
        vec3 diffuse = diff*lightMaterial.diffuse* vec3( texture(material.diffuse0,TexCoords));
        //specular light
    
        vec3 viewDir = normalize(viewPos - FragPos);
        vec3 reflectDir = reflect(-lightDirection, norm); 
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
        vec3 specularMap  =vec3(texture(material.specular0,TexCoords ));
        vec3 specular = lightMaterial.specular * spec * specularMap ;
    

    
   
        vec3 result = specular + ambient  + diffuse;
        FragColor = vec4(result,1.0);
    }
}