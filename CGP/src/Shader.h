#pragma once

#include "GL/glew.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../External/glm/glm.hpp"
#include "../External/glm/gtc/matrix_transform.hpp"
#include "../External/glm/gtc/type_ptr.hpp"
class Shader
{
public:
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader() {
		glDeleteProgram(ID);
	}
	void Activate() const;
	void Deactivate() const;
	
	void SetBool(const std::string& name, bool value) const;
	void SetInt(const std::string& name, int value) const;
	void SetFloat(const std::string& name, float value) const;
	void SetMatrix4(const std::string& name, glm::mat4& m4) const;
	void SetVec3(const std::string& name, glm::vec3& v3) const;
private:
	void checkCompileErrors(unsigned int shader, std::string type);
};

