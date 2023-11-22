#include "SpotLightTest.h"


SpotLightTest::SpotLightTest() :camera(new Camera()), renderer(nullptr), litObjectsMat(nullptr) {

    // cube vertex data
    float vertices[] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };
    //set the view and projection matrix
    view = camera->GetViewMatrix();
    projection = glm::perspective(glm::radians(camera->Zoom), 800.0f / 600.0f, 0.1f, 100.0f);
    // set object positions
    litObjectPosition = {
        // left 
        glm::vec3(-10.0f,0.0f,0.0f),
        // glm::vec3(-5.0f,0.0f,-2.0f),
       ////  glm::vec3(-5.0f,0.0f,0.0f),
        // glm::vec3(-5.0f,0.0f,4.0f),
        // glm::vec3(-5.0f,0.0f,2.0f),

         //right
        // glm::vec3(5.0f,0.0f,-4.0f),
       //  glm::vec3(5.0f,0.0f,-2.0f),
        // glm::vec3(5.0f,0.0f,0.0f),
        // glm::vec3(5.0f,0.0f,4.0f),
        // glm::vec3(5.0f,0.0f,2.0f)
    };
   
    //-----------------------------------------------------------------------------------------------------------
  
    // create and setup lit object material

    litObjectsMat = new Material("Shaders/spotlight.vert", "Shaders/spotlight.frag");
    model = glm::mat4(1.0f);
    litObjectsMat->SetMaterialAttribute("model", model, S_MAT4);
    litObjectsMat->SetMaterialAttribute("view", view, S_MAT4);
    litObjectsMat->SetMaterialAttribute("projection", projection, S_MAT4);

    litObjectsMat->AddTexture("material.diffuse", "External/Textures/diffuse.png", GL_REPEAT, GL_NEAREST);
    litObjectsMat->AddTexture("material.specular", "External/Textures/specular.png", GL_REPEAT, GL_NEAREST);
    litObjectsMat->SetMaterialAttribute("material.shininess",32.0f,S_FLOAT);
   // litObjectsMat->SetMaterialAttribute("lightMaterial.position", lightPos, S_VEC3);
    glm::vec3 lightAmbientColor(0.3f, 0.3f, 0.3f);
    glm::vec3 lightDiffuseColor(0.9f, 0.9f, 0.9f);
    glm::vec3 lightSpecularColor(1.0f, 1.0f, 1.0f);

    litObjectsMat->SetMaterialAttribute("light.ambient", lightAmbientColor, S_VEC3);
    litObjectsMat->SetMaterialAttribute("light.diffuse", lightDiffuseColor, S_VEC3);
    litObjectsMat->SetMaterialAttribute("light.specular", lightSpecularColor, S_VEC3);

    litObjectsMat->SetMaterialAttribute("light.constant", 1.0f, S_FLOAT);
    litObjectsMat->SetMaterialAttribute("light.linear", 0.09f, S_FLOAT);
    litObjectsMat->SetMaterialAttribute("light.quadratic", 0.032f, S_FLOAT);

    litObjectsMat->SetMaterialAttribute("light.direction", camera->Front, S_VEC3);
    litObjectsMat->SetMaterialAttribute("light.position", camera->Position, S_VEC3);
   
    litObjectsMat->SetMaterialAttribute("light.cutOff", glm::cos(glm::radians(12.5f)), S_FLOAT);
    litObjectsMat->SetMaterialAttribute("light.outerCutOff", glm::cos(glm::radians(17.5f)), S_FLOAT);
    litObjectsMat->SetMaterialAttribute("viewPos", camera->Position, S_VEC3);

    // init renderer

    renderer = new Renderer(vertices, sizeof(vertices));



}

SpotLightTest::~SpotLightTest() {
    delete renderer;
    delete camera;
    delete litObjectsMat;
  

}



void SpotLightTest::OnRender(int w, int h) {
    float t = static_cast<float>(glfwGetTime());

    glClearColor(0.28f, 0.28f, 0.28f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

  
    //set light pos 
    //litObjectsMat->SetMaterialAttribute("lightMaterial.position", lightPos, S_VEC3);
    litObjectsMat->SetMaterialAttribute("light.direction", camera->Front, S_VEC3);
    litObjectsMat->SetMaterialAttribute("light.position", camera->Position, S_VEC3);
    
    for (auto& cubePos : litObjectPosition) {
        model = glm::mat4(1.0f);

        model = glm::translate(model, cubePos);
        model = glm::scale(model, glm::vec3(10.f, 10.0f, 10.f));
        litObjectsMat->SetMaterialAttribute("model", model, S_MAT4);

        renderer->Render(*litObjectsMat, *camera);
    }

}








void SpotLightTest::OnUpdate(float deltaTime) {

}
void SpotLightTest::MouseCallBack(GLFWwindow* window, double xposIn, double yposIn, float deltaTime) {
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
void SpotLightTest::MouseScrollCallBack(GLFWwindow* window, double xoffset, double yoffset, float deltaTime) {
    camera->ProcessMouseScroll(static_cast<float>(yoffset));
}
void SpotLightTest::KeyboardInputCallBack(GLFWwindow* window, float deltaTime) {
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