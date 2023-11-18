#pragma once
#include "TextureLoader.h"
#include "Mesh.h"
#include "Camera.h"
class Model {
public:
	std::vector<Mesh*> meshes;
	std::string directory;
	bool gammaCorrection;

	Model(const std::string& path, bool gamma = false) : gammaCorrection(gamma), textureLoader(new TextureLoader()) {
		LoadModel(path);
	}
	~Model() {
		delete textureLoader;

		for (auto& mesh_ : meshes) {
			delete mesh_;
		}
	}

	void RenderModel(Camera& camera, Shader* shader) {
		for (unsigned int i = 0; i < meshes.size(); i++) {
			meshes[i]->Draw(*shader, *textureLoader);
		}

	}
private:
	TextureLoader* textureLoader;
	void LoadModel(const std::string& path) {
		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

		// error handling
		if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
			std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
			return;
		}
		// get dir 
		directory = path.substr(0, path.find_last_of('/'));

		ProcessNode(scene->mRootNode, scene);

		
	}
	// recursive load meshes --------------------------------------------------------------------------
	void ProcessNode(aiNode* node, const aiScene* scene) {

		for (unsigned int i = 0; i < node->mNumMeshes; i++) {
			// node only has indices
			aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
			meshes.push_back(ProcessMesh(mesh, scene));
		}
		for (unsigned int i = 0; i < node->mNumChildren; i++) {
			// do the same thing for all children and for their children
			ProcessNode(node->mChildren[i], scene);
		}


	}
	Mesh* ProcessMesh(aiMesh* mesh, const aiScene* scene) {

		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		//load vertex
		for (unsigned int i = 0; i < mesh->mNumVertices; i++) {

			Vertex vertex;

			glm::vec3 vector;

			vector.x = mesh->mVertices[i].x;
			vector.y = mesh->mVertices[i].y;
			vector.z = mesh->mVertices[i].z;
			vertex.Position = vector;

			if (mesh->HasNormals()) {
				vector.x = mesh->mNormals[i].x;
				vector.y = mesh->mNormals[i].y;
				vector.z = mesh->mNormals[i].z;
				vertex.Normal = vector;
			}

			if (mesh->mTextureCoords[0]) {
				glm::vec2 uv;

				uv.x = mesh->mTextureCoords[0][i].x;

				uv.y = mesh->mTextureCoords[0][i].y;
				vertex.TexCoords = uv;

				// tangent
				vector.x = mesh->mTangents[i].x;
				vector.y = mesh->mTangents[i].y;
				vector.z = mesh->mTangents[i].z;
				vertex.Tangent = vector;
				// biTangent
				vector.x = mesh->mBitangents[i].x;
				vector.y = mesh->mBitangents[i].y;
				vector.z = mesh->mBitangents[i].z;
				vertex.Bitangent = vector;

			}
			else {
				vertex.TexCoords = glm::vec2(0.0f, 0.0f);
			}

			vertices.push_back(vertex);
		}

		//load indices (faces)
		for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
			aiFace face = mesh->mFaces[i];
			// get face indices and set them
			for (unsigned int k = 0; k < face.mNumIndices; k++) {
				indices.push_back(face.mIndices[k]);
			}
		}
		// process materials
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

		Material* mesh_material = new Material();

		std::vector<int> diffuseTextures = textureLoader->loadTextures(material, aiTextureType_DIFFUSE, directory, "material.diffuse");
		
		std::vector<int> specularTextures = textureLoader->loadTextures(material, aiTextureType_SPECULAR, directory, "material.specular");

		std::vector<int> normalMaps = textureLoader->loadTextures(material, aiTextureType_HEIGHT, directory, "material.normal");

		std::vector<int> heightMaps = textureLoader->loadTextures(material, aiTextureType_AMBIENT, directory, "material.height");

	//	textureLoader->PrintAllTexturesLoaded();
		mesh_material->AddTexture("material.diffuse", diffuseTextures);
		mesh_material->AddTexture("material.specular", specularTextures);
		mesh_material->AddTexture("material.normal", normalMaps);
		mesh_material->AddTexture("material.height", heightMaps);

		return new Mesh(vertices, indices, mesh_material);

	}




};