#pragma once
#include "../VertexArray.h"
#include "../Texture.h"
#include "../Shader.h"
#include "Test.h"
#include "../Camera.h"
#include "../../External/glm/glm.hpp"
#include "../../External/glm/gtc/matrix_transform.hpp"
#include "../../External/glm/gtc/type_ptr.hpp"

class LightingExperiments : public Test{

public:
	LightingExperiments();
	~LightingExperiments();

	void OnRender() override;
	void MouseCallBack(GLFWwindow* window, double xposIn, double yposIn, float deltaTime) override;
	void MouseScrollCallBack(GLFWwindow* window, double xoffset, double yoffset, float deltaTime) override;
	void KeyboardInputCallBack(GLFWwindow* window, float deltaTime) override;

private:

	VertexArray* lightSourceVAO;
	VertexArray* litObjectVAO;
	VertexBuffer* vertexBuffer;
	Shader* unlitShaderProgram;
	Shader* litShaderProgram;
	Texture* diffuseTexture;
	Texture* specularTexture;
	Texture* emissionTexture;
	Camera* camera;
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	glm::vec3 lightColor;
	std::vector<glm::vec3> cubePositions;
	float lastX = 0.0f;
	float lastY = 0.0f;
	bool firstMouse = true;

	
};