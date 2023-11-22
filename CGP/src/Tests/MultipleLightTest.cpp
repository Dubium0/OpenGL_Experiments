#include "MultipleLightTest.h"



MultipleLight::MultipleLight(){
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
    // object positions
    pointLightPoses = { glm::vec3(0.0f,0.0f,4.0f),
                        glm::vec3(0.0f,0.0f,-4.0f) };
    litObjPoses = {
        glm::vec3(0.0f,0.0f,2.0f),
        glm::vec3(-2.0f,0.0f,4.0f),
        glm::vec3(2.0f,.0f,4.0f),

        glm::vec3(0.0f,.0f,-2.0f),
        glm::vec3(-2.0f,.0f,-4.0f),
        glm::vec3(2.0f,.0f,-4.0f),
    };

    model = glm::mat4(1.0f);

    // init tools
    renderer = new Renderer(vertices, sizeof(vertices));
    camera = new Camera();
    // unlit objSetup
    unlitObj = new Material("Shaders/unlitShader.vert", "Shaders/unlitShader.frag");
    glm::vec3 whiteColor(1.0f, 1.0f, 1.0f);
    unlitObj->SetMaterialAttribute("color", whiteColor, S_VEC3);
    // litObj setup
    litObj = new Material("Shaders/multipleLight.vert", "Shaders/multipleLight.frag");
    //add texture
    litObj->AddTexture("material.diffuse0", "External/Textures/diffuse.png", GL_REPEAT, GL_NEAREST);
    litObj->AddTexture("material.specular0", "External/Textures/specular.png", GL_REPEAT, GL_NEAREST);
    // material attr
    litObj->SetMaterialAttribute("material.shininess", 32.0f,S_FLOAT);
    // directional light setup
    glm::vec3 directionalLightDirection(0.3f,0.1f,0.4f);
    glm::vec3 directionalLightAmbient(0.2f, 0.2f, 0.2f);
    glm::vec3 directionalLightDiffuse(0.8f, 0.8f, 0.8f);
    glm::vec3 directionalLightSpecular(1.f, 1.f, 1.f);
    litObj->SetMaterialAttribute("directionalLight.direction", directionalLightDirection, S_VEC3);
    litObj->SetMaterialAttribute("directionalLight.ambient", directionalLightAmbient, S_VEC3);
    litObj->SetMaterialAttribute("directionalLight.diffuse", directionalLightDiffuse, S_VEC3);
    litObj->SetMaterialAttribute("directionalLight.specular", directionalLightSpecular, S_VEC3);
    // setup point lights
    for (int i = 0; i < pointLightPoses.size(); i++) {
        std::string n = std::to_string(i);
        litObj->SetMaterialAttribute(("pointLights[" + n + "].position").c_str(), pointLightPoses[0], S_VEC3);

        litObj->SetMaterialAttribute(("pointLights[" + n + "].constant").c_str(), 1.0f, S_FLOAT);
        litObj->SetMaterialAttribute(("pointLights[" + n + "].linear").c_str(), 0.09f, S_FLOAT);
        litObj->SetMaterialAttribute(("pointLights[" + n + "].quadratic").c_str(), 0.032f, S_FLOAT);
        glm::vec3 pointLightAmbient(0.1f, 0.1f, 0.1f);
        pointLightAmbient += i / 5.0f;
        glm::vec3 pointLightDiffuse(0.5f, 0.5f, 0.5f);
        pointLightDiffuse += i / 5.0f;
        glm::vec3 pointLightSpecular(1.f, 1.f, 1.f);
        litObj->SetMaterialAttribute(("pointLights[" + n + "].ambient").c_str(), pointLightAmbient, S_VEC3);
        litObj->SetMaterialAttribute(("pointLights[" + n + "].diffuse").c_str(), pointLightDiffuse, S_VEC3);
        litObj->SetMaterialAttribute(("pointLights[" + n + "].specular").c_str(), pointLightSpecular, S_VEC3);

    }
    //spot light setup
    litObj->SetMaterialAttribute("spotLight.position",camera->Position , S_VEC3);
    litObj->SetMaterialAttribute("spotLight.direction",camera->Front , S_VEC3);
    litObj->SetMaterialAttribute("spotLight.cutOff", glm::cos(glm::radians(12.5f)), S_FLOAT);
    litObj->SetMaterialAttribute("spotLight.outerCutOff", glm::cos(glm::radians(17.5f)), S_FLOAT);
    litObj->SetMaterialAttribute("spotLight.constant", 1.0f, S_FLOAT);
    litObj->SetMaterialAttribute("spotLight.linear", 0.09f, S_FLOAT);
    litObj->SetMaterialAttribute("spotLight.quadratic", 0.032f, S_FLOAT);
    glm::vec3 spotLightAmbient(0.1f, 0.1f, 0.1f);
    glm::vec3 spotLightDiffuse(0.1f, 0.1f, 0.1f);
    glm::vec3 spotLightSpecular(0.1f, 0.1f, 0.1f);
    litObj->SetMaterialAttribute("spotLight.ambient", spotLightAmbient, S_VEC3);
    litObj->SetMaterialAttribute("spotLight.diffuse", spotLightDiffuse, S_VEC3);
    litObj->SetMaterialAttribute("spotLight.specular",spotLightSpecular, S_VEC3);
    // view post
    litObj->SetMaterialAttribute("viewPos", camera->Position,S_VEC3);



}




void MultipleLight::OnRender(int width,int height) {
    float t = static_cast<float>(glfwGetTime());

    glClearColor(0.28f, 0.28f, 0.28f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    //spotLight update
    litObj->SetMaterialAttribute("spotLight.position", camera->Position, S_VEC3);
    litObj->SetMaterialAttribute("spotLight.direction", camera->Front, S_VEC3);
    // viewPos update;
    litObj->SetMaterialAttribute("viewPos", camera->Position, S_VEC3);

    for (auto& pos : pointLightPoses) {
        model = glm::mat4(1.0f);
        model = glm::translate(model, pos);
        unlitObj->SetMaterialAttribute("model", model, S_MAT4);
        renderer->Render(*unlitObj, *camera);
    }

    for (auto& pos : litObjPoses) {
        model = glm::mat4(1.0f);
        model = glm::translate(model, pos);
        litObj->SetMaterialAttribute("model", model, S_MAT4);
        renderer->Render(*litObj, *camera);
    }


}


void MultipleLight::OnUpdate(float deltaTime) {

}
void MultipleLight::MouseCallBack(GLFWwindow* window, double xposIn, double yposIn, float deltaTime) {
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
void MultipleLight::MouseScrollCallBack(GLFWwindow* window, double xoffset, double yoffset, float deltaTime) {
    camera->ProcessMouseScroll(static_cast<float>(yoffset));

}
void MultipleLight::KeyboardInputCallBack(GLFWwindow* window, float deltaTime) {
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