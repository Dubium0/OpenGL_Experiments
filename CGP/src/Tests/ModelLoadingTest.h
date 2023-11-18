#pragma once

#include "../Model.h"
#include "../Camera.h"
#include "Test.h"

class ModelLoadingTest : public Test {


public:
	ModelLoadingTest();
	~ModelLoadingTest();

	void OnUpdate(float deltaTime) override;
	void OnRender()override;
	void MouseCallBack(GLFWwindow* window, double xposIn, double yposIn, float deltaTime)override;
	void MouseScrollCallBack(GLFWwindow* window, double xoffset, double yoffset, float deltaTime) override;
	void KeyboardInputCallBack(GLFWwindow* window, float deltaTime) override;



private:
	Model* myModel;
	Camera* camera;
	Shader* myShader;

	float lastX = 0.0f;
	float lastY = 0.0f;
	bool firstMouse = true;
};


