#pragma once
#include "Common.h"
#include "VertexBuffer.h"
#include <vector>


class VertexArrayAttribute {
private:
	unsigned int stride;
	std::vector<unsigned int> sizeArray;

public:
	VertexArrayAttribute() : stride(0) {};
	void PushAttributef(unsigned int size) {
		stride += size;
		sizeArray.push_back(size);
	}

	inline const std::vector<unsigned int> GetElements() const& { return sizeArray; }
	inline unsigned int GetStride() const { return stride; }
};
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

