#include "LightingExperiments.h"

LightingExperiments::LightingExperiments() {
    float vertices[] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
    };
    cubePositions = {
        glm::vec3(0.0f,  0.0f,  0.0f),
        glm::vec3(0.0f,  0.0f, 0.0f),
       
    };
    camera = new Camera();
 
    lightMaterial = new Material("Shaders/unlitShader.vert", "Shaders/unlitShader.frag");
   
    // set up light source
    lightColor = glm::vec3(1.0f, 1.0f, 1.0f);

    lightMaterial->SetMaterialAttribute("color", lightColor,S_VEC3);



    //------------------
    // set up lit object
  
    litMaterial = new Material("Shaders/litShader.vert", "Shaders/litShader.frag");

    glm::vec3 objectColor(0.5f, 0.5f, 0.0f);
    glm::vec3 lightColor(1.0f, 1.0f, 1.0f);

    litMaterial->SetMaterialAttribute("lightPos", cubePositions[0],S_VEC3);
    
 
    glm::vec3 ambientColor(0.2f, 0.2f, 0.2f);

    litMaterial->SetMaterialAttribute("lightMaterial.ambient", ambientColor,S_VEC3);

    litMaterial->SetMaterialAttribute("lightMaterial.diffuse", lightColor,S_VEC3);

    glm::vec3 specularColor(1.0f, 1.0f, 1.0f);

    litMaterial->SetMaterialAttribute("lightMaterial.specular", specularColor,S_VEC3);

  

    litMaterial->SetMaterialAttribute("objectMaterial.shininess", 32.0f,S_FLOAT);
    litMaterial->SetMaterialAttribute("emissionPower", 0.0f, S_FLOAT);
    litMaterial->SetMaterialAttribute("time", 0.0f,S_FLOAT);




    litMaterial->AddTexture("objectMaterial.diffuse", "External/Textures/diffuse.png", GL_REPEAT, GL_NEAREST);

    litMaterial->AddTexture("objectMaterial.specular", "External/Textures/specular.png", GL_REPEAT, GL_NEAREST);
    
    litMaterial->AddTexture("objectMaterial.emission", "External/Textures/emission.jpg", GL_REPEAT, GL_NEAREST);

  

    renderer = new Renderer(vertices, sizeof(vertices));
   
}

LightingExperiments::~LightingExperiments() {

    delete renderer;
    delete lightMaterial;
    delete litMaterial;
    delete camera;

}

void LightingExperiments::OnRender() {
    float t = static_cast<float>(glfwGetTime());
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

   
    lightMaterial->SetMaterialAttribute("color", lightColor,S_VEC3);

    model = glm::mat4(1.0f);
    glm::vec3 deltaLightPos =  glm::vec3(cos(t),0.0f, sin(t))*2.0f + cubePositions[0];
    model = glm::translate(model, deltaLightPos);
    model = glm::scale(model, glm::vec3(0.3f));
 
    lightMaterial->SetMaterialAttribute("model", model,S_MAT4);
    
    
    renderer->Render(*lightMaterial,*camera);
   
    
    
    //draw lit object



    litMaterial->SetMaterialAttribute("viewPos", camera->Position, S_VEC3);
    litMaterial->SetMaterialAttribute("lightPos", deltaLightPos,S_VEC3);



    litMaterial->SetMaterialAttribute("lightMaterial.diffuse", lightColor,S_VEC3);
    litMaterial->SetMaterialAttribute("emissionPower", (sin(t * 5.0f) + 1.0f) / 2.0f + 0.1f,S_FLOAT);
    litMaterial->SetMaterialAttribute("time", t,S_FLOAT);
    
    model = glm::mat4(1.0f);
    model = glm::translate(model, cubePositions[1]);
 
    litMaterial->SetMaterialAttribute("model", model,S_MAT4);
    //renderer->ChangeMaterialTarget(litMaterial);
    renderer->Render(*litMaterial, *camera);
  



}




// call Back function set up
void LightingExperiments::MouseCallBack(GLFWwindow* window, double xposIn, double yposIn, float deltaTime) {
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {

        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera->ProcessMouseMovement(xoffset, yoffset);

}

void LightingExperiments::MouseScrollCallBack(GLFWwindow* window, double xoffset, double yoffset, float deltaTime) {
    camera->ProcessMouseScroll(static_cast<float>(yoffset));

}

void LightingExperiments::KeyboardInputCallBack(GLFWwindow* window, float deltaTime) {



    if (glfwGetKey(window, GLFW_KEY_W))
        camera->ProcessKeyboard(FORWARD, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_S))
        camera->ProcessKeyboard(BACKWARD, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_A))
        camera->ProcessKeyboard(LEFT, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_D))
        camera->ProcessKeyboard(RIGHT, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_Q))
        camera->ProcessKeyboard(UPWARD, deltaTime);

    if (glfwGetKey(window, GLFW_KEY_E))
        camera->ProcessKeyboard(DOWNWARD, deltaTime);

}