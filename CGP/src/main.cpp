#include "GL/glew.h"
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


const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float deltaTime;
float lastFrame;

Test* currentTest;


void mouse_callback(GLFWwindow* window, double xposIn, double yposIn) {
    currentTest->MouseCallBack(window, xposIn, yposIn,deltaTime);
}
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    currentTest->MouseScrollCallBack(window, xoffset, yoffset, deltaTime);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow* window)
{   
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
    {
        currentTest->~Test();
        currentTest = new SpinningCubesTest();

    }
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
    {
        currentTest->~Test();
        currentTest = new LightingExperiments();

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

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    

    currentTest = new LightingExperiments();
  

    
  
  
    while (!glfwWindowShouldClose(window))
    {
        float t = static_cast<float>(glfwGetTime());
        deltaTime = t - lastFrame;
        lastFrame = t;

        // handle input
        processInput(window);
       
        //handle rendering
        currentTest->OnRender();
        //glDrawElements(GL_TRIANGLES, (unsigned int)(sizeof(indices) / sizeof(unsigned int)), GL_UNSIGNED_INT, 0);
     


        // check-call events and swap buffer
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
 
    //glDeleteBuffers(1, &VBO);
    //glDeleteVertexArrays(1, &VAO);
    currentTest->~Test();
    //glDeleteBuffers(1, &EBO);
    

    glfwTerminate(); 
    return 0;

}


