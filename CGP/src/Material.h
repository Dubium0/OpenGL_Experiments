#pragma once
// just stores to uniforms and sets them
#include "Shader.h"
#include "Texture.h"
#include <vector>
#include "../External/glm/glm.hpp"
#include "../External/glm/gtc/matrix_transform.hpp"
#include "../External/glm/gtc/type_ptr.hpp"
#include <unordered_map>

enum UniformType{ S_FLOAT,S_INT, S_BOOL,S_VEC3,S_MAT4 };
class  Material{
public:
	
	Material(const char* vPath, const char* fPath) :
		shader(new Shader(vPath, fPath)) {};
	 ~Material();

	template< typename T>
	void SetMaterialAttribute(const std::string& name, T val, UniformType type) {
		shader->Activate();

		
		switch (type)
		{
		case S_FLOAT:
			
			if constexpr (std::is_same_v<T, float>) {
				shader->SetFloat(name, val);
			}
			else {
				std::cout << "MATERIAL_DEBUG: Attribute type mismatch. Expected float." << std::endl;
			}
			break;
		case S_INT:
			
			if constexpr (std::is_same_v < T, int>) {
				shader->SetInt(name, val);
			}
			else {
				std::cout << "MATERIAL_DEBUG: Attribute type mismatch. Expected int." << std::endl;
			}
			break;
		case S_VEC3:
			if constexpr (std::is_same_v < T, glm::vec3>) {
				shader->SetVec3(name, val);
			}
			else {
				std::cout << "MATERIAL_DEBUG: Attribute type mismatch. Expected glm::vec3." << std::endl;
			}
			break;
		case S_MAT4:
			if constexpr (std::is_same_v<T, glm::mat4>) {
				shader->SetMatrix4(name, val);
			}
			else {
				std::cout << "MATERIAL_DEBUG: Attribute type mismatch. Expected glm::mat4." << std::endl;
			}
			break;
		case S_BOOL:
			
			if constexpr (std::is_same_v<T, bool>) {
				shader->SetBool(name, val);
			}
			else {
				std::cout << "MATERIAL_DEBUG: Attribute type mismatch. Expected bool." << std::endl;
			}
			break;
		default:
			std::cout << "MATERIAL_DEBUG: Attribute decleration type is not compatible" << std::endl;
			break;
		};

		
		shader->Deactivate();
	}
	
	void AddTexture(const std::string& channelName,const std::string& texturePath, GLint _wrapParam, GLint _filterMode);

	void Bind()const;
	


	

private:
	Shader* shader;
	std::unordered_map<std::string, Texture* > textures;


	void BindTextures() const;
	


};