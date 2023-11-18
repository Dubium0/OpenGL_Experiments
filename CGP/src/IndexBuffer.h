#pragma once
#include "Common.h"

class IndexBuffer
{
private:
	unsigned int ID;

public:
	IndexBuffer(const void* data, unsigned int size);
	~IndexBuffer();
	void Bind() const;
	void UnBind() const;

};
