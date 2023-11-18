#pragma once
#include "Common.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <vector>
#include "Material.h"
#include "VertexArray.h"



class Mesh {
public:
    // mesh Data
    std::vector<Vertex>       vertices;
    std::vector<unsigned int> indices;
    
   
    Material* material;
   
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, Material* material) : vao(nullptr), vbo(nullptr), ibo(nullptr)
    {
        this->vertices = vertices;
        this->indices = indices;
        this->material = material;
       // material = new Material();
        // now that we have all the required data, set the vertex buffers and its attribute pointers.
        setupMesh();
    }
    ~Mesh() {
        vao->~VertexArray();
        vbo->~VertexBuffer();
        ibo->~IndexBuffer();
        delete material;
    }

    // render the mesh
    
    void Draw(Shader& shader, TextureLoader& textureLoader) {
        material->Bind(shader,textureLoader);
        vao->Bind();
        glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
        vao->UnBind();      
    }

  

private:
    VertexArray* vao;
    VertexBuffer* vbo;
    IndexBuffer* ibo;

    // initializes all the buffer objects/arrays
    void setupMesh()
    {
        // create buffers/arrays
        vao = new VertexArray();
        vbo = new VertexBuffer(&vertices[0], vertices.size() * sizeof(Vertex));
        ibo = new IndexBuffer(&indices[0], indices.size() * sizeof(unsigned int));

        // set the vertex attribute pointers
        vao->Bind();
        VertexArrayAttribute attributes = VertexArrayAttribute();
        attributes.PushAttributef(3);
        attributes.PushAttributef(3);
        attributes.PushAttributef(2);
        attributes.PushAttributef(3);
        attributes.PushAttributef(3);
        vao->AddVertexArrayAttributef(*vbo, *ibo, attributes);
        
        vao->UnBind();
        vbo->UnBind();
        ibo->UnBind();
    }
};
