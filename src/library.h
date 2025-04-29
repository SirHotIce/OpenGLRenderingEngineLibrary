#ifndef OPENGLRENDERENGINE_LIBRARY_H
#define OPENGLRENDERENGINE_LIBRARY_H
#include <cmath>
#include <string>

#include "Basic/GameObject.h"
#include "Utils/Vector3.h"
#include "Matrix/Camera.h"
#include "Render/Frame.h"
#include "Render/Renderer.h"

#ifdef _WIN32
  #define EXPORT_API __declspec(dllexport)
#else
  #define EXPORT_API __attribute__((visibility("default")))
#endif


extern "C" {
    struct Vector3Export {
        float x;
        float y;
        float z;
    };
    // Debug Log
    EXPORT_API void _print(std::string message);
    EXPORT_API void _printWarning(std::string message);
    EXPORT_API void _printError(std::string message);
    EXPORT_API const char* _getLog();
    EXPORT_API const char*  _getWarningLog();
    EXPORT_API const char* _getErrorLog();
    EXPORT_API int _getErrorFlag();

    //Camera
    EXPORT_API Matrix::Camera*  _createCamera(float fov, float aspect, float near, float far);
    EXPORT_API void _setCameraFov(Matrix::Camera* cam, float fov);
    EXPORT_API void _setCameraAspect(Matrix::Camera* cam, float aspect);
    EXPORT_API void _setCameraNear(Matrix::Camera* cam, float near);
    EXPORT_API void _setCameraFar(Matrix::Camera* cam, float far);
    EXPORT_API void _setCameraPosition(Matrix::Camera* cam, float x, float y, float z);
    EXPORT_API void _setCameraRotation(Matrix::Camera* cam, float pitch, float yaw);

    EXPORT_API Vector3Export _getCameraPosition(Matrix::Camera* cam);
    EXPORT_API Vector3Export _getCameraRotation(Matrix::Camera* cam);

    //Gameobject
    EXPORT_API Basic::GameObject* _createGameObject(const char* name,
    const char* meshPath,
    const char* diffuseMapPath,
    const char* normalMapPath,
    const char* metallicMapPath,
    const char* roughnessMapPath);
    EXPORT_API void _moveGameObject(Basic::GameObject* gO, float x, float y, float z);
    EXPORT_API void _rotateGameObject(Basic::GameObject* gO, float x, float y, float z);
    EXPORT_API void _scaleGameObject(Basic::GameObject* gO, float x, float y, float z);
    EXPORT_API Vector3Export _getGameObjectPosition(Basic::GameObject* gO);
    EXPORT_API Vector3Export _getGameObjectRotation(Basic::GameObject* gO);
    EXPORT_API Vector3Export _getGameObjectScale(Basic::GameObject* gO);

    //Frame

    EXPORT_API Render::Frame* _createFrame(int width, int height);
    EXPORT_API void _updateFrameSize(Render::Frame* frame, int width, int height);

    //Renderer
    EXPORT_API Render::Renderer* _createRenderer();
    EXPORT_API void _setClearColor(Render::Renderer* renderer, float r, float g, float b);
    EXPORT_API unsigned char* _renderFrame(Render::Renderer* renderer,Basic::GameObject** game_objects, int count,Matrix::Camera* camera, Render::Frame* frame);


}

#endif //OPENGLRENDERENGINE_LIBRARY_H
