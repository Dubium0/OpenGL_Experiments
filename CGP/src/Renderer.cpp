#include "Renderer.h"

Renderer::Renderer(const void* vertices, int size):
	vao(new VertexArray()), vbo(new VertexBuffer(vertices, size)),
	 view(glm::mat4(1.0f)), projection(glm::mat4(1.0f)),vertexCount(size) {

	VertexArrayAttribute  attributes = VertexArrayAttribute();
	attributes.PushAttributef(3);// push positions
	attributes.PushAttributef(3);// push normals
	attributes.PushAttributef(2);// push texture coordinates
	// fill vertex array
	vao->AddVertexArrayAttributef(*vbo, attributes);
	vao->UnBind();
	
	

}
void Renderer::Render( Material& materialTarget, Camera& cameraTarget) {
	// make sure shader is activated
	
	view = cameraTarget.GetViewMatrix();
	materialTarget.SetMaterialAttribute("view", view,S_MAT4);
	projection = glm::perspective(glm::radians(cameraTarget.Zoom), 800.0f / 600.0f, 0.1f, 100.0f);
	materialTarget.SetMaterialAttribute("projection", projection,S_MAT4);
	materialTarget.Bind();
	vao->Bind();
	unsigned int count = (vertexCount / sizeof(float) ) / 8;
	glDrawArrays(GL_TRIANGLES, 0,count );

}
