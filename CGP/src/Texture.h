#pragma once
#include "Common.h"


class Texture {
public:
	Texture(const std::string& _path, GLint _wrapParam, GLint _filterMode);
	~Texture();
	void Bind(unsigned int channel) const ;
	void UnBind() const;
private:
	unsigned int id;
	std::string path;
	unsigned char* data;
	int WIDTH, HEIGHT, NR_CHANNELS;
	
	


};