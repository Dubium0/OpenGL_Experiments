#pragma once
#include "../Renderer.h"
#include "Test.h"

class PointLightTest: public Test {

public:
	PointLightTest();
	~PointLightTest();

	void OnUpdate(float deltaTime)override;
	void OnRender(int, int) override;
	void MouseCallBack(GLFWwindow* window, double xposIn, double yposIn, float deltaTime) override;
	void MouseScrollCallBack(GLFWwindow* window, double xoffset, double yoffset, float deltaTime) override;
	void KeyboardInputCallBack(GLFWwindow* window, float deltaTime) override;


private:
	Camera* camera;
	Renderer* renderer;
	Material* lightSourceMat;
	Material* litObjectsMat;
	
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	glm::vec3 lightPos;

	std::vector<glm::vec3> litObjectPosition;

	float lastX = 0.0f;
	float lastY = 0.0f;
	bool firstMouse = true;


};
