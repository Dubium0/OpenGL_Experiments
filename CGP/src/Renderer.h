#pragma once

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
	Renderer(const void* vertices, int size);
	Renderer(const void* vertices, int verticesSize, const void* indices, int indicesSize);
	
	~Renderer() {
		delete vao;
		delete vbo;
			
	}
	void Render( Material& material , Camera& camera) ;




private: 
	
	//Shader* shader;
	VertexArray* vao;
	VertexBuffer* vbo;
	IndexBuffer* ebo;
	unsigned int vertexCount;
	unsigned int indexCount;
	glm::mat4 view;
	glm::mat4 projection;
	
	

};