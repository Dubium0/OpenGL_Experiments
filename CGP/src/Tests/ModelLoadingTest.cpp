#include "ModelLoadingTest.h"


ModelLoadingTest::ModelLoadingTest() {

    // build and compile shaders
 // -------------------------
    myShader = new Shader("Shaders/1.model_loading.vert", "Shaders/1.model_loading.frag");

    // load models
    // -----------
    myModel = new Model("External/Models/backpack/backpack.obj");

    camera = new Camera();


}
ModelLoadingTest::~ModelLoadingTest() {
    delete myModel;
    delete camera;
    delete myShader;

}

void ModelLoadingTest::OnUpdate(float deltaTime) {

}
void ModelLoadingTest::OnRender() {

    float t = static_cast<float>(glfwGetTime());

    glClearColor(0.28f, 0.28f, 0.28f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
   

    // we will change material class 
    myShader->Activate();

    // view/projection transformations
    glm::mat4 projection = glm::perspective(glm::radians(camera->Zoom), 800.0f / 600.0f, 0.1f, 100.0f);
    glm::mat4 view = camera->GetViewMatrix();
    myShader->SetMatrix4("projection", projection);
    myShader->SetMatrix4("view", view);

    // render the loaded model
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
    model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));	// it's a bit too big for our scene, so scale it down
    myShader->SetMatrix4("model", model);
    myModel->RenderModel(*camera ,myShader );


}
void ModelLoadingTest::MouseCallBack(GLFWwindow* window, double xposIn, double yposIn, float deltaTime) {
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
