#version 330 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec3 aNormal;
//layout (location = 1) in vec3 aColor; // the color variable has attribute position 1

//out vec3 ourColor; // output a color to the fragment shader

out vec3 Color;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main()
{

    gl_Position = projection*view*model* vec4(aPos, 1.0);
    //ourColor = aColor; // set ourColor to the input color we got from the vertex data
    vec3 FragPos = vec3(view*model* vec4(aPos, 1.0));
    vec3 Normal = mat3(transpose(inverse(view*model))) * aNormal;
    vec3 LightPos = vec3(view * vec4(lightPos, 1.0));

    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength* lightColor;
    // normalizing vectors
    vec3 norm = normalize(Normal);
    vec3 lightDirection = normalize(lightPos-FragPos);
    // diffuse light
    float diff = max(dot(norm,lightDirection),0.0);
    vec3 diffuse = diff* lightColor;
    //specular light
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDirection, norm); 
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 256);
    vec3 specular = specularStrength * spec * lightColor;  

    Color = (specular+ambient + diffuse) * objectColor;

}     