#pragma once
#include "Common.h"
#include "VertexBuffer.h"
#include "VertexArrayAttribute.h"
class VertexArray
{
private:
	unsigned int ID;



public:
	VertexArray();
	~VertexArray();
	void AddVertexArrayAttributef(const VertexBuffer& vbo, const VertexArrayAttribute& attributes);
	
	
	void Bind() const;
	void UnBind() const;

};

