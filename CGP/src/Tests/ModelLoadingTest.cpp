#include "ModelLoadingTest.h"


ModelLoadingTest::ModelLoadingTest() {

    // build and compile shaders
 // -------------------------
    myShader = new Shader("Shaders/directionalLight.vert", "Shaders/directionalLight.frag");

    // load models
    // -----------
    myModel = new Model("External/Models/humanMesh/FinalBaseMesh.obj");

    camera = new Camera();
    myShader->Activate();
    directionalLightDirection = glm::vec3(-.5, -.2f, -.3f);
    directionalLightAmbient = glm::vec3(0.4f, 0.4f, 0.4f);
    directionalLightDiffuse = glm::vec3(0.9f, 0.9f, 0.9f);
    directionalLightSpecular = glm::vec3(1.f, 1.f, 1.f);
    myShader->SetVec3("lightMaterial.direction", directionalLightDirection);
    myShader->SetVec3("lightMaterial.ambient", directionalLightAmbient);
    myShader->SetVec3("lightMaterial.diffuse", directionalLightDiffuse);
    myShader->SetVec3("lightMaterial.specular", directionalLightSpecular);
    myShader->SetBool("isColorShading", false);
    objectAmbient = glm::vec3(1.f, 0.f, 0.f);
    objectDiffuse = glm::vec3(0.3f, 0.5f, 0.3f);
    objectSpecular = glm::vec3(1.f, 1.f, 1.f);
    myShader->SetVec3("material.diffuse", objectDiffuse);
    myShader->SetVec3("material.ambient", objectAmbient);
    myShader->SetVec3("material.specular", objectSpecular);
    myShader->Deactivate();

}
ModelLoadingTest::~ModelLoadingTest() {
    delete myModel;
    delete camera;
    delete myShader;

}

void ModelLoadingTest::OnUpdate(float deltaTime) {
    
    
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    {   
        ImGui::Begin("Light Editor ");
        ImGui::Text("Change Light Settings here");
        ImGui::SliderFloat3("Light Direction",glm::value_ptr(directionalLightDirection), -1.f, 1.f);
        ImGui::ColorEdit3("Light Ambient Color",glm::value_ptr(directionalLightAmbient));
        ImGui::ColorEdit3("Light Diffuse Color", glm::value_ptr(directionalLightDiffuse));
        ImGui::ColorEdit3("Light Specular Color", glm::value_ptr(directionalLightSpecular));
        ImGui::End();

        ImGui::Begin("Material Editor ");
        ImGui::Text("Change Material Settings here");
        ImGui::ColorEdit3("Ambient Color", glm::value_ptr(objectAmbient));
        ImGui::ColorEdit3("Diffuse Color", glm::value_ptr(objectDiffuse));
        ImGui::ColorEdit3("Specular Color", glm::value_ptr(objectSpecular));
        ImGui::End();

    }
   
    myShader->SetVec3("lightMaterial.direction", directionalLightDirection);
    myShader->SetVec3("lightMaterial.ambient", directionalLightAmbient);
    myShader->SetVec3("lightMaterial.diffuse", directionalLightDiffuse);
    myShader->SetVec3("lightMaterial.specular", directionalLightSpecular);

    myShader->SetVec3("material.diffuse", objectDiffuse);
    myShader->SetVec3("material.ambient", objectAmbient);
    myShader->SetVec3("material.specular", objectSpecular);


}
void ModelLoadingTest::OnRender(int Width, int Height) {

    float t = static_cast<float>(glfwGetTime());

    glClearColor(0.28f, 0.28f, 0.28f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
   

    // we will change material class 
    myShader->Activate();

    // view/projection transformations
    glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom),(float) Width / Height, 0.1f, 100.0f);
    glm::mat4 view = camera->GetViewMatrix();
    myShader->SetMatrix4("projection", projection);
    myShader->SetMatrix4("view", view);

    // render the loaded model
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
    model = glm::scale(model, glm::vec3(.2f, .2f, .2f));	// it's a bit too big for our scene, so scale it down
    myShader->SetMatrix4("model", model);

    myShader->SetFloat("material.shininess", 32.0f);
    // directional light setup
    float sinVal = (sin(t * 2) + 1.0f) / 2.0f;
    
    myShader->SetVec3("viewPos", camera->Position);
    myShader->SetBool("isColorShading", true);

    myModel->RenderModel(*camera ,myShader );


}
void ModelLoadingTest::MouseCallBack(GLFWwindow* window, double xposIn, double yposIn, float deltaTime) {
    

    camera->ProcessMouseMovement(xposIn, yposIn);


}
void ModelLoadingTest::MouseScrollCallBack(GLFWwindow* window, double xoffset, double yoffset, float deltaTime) {
    camera->ProcessMouseScroll(static_cast<float>(yoffset));
}
void ModelLoadingTest::KeyboardInputCallBack(GLFWwindow* window, float deltaTime) {

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
