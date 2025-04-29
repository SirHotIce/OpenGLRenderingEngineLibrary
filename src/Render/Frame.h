//
// Created by Vinayak Regmi on 28/04/2025.
//

#ifndef FRAME_H
#define FRAME_H
#include <vector>
#include <GL/glew.h>

namespace Render {

class Frame {
private:
    GLuint FBO, texture, depthTex;
    GLint width, height;
    std::vector<unsigned char> pixelData;
    void setupFramebuffer();
public:
    Frame(int width, int height);
    void clearBuffer();
    void setSize(int width, int height);
    std::vector<unsigned char> getPixelData();

    void attach();
    void detach();
    std::vector<unsigned char> screenshot();
};

} // Render

#endif //FRAME_H
