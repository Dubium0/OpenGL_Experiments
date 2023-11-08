#version 330 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;
//layout (location = 1) in vec3 aColor; // the color variable has attribute position 1

//out vec3 ourColor; // output a color to the fragment shader

out vec3 Normal;
out vec3 FragPos;
out vec3 LightPos;
out vec2 TexCoords;
uniform vec3 lightPos;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
void main()
{

    gl_Position = projection*view*model* vec4(aPos, 1.0);
    //ourColor = aColor; // set ourColor to the input color we got from the vertex data
    FragPos = vec3(view*model* vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(view*model))) * aNormal;
    LightPos = vec3(view * vec4(lightPos, 1.0));
    TexCoords =aTexCoords;
}     