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
    //set mvp 
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));

    projection = glm::perspective(glm::radians(camera->Zoom), 800.0f / 600.0f, 0.1f, 100.0f);

    // set up objects' vertex buffer

    vertexBuffer = new VertexBuffer(vertices, sizeof(vertices));
    VertexArrayAttribute* vertexAttr = new VertexArrayAttribute();
    vertexAttr->PushAttributef(3);
    vertexAttr->PushAttributef(3);
    vertexAttr->PushAttributef(2);
    vertexBuffer->UnBind();

    // set up light source
    lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
    unlitShaderProgram = new Shader("Shaders/unlitShader.vert", "Shaders/unlitShader.frag");
    unlitShaderProgram->Activate();

    unlitShaderProgram->SetVec3("color", glm::value_ptr(lightColor));
    unlitShaderProgram->SetMatrix4("model", glm::value_ptr(model));


    unlitShaderProgram->SetMatrix4("view", glm::value_ptr(view));


    unlitShaderProgram->SetMatrix4("projection", glm::value_ptr(projection));

    lightSourceVAO = new VertexArray();
    lightSourceVAO->AddVertexArrayAttributef(*vertexBuffer, *vertexAttr);
    lightSourceVAO->UnBind();
    unlitShaderProgram->Deactivate();
    //------------------
    // set up lit object
    litShaderProgram = new Shader("Shaders/litShader.vert", "Shaders/litShader.frag");
    litShaderProgram->Activate();
    glm::vec3 objectColor(0.5f, 0.5f, 0.0f);
    glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
    litShaderProgram->SetVec3("lightPos", glm::value_ptr(cubePositions[0]));
    litShaderProgram->SetVec3("viewPos", glm::value_ptr(camera->Position));

    litShaderProgram->SetVec3("lightMaterial.ambient", glm::value_ptr(glm::vec3(0.2f, 0.2f, 0.2f)));
    litShaderProgram->SetVec3("lightMaterial.diffuse", glm::value_ptr(lightColor)); // darken diffuse light a bit
    litShaderProgram->SetVec3("lightMaterial.specular", glm::value_ptr(glm::vec3(1.0f, 1.0f, 1.0f)));

    //litShaderProgram->SetVec3("objectMaterial.ambient", glm::value_ptr(glm::vec3(1.0f, 0.5f, 0.31f)));
    litShaderProgram->SetInt("objectMaterial.diffuse", 0); // darken diffuse light a bit
   
    litShaderProgram->SetInt("objectMaterial.specular",1);
    litShaderProgram->SetInt("objectMaterial.emission",2 );
    litShaderProgram->SetFloat("objectMaterial.shininess",32.0f);
    litShaderProgram->SetFloat("emissionPower", 0.0f);
    litShaderProgram->SetFloat("time", 0.0f);
    diffuseTexture = new Texture("External/Textures/container2.png", GL_REPEAT, GL_NEAREST);
    diffuseTexture->Bind(0);
    specularTexture = new Texture("External/Textures/container2_specular.png", GL_REPEAT, GL_NEAREST);
    specularTexture->Bind(1);

    emissionTexture = new Texture("External/Textures/matrix.jpg", GL_REPEAT, GL_NEAREST);
    emissionTexture->Bind(2);

    litShaderProgram->SetMatrix4("model", glm::value_ptr(model));
    litShaderProgram->SetMatrix4("view", glm::value_ptr(view));
    litShaderProgram->SetMatrix4("projection", glm::value_ptr(projection));

    litObjectVAO = new VertexArray();
    litObjectVAO->AddVertexArrayAttributef(*vertexBuffer, *vertexAttr);
    litObjectVAO->UnBind();
    litShaderProgram->Deactivate();

   
}

LightingExperiments::~LightingExperiments() {
    litObjectVAO->~VertexArray();
    lightSourceVAO->~VertexArray();
    vertexBuffer->~VertexBuffer();
    diffuseTexture->~Texture();
    specularTexture->~Texture();
   
}

void LightingExperiments::OnRender() {
    float t = static_cast<float>(glfwGetTime());
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    //lightColor = glm::vec3(sin(t * 2.0f) / 2.0f + 0.5f, cos(t * 0.5f) / 2.0f + 0.5f, sin(t * 4.0f) * cos(t * 0.25f) / 2.0f + 0.5f);

    //draw unlit light source
    unlitShaderProgram->Activate();

    view = camera->GetViewMatrix();
    unlitShaderProgram->SetMatrix4("view", glm::value_ptr(view));

    projection = glm::perspective(glm::radians(camera->Zoom), 800.0f / 600.0f, 0.1f, 100.0f);
    unlitShaderProgram->SetMatrix4("projection", glm::value_ptr(projection));

    unlitShaderProgram->SetVec3("color", glm::value_ptr(lightColor));
    lightSourceVAO->Bind();

    model = glm::mat4(1.0f);
    glm::vec3 deltaLightPos =  glm::vec3(cos(t),0.0f, sin(t))*2.0f + cubePositions[0];
    model = glm::translate(model, deltaLightPos);
    model = glm::scale(model, glm::vec3(0.3f));
    unlitShaderProgram->SetMatrix4("model", glm::value_ptr(model));

    glDrawArrays(GL_TRIANGLES, 0, 36);
    //draw lit object

    litShaderProgram->Activate();
    diffuseTexture->Bind(0);
    specularTexture->Bind(1);
    emissionTexture->Bind(2);
    litShaderProgram->SetVec3("lightPos", glm::value_ptr(deltaLightPos));
    litShaderProgram->SetVec3("viewPos", glm::value_ptr(camera->Position));
    view = camera->GetViewMatrix();
    litShaderProgram->SetMatrix4("view", glm::value_ptr(view));

    projection = glm::perspective(glm::radians(camera->Zoom), 800.0f / 600.0f, 0.1f, 100.0f);
    litShaderProgram->SetMatrix4("projection", glm::value_ptr(projection));
    litShaderProgram->SetVec3("lightMaterial.diffuse", glm::value_ptr(lightColor));
    litShaderProgram->SetFloat("emissionPower", (sin(t*5.0f) + 1.0f)/2.0f +0.1f);
    litShaderProgram->SetFloat("time", t);
    litObjectVAO->Bind();
    
    model = glm::mat4(1.0f);
    model = glm::translate(model, cubePositions[1]);
   // model = glm::rotate(model, t + glm::radians(30.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    litShaderProgram->SetMatrix4("model", glm::value_ptr(model));

    glDrawArrays(GL_TRIANGLES, 0, 36);



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