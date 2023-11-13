#include "Renderer.h"

Renderer::Renderer(const void* vertices, int size, Material* materialTarget, Camera* cameraTarget):
	material(materialTarget), camera(cameraTarget), vao(new VertexArray()), vbo(new VertexBuffer(vertices, size)),
	model(glm::mat4(1.0f)), view(glm::mat4(1.0f)), projection(glm::mat4(1.0f)),vertexCount(size) {

	VertexArrayAttribute  attributes = VertexArrayAttribute();
	attributes.PushAttributef(3);// push positions
	attributes.PushAttributef(3);// push normals
	attributes.PushAttributef(2);// push texture coordinates
	// fill vertex array
	vao->AddVertexArrayAttributef(*vbo, attributes);
	vao->UnBind();
	// fill position uniforms

	material->SetMaterialAttribute("model", model,S_MAT4);
	material->SetMaterialAttribute("view", view,S_MAT4);
	projection = glm::perspective(glm::radians(camera->Zoom), 800.0f / 600.0f, 0.1f, 100.0f);
	material->SetMaterialAttribute("projection", projection,S_MAT4);



}
void Renderer::Render() {
	// make sure shader is activated
	
	view = camera->GetViewMatrix();
	material->SetMaterialAttribute("view", view,S_MAT4);
	projection = glm::perspective(glm::radians(camera->Zoom), 800.0f / 600.0f, 0.1f, 100.0f);
	material->SetMaterialAttribute("projection", projection,S_MAT4);
	material->Bind();
	vao->Bind();
	unsigned int count = (vertexCount / sizeof(float) ) / 8;
	std::cout << count << std::endl;
	glDrawArrays(GL_TRIANGLES, 0,count );




}
void Renderer::ChangeMaterialTarget(Material* material) {
	std::cout << "RENDERER DEBUG : Shader target has changed"<< std::endl;
	this->material = material;

}
void Renderer::ChangeCameraTarget(Camera* camera) {
	std::cout << "RENDERER DEBUG : Camera target has changed" << std::endl;
	this->camera = camera;
}