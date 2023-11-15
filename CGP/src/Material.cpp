#include "Material.h"


void Material::AddTexture(const std::string& channelName,const std::string& path, GLint _wrapParam, GLint _filterMode) {
	textures[channelName] = new Texture(path, _wrapParam, _filterMode);


	
}

void Material::Bind() const {
	BindTextures();
	shader->Activate();


}

void Material::BindTextures() const {
	shader->Activate();
	unsigned int channel = 0;
	for (auto& x : textures) {
		shader->SetInt(x.first, channel);
		x.second->Bind(channel);
		channel++;
	}
	shader->Deactivate();
}


Material::~Material() {
	delete shader;
	for (auto& x : textures) {
		
		delete x.second;
		
	}
	
}