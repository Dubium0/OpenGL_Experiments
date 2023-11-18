#include "Renderer.h"

Renderer::Renderer(const void* vertices, int size):
	vao(new VertexArray()), vbo(new VertexBuffer(vertices, size)),ebo(nullptr), indexCount(0),
	 view(glm::mat4(1.0f)), projection(glm::mat4(1.0f)),vertexCount(size) {

	VertexArrayAttribute  attributes = VertexArrayAttribute();
	attributes.PushAttributef(3);// push positions
	attributes.PushAttributef(3);// push normals
	attributes.PushAttributef(2);// push texture coordinates
	// fill vertex array
	vao->AddVertexArrayAttributef(*vbo, attributes);
	vao->UnBind();
	
	

}


Renderer::Renderer(const void* vertices, int verticesSize, const void* indices, int indicesSize) :
	vao(new VertexArray()), vbo(new VertexBuffer(vertices, verticesSize)), ebo(new IndexBuffer(indices, indicesSize)),
	view(glm::mat4(1.0f)), projection(glm::mat4(1.0f)), vertexCount(verticesSize), indexCount(indicesSize) {

	VertexArrayAttribute  attributes = VertexArrayAttribute();
	attributes.PushAttributef(3);// push positions
	attributes.PushAttributef(3);// push normals
	attributes.PushAttributef(2);// push texture coordinates
	attributes.PushAttributef(3);// push Tangent
	attributes.PushAttributef(3);// push BiTangent
	// fill vertex array
	vao->AddVertexArrayAttributef(*vbo,*ebo , attributes);
	vao->UnBind();



}
void Renderer::Render( Material& materialTarget, Camera& cameraTarget) {
	
	view = cameraTarget.GetViewMatrix();
	materialTarget.SetMaterialAttribute("view", view,S_MAT4);
	projection = glm::perspective(glm::radians(cameraTarget.Zoom), 800.0f / 600.0f, 0.1f, 100.0f);
	materialTarget.SetMaterialAttribute("projection", projection,S_MAT4);
	materialTarget.Bind();
	vao->Bind();
	if (ebo) {
		unsigned int count = indexCount / sizeof(unsigned int);
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, 0);
		glCheckError();
	}
	else {
		unsigned int count = (vertexCount / sizeof(float) ) / 8;
		glDrawArrays(GL_TRIANGLES, 0,count );
		glCheckError();

	}

}
