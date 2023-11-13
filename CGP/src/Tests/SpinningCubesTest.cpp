#include "SpinningCubesTest.h"

SpinningCubesTest::SpinningCubesTest() :
	vertexArray(nullptr), vertexBuffer(nullptr), vertexArrayAttribute(nullptr), shaderProgram(nullptr), 
	texture_1(nullptr), texture_2(nullptr), camera(nullptr),
	model(glm::mat4(1.0f)), view(glm::mat4(1.0f)), projection(glm::mat4(1.0f)) {

    float vertices[] = {
   -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
    0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
   -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
   -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

   -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
   -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
   -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
    0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
   -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
   -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
    0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
    0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
   -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
   -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    
    cubePositions =  {
        glm::vec3(0.0f,  0.0f,  0.0f),
        glm::vec3(2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3(2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3(1.3f, -2.0f, -2.5f),
        glm::vec3(1.5f,  2.0f, -2.5f),
        glm::vec3(1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };
    //init camera
    camera = new Camera();
    // init shader program and set properties
    shaderProgram = new Shader("Shaders/myShader.vert", "Shaders/myShader.frag");
    shaderProgram->Activate();

    shaderProgram->SetInt("texture1", 0);

    shaderProgram->SetInt("texture2", 1);

    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    shaderProgram->SetMatrix4("model", model);



    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    shaderProgram->SetMatrix4("view", view);



    projection = glm::perspective(glm::radians(camera->Zoom), 800.0f / 600.0f, 0.1f, 100.0f);
    shaderProgram->SetMatrix4("projection", projection);

    // init vertex array and buffer
    vertexArray = new VertexArray();
    vertexBuffer = new VertexBuffer(vertices, sizeof(vertices));

    vertexArrayAttribute = new VertexArrayAttribute();
    vertexArrayAttribute->PushAttributef(3);
    vertexArrayAttribute->PushAttributef(2);

    vertexArray->AddVertexArrayAttributef(*vertexBuffer, *vertexArrayAttribute);


    

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //init texture
    texture_1 = new Texture("External/Textures/container.jpg", GL_REPEAT, GL_NEAREST);
    texture_2 = new Texture("External/Textures/awesomeface.png", GL_REPEAT, GL_NEAREST);


}

SpinningCubesTest::~SpinningCubesTest() {
    vertexArray->~VertexArray();
    vertexBuffer->~VertexBuffer();
    texture_1->~Texture();
    texture_2->~Texture();

}
void SpinningCubesTest::OnRender()  {
    float t = static_cast<float>(glfwGetTime());
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);


    shaderProgram->Activate();
   

    view = camera->GetViewMatrix();
    shaderProgram->SetMatrix4("view", view);

    projection = glm::perspective(glm::radians(camera->Zoom), 800.0f / 600.0f, 0.1f, 100.0f);
    shaderProgram->SetMatrix4("projection",projection);


    texture_1->Bind(0);
    texture_2->Bind(1);

    //glBindVertexArray(VAO);
    vertexArray->Bind();

    for (unsigned int i = 0; i < 10; i++) {
        model = glm::mat4(1.0f);
        model = glm::translate(model, cubePositions[i]);
        if (i % 3 == 0) {
            float angle = 20.0f * (i + 1);
            model = glm::rotate(model, t + glm::radians(angle), glm::vec3(0.5f, 1.0f, 0.0f));

        }
        else {
            float angle = 20.0f * (i + 1);
            model = glm::rotate(model, glm::radians(angle), glm::vec3(0.5f, 1.0f, 0.0f));
        }

        shaderProgram->SetMatrix4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }


}

void SpinningCubesTest::MouseCallBack(GLFWwindow* window, double xposIn, double yposIn, float deltaTime) {
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

void SpinningCubesTest::MouseScrollCallBack(GLFWwindow* window, double xoffset, double yoffset,float deltaTime) {
    camera->ProcessMouseScroll(static_cast<float>(yoffset));

}

void SpinningCubesTest::KeyboardInputCallBack(GLFWwindow* window, float deltaTime) {
 
 

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

void SpinningCubesTest::OnUpdate(float deltaTime) {

}

