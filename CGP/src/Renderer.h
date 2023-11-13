#pragma once
#include "Shader.h"
#include "Texture.h"
#include <vector>
#include "../External/glm/glm.hpp"
#include "../External/glm/gtc/matrix_transform.hpp"
#include "../External/glm/gtc/type_ptr.hpp"
#include "Camera.h"
#include "VertexArray.h"
#include "Material.h"
/*
	Gets vertices with a shader and draws it

*/

class Renderer {
public:
	// this renderer expects it vertices data as [position,normal,uv]
	Renderer(const void* vertices, int size, Material* materialTarget, Camera* cameraTarget);
	~Renderer() {
		vao->~VertexArray();
		vbo->~VertexBuffer();

	}
	void Render() ;
	void ChangeMaterialTarget(Material* material);
	void ChangeCameraTarget(Camera* camera);




private: 
	
	//Shader* shader;
	Material* material;
	Camera* camera;
	VertexArray* vao;
	VertexBuffer* vbo;
	unsigned int vertexCount;
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;
	
	

};