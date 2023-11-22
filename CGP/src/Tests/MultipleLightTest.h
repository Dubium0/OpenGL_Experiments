#pragma once
#include "../Renderer.h"
#include "Test.h"


class MultipleLight : public Test {
public:

	MultipleLight();
	~MultipleLight() {
		delete renderer;
		delete camera;
		delete litObj;
		delete unlitObj;
	}

	void OnUpdate(float deltaTime)  override;
	void OnRender(int, int) override;
	void MouseCallBack(GLFWwindow* window, double xposIn, double yposIn, float deltaTime) override;
	void MouseScrollCallBack(GLFWwindow* window, double xoffset, double yoffset, float deltaTime) override;
	void KeyboardInputCallBack(GLFWwindow* window, float deltaTime) override;


private:

	Renderer* renderer;
	Camera* camera;
	Material* litObj;
	Material* unlitObj;
	
	std::vector<glm::vec3> pointLightPoses;
	std::vector<glm::vec3> litObjPoses;

	glm::mat4 model;



	float lastX = 0.0f;
	float lastY = 0.0f;
	bool firstMouse = true;
};