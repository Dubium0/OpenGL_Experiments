
#include "GL/glew.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "stb_image.h"
#include "Shader.h"
#include "Camera.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Texture.h"
#include "VertexArray.h"
#include "Tests/SpinningCubesTest.h"
#include "Tests/LightingExperiments.h"
#include "Tests/PointLight_Test.h"
#include "Tests/SpotLightTest.h"
#include "Tests/MultipleLightTest.h"
#include "Tests/ModelLoadingTest.h"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int screenWidth = SCR_WIDTH;
int screenHeight = SCR_HEIGHT;
float deltaTime;
float lastFrame;

Test* currentTest;
ModelLoadingTest* modelLoadingTest;
bool testCameraCanMove = false;
bool firstMouse = true;
double lastX;
double lastY;
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn) {
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
    if(testCameraCanMove)
        currentTest->MouseCallBack(window, xoffset, yoffset,deltaTime);
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    currentTest->MouseScrollCallBack(window, xoffset, yoffset, deltaTime);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void window_size_callback(GLFWwindow* window, int width, int height) {
    screenWidth = width;
    screenHeight = height;
}
void processInput(GLFWwindow* window)
{
    int rState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
    if (rState == GLFW_PRESS)
    {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        testCameraCanMove = true;
    }

    if (rState == GLFW_RELEASE) {
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        testCameraCanMove = false;

    }
   // if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
   //     glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
    {
        if (currentTest != modelLoadingTest)
            currentTest->~Test();
        currentTest = new SpinningCubesTest();

    }
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
    {
        if (currentTest != modelLoadingTest)
            currentTest->~Test();
        currentTest = new LightingExperiments();

    }

    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
    {
        if (currentTest != modelLoadingTest)
            currentTest->~Test();
        currentTest = new PointLightTest();

    }
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
    {
        if (currentTest != modelLoadingTest)
            currentTest->~Test();
        currentTest = new SpotLightTest();

    }
    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
    {
        if (currentTest != modelLoadingTest)
            currentTest->~Test();
        currentTest = new MultipleLight();

    }
    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
    {
       if(currentTest != modelLoadingTest)
            currentTest->~Test();
        currentTest = modelLoadingTest;
        

    }
    
    currentTest->KeyboardInputCallBack(window, deltaTime);
}   

int main(void) {

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK)
        std::cout << "GlEW IS NOT OKEY (HELP)" << std::endl;

    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetWindowSizeCallback(window, window_size_callback);
    // tell GLFW to capture our mouse
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);



    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    const char* glsl_version = "#version 130";



    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    
    modelLoadingTest =  new ModelLoadingTest();
    currentTest = modelLoadingTest;
  
  
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
  
    while (!glfwWindowShouldClose(window))
    {
        
        float t = static_cast<float>(glfwGetTime());
        deltaTime = t - lastFrame;
        lastFrame = t;

        // handle input
        processInput(window);
        currentTest->OnUpdate(t);
        //handle rendering
        ImGui::Render();
        currentTest->OnRender(screenWidth,screenHeight);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // check-call events and swap buffer
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
 

    currentTest->~Test();

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate(); 
    return 0;

}


