//
// Created by Vinayak Regmi on 23/04/2025.
//

#include "MeshImporter.h"


namespace Importer {

    MeshHandling::Mesh MeshImporter::importMesh(const std::string &path) {
        MeshHandling::Mesh mesh;
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path.c_str(),aiProcess_Triangulate|aiProcess_GenSmoothNormals|aiProcess_OptimizeMeshes);
        if (!scene) {
            DebugLog::EngineLog::printWarning("Failed to load mesh");
            DebugLog::EngineLog::printWarning(importer.GetErrorString());
        }
        for (int i= 0; i<scene->mMeshes[0]->mNumVertices; i++) {
            aiVector3D loadedVertex = scene->mMeshes[0]->mVertices[i];
            MeshHandling::Vertex vertex;
            vertex.Position = glm::vec3(loadedVertex.x, loadedVertex.y, loadedVertex.z);
            aiVector3D loadedNormal = scene->mMeshes[0]->mNormals[i];
            vertex.Normal = glm::vec3(loadedNormal.x, loadedNormal.y, loadedNormal.z);
            aiVector3D loadedUVS= scene->mMeshes[0]->mTextureCoords[0][i];
            vertex.TexCoords = glm::vec2(loadedUVS.x, loadedUVS.y);

            mesh.vertices.push_back(vertex);
        }
        if (scene->mMeshes[0]->mNumFaces>0) {
            for (int i= 0; i<scene->mMeshes[0]->mNumFaces; i++) {
                aiFace face = scene->mMeshes[0]->mFaces[i];
                for (int j= 0; j<face.mNumIndices; j++) {
                    mesh.indices.push_back(face.mIndices[j]);
                }
            }
        }
        return mesh;
    }
} // Importer