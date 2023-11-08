#include "VertexArray.h"
VertexArray::VertexArray(): ID(0) {

	glGenVertexArrays(1, &ID);
	glBindVertexArray(ID);

}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &ID);
}

void VertexArray::Bind() const {
	glBindVertexArray(ID);

}
void VertexArray::UnBind() const {
	glBindVertexArray(0);

}
void VertexArray::AddVertexArrayAttributef(const VertexBuffer& vbo, const VertexArrayAttribute& attributes) {
	Bind();
	vbo.Bind();
	const std::vector<unsigned int>& sizeArray = attributes.GetElements();
	unsigned int offSet = 0;
	for (unsigned int i = 0; i < sizeArray.size(); i++) {
		glVertexAttribPointer(i, sizeArray[i], GL_FLOAT, GL_FALSE, attributes.GetStride() * sizeof(float), (void*)(offSet * sizeof(float)));
		glEnableVertexAttribArray(i);
		offSet += sizeArray[i];
	}
	

}
