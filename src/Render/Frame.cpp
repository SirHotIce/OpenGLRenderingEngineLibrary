//
// Created by Vinayak Regmi on 28/04/2025.
//

#include "Frame.h"

#include "../DebugLog/EngineLog.h"

namespace Render {
    void Frame::setupFramebuffer() {
        glGenFramebuffers(1, &FBO);
        glBindFramebuffer(GL_FRAMEBUFFER, FBO);

        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0 , GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture, 0);

        // glGenRenderbuffers(1, &depth);
        // glBindRenderbuffer(GL_RENDERBUFFER, depth);
        // glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
        // glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, depth);

        glGenTextures(1, &depthTex);
        glBindTexture(GL_TEXTURE_2D, depthTex);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, width, height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthTex, 0);

        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
            DebugLog::EngineLog::printError("Framebuffer not complete!");
            DebugLog::EngineLog::setFlag(12);
        }else {
            DebugLog::EngineLog::print("Framebuffer made successfully.");
        }
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    Frame::Frame(int width, int height) {
        this->width = width;
        this->height = height;
        setupFramebuffer();
    }

    void Frame::attach() {
        glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    }

    void Frame::detach() {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    std::vector<unsigned char> Frame::getPixelData() {
        pixelData.clear();
        pixelData.resize(width * height * 3);
        glBindFramebuffer(GL_FRAMEBUFFER, FBO);
        glReadBuffer(GL_COLOR_ATTACHMENT0);
        glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixelData.data());
        return pixelData;
    }

    std::vector<unsigned char> Frame::screenshot() {
        return getPixelData();
    }

    void Frame::clearBuffer() {
        glBindFramebuffer(GL_FRAMEBUFFER, FBO);

        if (texture != 0) {
            glDeleteTextures(1, &texture);
            texture = 0;
        }

        if (depthTex != 0) {
            glDeleteTextures(1, &depthTex);
            depthTex = 0;
        }

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void Frame::setSize(int width, int height) {
        this->width = width;
        this->height = height;
        clearBuffer();
        setupFramebuffer();
    }


} // Render