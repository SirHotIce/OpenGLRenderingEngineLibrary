#include "library.h"

#include <iostream>

void _print(std::string message) {
    DebugLog::EngineLog::print(message);
}

void _printWarning(std::string message) {
    DebugLog::EngineLog::printWarning(message);
}

void _printError(std::string message) {
    DebugLog::EngineLog::printError(message);
}

const char* _getLog() {
    return DebugLog::EngineLog::getEngineLog().c_str();
}

const char* _getWarningLog() {
    return DebugLog::EngineLog::getEngineWarningLog().c_str();
}

const char* _getErrorLog() {
    return DebugLog::EngineLog::getEngineErrorLog().c_str();
}

int _getErrorFlag() {
    return  DebugLog::EngineLog::getErrorFlag();
}

Matrix::Camera * _createCamera(float fov, float aspect, float near, float far) {
    return new Matrix::Camera(fov, aspect, near, far);
}

void _setCameraFov(Matrix::Camera *cam, float fov) {
    cam->setFov(fov);
}

void _setCameraAspect(Matrix::Camera *cam, float aspect) {
    cam->setAspect(aspect);
}

void _setCameraNear(Matrix::Camera *cam, float near) {
    cam->setNear(near);
}

void _setCameraFar(Matrix::Camera *cam, float far) {
    cam->setFar(far);
}

void _setCameraPosition(Matrix::Camera *cam, float x, float y, float z) {
    cam->setPosition(x, y, z);
}

void _setCameraRotation(Matrix::Camera *cam, float pitch, float yaw) {
    cam->setRotation(pitch, yaw);
}

Vector3Export _getCameraPosition(Matrix::Camera *cam) {
    Vector3Export vec3;
    vec3.x = cam->getPositionOut().x;
    vec3.y = cam->getPositionOut().y;
    vec3.z = cam->getPositionOut().z;
    return vec3;
}

Vector3Export _getCameraRotation(Matrix::Camera *cam) {
    Vector3Export vec3;
    vec3.x= cam->getRotationOut().x;
    vec3.y= cam->getRotationOut().y;
    vec3.z= cam->getRotationOut().z;
    return vec3;
}

Basic::GameObject * _createGameObject(const char *name, const char *meshPath, const char *diffuseMapPath,
    const char *normalMapPath, const char *metallicMapPath, const char *roughnessMapPath) {
    return new Basic::GameObject(name, meshPath, diffuseMapPath, normalMapPath, roughnessMapPath, metallicMapPath,Utils::BASIC_PHONG);
}

void _moveGameObject(Basic::GameObject *gO, float x, float y, float z) {
    gO->getTransform().setPosition(x, y, z);
}

void _rotateGameObject(Basic::GameObject *gO, float x, float y, float z) {
    gO->getTransform().setRotation(x, y, z);
}

void _scaleGameObject(Basic::GameObject *gO, float x, float y, float z) {
    gO->getTransform().setScale(x, y, z);
}

Vector3Export _getGameObjectPosition(Basic::GameObject *gO) {
    Vector3Export vec3;
    vec3.x = gO->getTransform().getPosition().x;
    vec3.y = gO->getTransform().getPosition().y;
    vec3.z = gO->getTransform().getPosition().z;
    return vec3;
}

Vector3Export _getGameObjectRotation(Basic::GameObject *gO) {
    Vector3Export vec3;
    vec3.x = gO->getTransform().getRotation().x;
    vec3.y = gO->getTransform().getRotation().y;
    vec3.z = gO->getTransform().getRotation().z;
    return vec3;
}

Vector3Export _getGameObjectScale(Basic::GameObject *gO) {
    Vector3Export vec3;
    vec3.x = gO->getTransform().getScale().x;
    vec3.y = gO->getTransform().getScale().y;
    vec3.z = gO->getTransform().getScale().z;
    return vec3;
}

Render::Frame * _createFrame(int width, int height) {
    return new Render::Frame(width, height);
}

void _updateFrameSize(Render::Frame *frame, int width, int height) {
    frame->setSize(width, height);
}

Render::Renderer * _createRenderer() {
    return new Render::Renderer();
}

void _setClearColor(Render::Renderer *renderer, float r, float g, float b) {
    renderer->setClearColor(r, g, b);
}

unsigned char * _renderFrame(Render::Renderer *renderer, Basic::GameObject **game_objects, int count,
    Matrix::Camera *camera, Render::Frame *frame) {
    return renderer->render(game_objects, count, camera, frame).data();
}
