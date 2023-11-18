#include "Material.h"


void Material::AddTexture(const std::string& channelName,const std::string& path, GLint _wrapParam, GLint _filterMode) {
	textures[channelName] = new Texture(path, _wrapParam, _filterMode);


	
}

void  Material::AddTexture(const std::string& typeName, std::vector<int> textureIDS) {
	textures_IndexBased[typeName] = textureIDS;
}

void Material::Bind() const {
	if (shader) {

	BindTextures();
	
	shader->Activate();
	}


}

void Material::Bind(Shader& shader,TextureLoader& loader) const {
		shader.Activate();
		unsigned int channel = 0;
		for (auto& element : textures_IndexBased) {

			for (int i = 0; i < element.second.size(); i++) {
				std::string name = element.first + std::to_string(i);
				shader.SetInt(name, channel);
				loader.linkedTextures[element.first][element.second[i]]->Bind(channel);
				channel++;
			}
		}
		
	
}



void Material::BindTextures() const {
	if (shader) {

		shader->Activate();
		unsigned int channel = 0;
		for (auto& x : textures) {
			shader->SetInt(x.first, channel);
			x.second->Bind(channel);
			channel++;
		}
		shader->Deactivate();
	}
}





Material::~Material() {
	delete shader;
	for (auto& x : textures) {
		
		delete x.second;
		
	}
	
}