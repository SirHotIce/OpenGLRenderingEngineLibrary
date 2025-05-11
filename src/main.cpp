#include <cstdio>

#include "Render/Renderer.h"

int main() {
    Render::Renderer *renderer = new Render::Renderer();
    Matrix::Camera camera(75, Utils::GlobalConstants::width/Utils::GlobalConstants::height, 0.1f, 100.0f);
    while(glfwWindowShouldClose(renderer->getWindow())) {
        renderer->render(nullptr, 0, &camera);
        std::cout<<DebugLog::EngineLog::getEngineErrorLog()<<std::endl;
        std::cout<<DebugLog::EngineLog::getEngineLog()<<std::endl;
    }
    printf("Hello, World!\n");
    return 1;
}
