//
// Created by Vinayak Regmi on 28/04/2025.
//

#include "Renderer.h"

namespace Render {


    void Renderer::setFlags() {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    }

    void Renderer::glfwInitialize() {
        if (!glfwInit()) {
            DebugLog::EngineLog::printError("GLFW initialization failed");
            DebugLog::EngineLog::setFlag(5);
            exit(EXIT_FAILURE);
        }
    }

    void Renderer::glewInitialize() {
        if (glewInit()!= GLEW_OK) {
            DebugLog::EngineLog::printError("GLEW initialization failed");
            DebugLog::EngineLog::setFlag(6);
            exit(EXIT_FAILURE);
        }
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);


    }
    void Renderer::initialize() {
        glfwInitialize();
        setFlags();
        window = glfwCreateWindow( Utils::GlobalConstants::width, Utils::GlobalConstants::height, "OpenGL Renderer", NULL, NULL);
        if (!window) {
            DebugLog::EngineLog::printError("GLFW initialization failed");
            DebugLog::EngineLog::setFlag(7);
            return;
        }
        glfwMakeContextCurrent(window);
        glewInitialize();
        int bw, bh;
        glfwGetFramebufferSize(window, &bw, &bh);
        glViewport(0,0, bw, bh);

    }

    void Renderer::miscInitialize() {}

    Renderer::Renderer(): dirLight(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, -1.0f, 1.0f),0.35f, 0.65f) {
        initialize();
    }

    void Renderer::setClearColor(float r, float g, float b) {
        clearColor[0]=r;
        clearColor[1]=g;
        clearColor[2]=b;

    }

   void Renderer::render(Basic::GameObject** game_objects, int count,Matrix::Camera *camera) {

        glfwPollEvents();
        glEnable(GL_DEPTH_TEST);
        glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        for(int i=0; i<count; i++) {
            game_objects[i]->drawObject(camera, &dirLight);
        }

    }
} // Render