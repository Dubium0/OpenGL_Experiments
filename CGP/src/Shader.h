#pragma once

#include "GL/glew.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath);

	void Activate();
	void Deactivate();
	
	void SetBool(const std::string &name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetMatrix4(const std::string& name, const float *value) const;
	void SetVec3(const std::string& name, const float* value) const;
private:
	void checkCompileErrors(unsigned int shader, std::string type);
};

