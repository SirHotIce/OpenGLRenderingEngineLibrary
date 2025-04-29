//
// Created by Vinayak Regmi on 28/04/2025.
//

#ifndef RENDERER_H
#define RENDERER_H
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


#include "Frame.h"
#include "../Basic/GameObject.h"
#include "../Basic/Light.h"
#include "../Matrix/Camera.h"
#include "../DebugLog/EngineLog.h"

namespace Render {

class Renderer {
private:

    bool initialized;
    GLFWwindow* window;
    Basic::Light dirLight;
    float clearColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
//flags only use after the pp stack is built
    bool postProcess;
    bool fxaa;
    bool depthOfField;
    bool outline;

    //the renderer takes in a list of gameobjects and camera, we take the materials shader to render the specific gameobject
    //update fns for width height and aspect
//construct the renderer based on the width and height, basically empty initialize, and there needs to be an exposed init fn, that initializes glew and sets up fbo and empty texture and pixel data
    //optional: have a screenshot that returns the cached pixeldata
    //light are left to bind
    //shaders are left

    void glfwInitialize();
    void glewInitialize();
    void setFlags();
    void miscInitialize();
    void initialize();


public:

    Renderer();
    void setClearColor(float r, float g, float b);
    std::vector<unsigned char> render(Basic::GameObject** game_objects, int count,Matrix::Camera* camera, Frame* frame);

};

} // Render

#endif //RENDERER_H
