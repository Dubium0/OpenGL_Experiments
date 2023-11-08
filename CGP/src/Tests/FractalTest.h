#pragma once
#include "Test.h"

class Fractal :public Test {


public:
	Fractal();
	~Fractal();


	// overrides
	
	void OnUpdate(float deltaTime) override;
	void OnRender()override;
	void MouseCallBack(GLFWwindow* window, double xposIn, double yposIn, float deltaTime)override;
	void MouseScrollCallBack(GLFWwindow* window, double xoffset, double yoffset, float deltaTime) override;
	void KeyboardInputCallBack(GLFWwindow* window, float deltaTime) override;

};