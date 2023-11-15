#pragma once
#include "GLFW/glfw3.h"




class Test {
public:
	Test() {}
	virtual ~Test() {}

	virtual  void OnUpdate(float deltaTime) {}
	virtual  void OnRender() {}
	virtual void MouseCallBack(GLFWwindow* window, double xposIn, double yposIn,float deltaTime){}
	virtual void MouseScrollCallBack(GLFWwindow* window, double xoffset, double yoffset,float deltaTime){}
	virtual void KeyboardInputCallBack(GLFWwindow* window, float deltaTime) {}
};