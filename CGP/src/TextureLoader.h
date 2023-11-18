#pragma once

#include "Common.h"
#include "Texture.h"
#include <vector>
#include <unordered_map>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class TextureLoader {

public:
	std::unordered_map< std::string, std::vector<Texture*> > linkedTextures;
	TextureLoader() {
		std::cout << "A Texture Loader Created" << std::endl;
		
	}
	~TextureLoader() {
		// later on we will delete texture pointers here right now they deleted on material
		std::cout << "A Texture Loader Deleted" << std::endl;

		for (auto& element : linkedTextures) {
			for (auto& text : element.second) {
				delete text;
			}

		}

		
	}

	std::vector<int> loadTextures(aiMaterial* mat, aiTextureType type,const std::string& directory ,std::string typeName) {
		std::vector<int> textureIndices;
		
		for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
			aiString path;
			mat->GetTexture(type, i, &path);
			bool wasThere = false;
			
			
			for (unsigned int k = 0; k < linkedTextures[typeName].size(); k++) {
				if (std::strcmp(linkedTextures[typeName][k]->GetModelPath().data(), path.C_Str()) == 0) {
					textureIndices.push_back(k);
					wasThere = true;
					break;
				}
			}

			
			
			if (!wasThere) {
				Texture* textureToLoad = new Texture(TexturePathParser(path.C_Str(), directory), GL_REPEAT, GL_NEAREST);
				textureToLoad->SetTypeName(typeName); // doesnt have to do I'm doing it just because I want to debug texture type from the texture itself
				textureToLoad->SetModelPath(path.C_Str());
				linkedTextures[typeName].push_back(textureToLoad);
				textureIndices.push_back(linkedTextures[typeName].size() - 1); 
			}
		}

		return textureIndices;


	}

	void PrintAllTexturesLoaded() {
		std::cout << " PRINTING TEXTURES " << std::endl;
		
		for (const auto& element : linkedTextures) {
			for (const auto& text : element.second) {
				std::cout << "TYPE: " << element.first << "  ::  " << "PATH: " << text->GetModelPath() << std::endl;
			}
		}


	}

	//inline std::unordered_map< std::string, std::vector<Texture*> > GetTextures() const { return linkedTextures; }

private:
	

	inline std::string TexturePathParser(const char* path, const std::string& directory) const {
		return directory + '/' + std::string(path);
	}
	

};