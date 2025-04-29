//
// Created by Vinayak Regmi on 23/04/2025.
//

#ifndef MESHIMPORTER_H
#define MESHIMPORTER_H
#include "../MeshHandling/Mesh.h"
#include "../MeshHandling/Vertex.h"
#include  <iostream>
#include <GL/glew.h>
#include  <glm/glm.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "../DebugLog/EngineLog.h"

namespace Importer {

class MeshImporter {

public:
    static MeshHandling::Mesh importMesh(const std::string& path);
};

} // Importer

#endif //MESHIMPORTER_H
