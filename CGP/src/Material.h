#pragma once
// just stores to uniforms and sets them
#include "Shader.h"
#include "Texture.h"
#include <vector>
#include "../External/glm/glm.hpp"
#include "../External/glm/gtc/matrix_transform.hpp"
#include "../External/glm/gtc/type_ptr.hpp"
#include <unordered_map>
#include "TextureLoader.h"
enum UniformType{ S_FLOAT,S_INT, S_BOOL,S_VEC3,S_MAT4 };
class  Material{
public:
	bool isOnDebugMode;
	Material(): shader(nullptr) ,isOnDebugMode(false){};
	
	Material(const char* vPath, const char* fPath) :isOnDebugMode(false),
		shader(new Shader(vPath, fPath)) {};

	 ~Material();

	template< typename T>
	void SetMaterialAttribute(const std::string& name, T val, UniformType type) {
		if (shader) {

			shader->Activate();

		
			switch (type)
			{
			case S_FLOAT:
			
				if constexpr (std::is_same_v<T, float>) {
					shader->SetFloat(name, val);
				}
				else {
					if(isOnDebugMode)
						std::cout << "MATERIAL_DEBUG: Attribute type mismatch. Expected float." << std::endl;
				}
				break;
			case S_INT:
			
				if constexpr (std::is_same_v < T, int>) {
					shader->SetInt(name, val);
				}
				else {
					if (isOnDebugMode)
					std::cout << "MATERIAL_DEBUG: Attribute type mismatch. Expected int." << std::endl;
				}
				break;
			case S_VEC3:
				if constexpr (std::is_same_v < T, glm::vec3>) {
					shader->SetVec3(name, val);
				}
				else {
					if (isOnDebugMode)
					std::cout << "MATERIAL_DEBUG: Attribute type mismatch. Expected glm::vec3." << std::endl;
				}
				break;
			case S_MAT4:
				if constexpr (std::is_same_v<T, glm::mat4>) {
					shader->SetMatrix4(name, val);
				}
				else {
					if (isOnDebugMode)
					std::cout << "MATERIAL_DEBUG: Attribute type mismatch. Expected glm::mat4." << std::endl;
				}
				break;
			case S_BOOL:
			
				if constexpr (std::is_same_v<T, bool>) {
					shader->SetBool(name, val);
				}
				else {
					if (isOnDebugMode)
					std::cout << "MATERIAL_DEBUG: Attribute type mismatch. Expected bool." << std::endl;
				}
				break;
			default:
				if (isOnDebugMode)
				std::cout << "MATERIAL_DEBUG: Attribute decleration type is not compatible" << std::endl;
				break;
			};

		
			shader->Deactivate();
		}
	}
	
	void AddTexture(const std::string& channelName,const std::string& texturePath, GLint _wrapParam, GLint _filterMode);

	void Bind()const; 
	void Bind(Shader& shader,TextureLoader& loader)const;
	
	
	void AddTexture(const std::string& typeName, std::vector<int> textureIDS);

	void SetShaderIfDoesNotHave(Shader* shader) {
		if (this->shader ==nullptr) {
			this->shader = shader;
		}
		else {
			if (isOnDebugMode)
			std::cout << "DEBUG::MATERIAL:: " << "Material has a shader" << " ::DEBUG::END" << std::endl;
		}
	
	}

	inline bool  DoesHaveShader() const{
		if (shader == nullptr) {
			if (isOnDebugMode)
			std::cout << "DEBUG::MATERIAL:: " << "Material doesn't have  a shader" << " ::DEBUG::END" << std::endl;
			return false;
		}
		else {
			if (isOnDebugMode)
			std::cout << "DEBUG::MATERIAL:: " << "Material has a shader" << " ::DEBUG::END" << std::endl;
			return true;
		}

	}
	

private:
	Shader* shader;
	std::unordered_map<std::string, Texture* > textures;
	std::unordered_map<std::string, std::vector<int>> textures_IndexBased;

	void BindTextures() const;
	


};