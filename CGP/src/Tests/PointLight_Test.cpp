#include "PointLight_Test.h"

PointLightTest::PointLightTest():camera(new Camera()), renderer(nullptr), lightSourceMat(nullptr), litObjectsMat(nullptr) {

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
    // set light source position
    lightPos = glm::vec3(0.0f, 0.0f, 0.0f);

    //-----------------------------------------------------------------------------------------------------------
    // create and setup light source material ------------------------------------------------------------------
    lightSourceMat = new Material("Shaders/unlitShader.vert", "Shaders/unlitShader.frag");
    model = glm::mat4(1.0f);
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
    lightSourceMat->SetMaterialAttribute("model", model,S_MAT4);
    lightSourceMat->SetMaterialAttribute("view", view, S_MAT4);
    lightSourceMat->SetMaterialAttribute("projection", projection, S_MAT4);
    glm::vec3 lightSourceColor(1.0f, 1.0f, 1.0f);
    lightSourceMat->SetMaterialAttribute("color", lightSourceColor, S_VEC3);
    
    // create and setup lit object material

    litObjectsMat = new Material("Shaders/pointLight.vert", "Shaders/pointLight.frag");
    model = glm::mat4(1.0f);
    litObjectsMat->SetMaterialAttribute("model", model, S_MAT4);
    litObjectsMat->SetMaterialAttribute("view", view, S_MAT4);
    litObjectsMat->SetMaterialAttribute("projection", projection, S_MAT4);

    litObjectsMat->AddTexture("objectMaterial.diffuse", "External/Textures/diffuse.png", GL_REPEAT, GL_NEAREST);
    litObjectsMat->AddTexture("objectMaterial.emission", "External/Textures/emission.jpg", GL_REPEAT, GL_NEAREST);
    litObjectsMat->AddTexture("objectMaterial.specular", "External/Textures/specular.png", GL_REPEAT, GL_NEAREST);
    litObjectsMat->SetMaterialAttribute("lightMaterial.position", lightPos,S_VEC3);
    glm::vec3 lightAmbientColor(0.2f,0.2f,0.2f);
    glm::vec3 lightDiffuseColor(0.9f, 0.9f, 0.9f);
    glm::vec3 lightSpecularColor(1.0f, 1.0f, 1.0f);

    litObjectsMat->SetMaterialAttribute("lightMaterial.ambient", lightAmbientColor, S_VEC3);
    litObjectsMat->SetMaterialAttribute("lightMaterial.diffuse", lightDiffuseColor, S_VEC3);
    litObjectsMat->SetMaterialAttribute("lightMaterial.specular", lightSpecularColor, S_VEC3);

    litObjectsMat->SetMaterialAttribute("lightMaterial.constant", 1.0f, S_FLOAT);
    litObjectsMat->SetMaterialAttribute("lightMaterial.linear", 0.09f, S_FLOAT);
    litObjectsMat->SetMaterialAttribute("lightMaterial.quadratic", 0.032f, S_FLOAT);

    litObjectsMat->SetMaterialAttribute("viewPos", camera->Position, S_VEC3);

    // init renderer

    renderer = new Renderer(vertices, sizeof(vertices));



}

PointLightTest::~PointLightTest() {
    delete renderer;
    delete camera;
    delete litObjectsMat;
    delete lightSourceMat;


}



void PointLightTest::OnRender() {
    float t = static_cast<float>(glfwGetTime());

    glClearColor(0.28f, 0.28f, 0.28f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    model = glm::mat4(1.0f);
    lightPos = glm::vec3(0.f, 0.f, sin(3.f * t) *4 );
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
    lightSourceMat->SetMaterialAttribute("model", model, S_MAT4);
  
    renderer->Render(*lightSourceMat,*camera);
    
    //set light pos 
    litObjectsMat->SetMaterialAttribute("lightMaterial.position", lightPos, S_VEC3);

    for (auto& cubePos : litObjectPosition) {
        model = glm::mat4(1.0f);
        
        model = glm::translate(model, cubePos);
        model = glm::scale(model, glm::vec3(10.f, 10.0f, 10.f));
        litObjectsMat->SetMaterialAttribute("model", model, S_MAT4);
       
        renderer->Render(*litObjectsMat, *camera);
    }

}








void PointLightTest::OnUpdate(float deltaTime) {

}
void PointLightTest::MouseCallBack(GLFWwindow* window, double xposIn, double yposIn, float deltaTime) {
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
void PointLightTest::MouseScrollCallBack(GLFWwindow* window, double xoffset, double yoffset, float deltaTime) {
    camera->ProcessMouseScroll(static_cast<float>(yoffset));
}
void PointLightTest::KeyboardInputCallBack(GLFWwindow* window, float deltaTime) {
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