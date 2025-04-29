
# 📖 OpenGLRenderEngine DLL Basic Usage Guide

Welcome!  
This DLL provides a simple interface to manage **game objects**, **cameras**, and **render frames** using **OpenGL**, exported for easy use in external applications (e.g., F#, C#, C++ frontend).
Before you start dowmload the dll file here: https://github.com/SirHotIce/OpenGLRenderingEngineLibrary/blob/main/OpenGLRenderEngine.zip
---

## 📦 Summary of What’s Inside

- ✅ Create and control **GameObjects**
- ✅ Create and control a **Camera**
- ✅ Create a **Frame** to render into
- ✅ Create a **Renderer**
- ✅ Render **GameObjects** into a **Frame** and get raw pixel data
- ✅ Built-in **logging** functions for debug/warnings/errors

---

## 📚 Quick Start Workflow

| Step | What to Call |
|:-----|:-------------|
| 1 | `_createRenderer()` |
| 2 | `_createCamera(fov, aspect, near, far)` |
| 3 | `_createFrame(width, height)` |
| 4 | `_createGameObject(name, meshPath, diffuse, normal, metallic, roughness)` |
| 5 | Setup object transforms (move, rotate, scale) |
| 6 | Call `_renderFrame(renderer, gameObjects, count, camera, frame)` |
| 7 | Get a `unsigned char*` array of pixel data |

---

## 📜 API Functions

### 🖥 Renderer

| Function | Purpose |
|:---------|:--------|
| `Render::Renderer* _createRenderer()` | Create a new renderer instance |
| `void _setClearColor(renderer, r, g, b)` | Set background clear color (RGB) |

---

### 📸 Camera

| Function | Purpose |
|:---------|:--------|
| `Camera* _createCamera(fov, aspect, near, far)` | Create a camera |
| `void _setCameraFov(camera, fov)` | Set field of view |
| `void _setCameraAspect(camera, aspect)` | Set aspect ratio |
| `void _setCameraNear(camera, near)` | Set near plane distance |
| `void _setCameraFar(camera, far)` | Set far plane distance |
| `void _setCameraPosition(camera, x, y, z)` | Move camera position |
| `void _setCameraRotation(camera, pitch, yaw)` | Rotate camera (pitch, yaw) |
| `Vector3Export _getCameraPosition(camera)` | Get camera position |
| `Vector3Export _getCameraRotation(camera)` | Get camera rotation |

---

### 🎮 GameObject

| Function | Purpose |
|:---------|:--------|
| `GameObject* _createGameObject(name, meshPath, diffusePath, normalPath, metallicPath, roughnessPath)` | Create a 3D object with material maps |
| `void _moveGameObject(object, x, y, z)` | Move object |
| `void _rotateGameObject(object, x, y, z)` | Rotate object |
| `void _scaleGameObject(object, x, y, z)` | Scale object |
| `Vector3Export _getGameObjectPosition(object)` | Get object position |
| `Vector3Export _getGameObjectRotation(object)` | Get object rotation |
| `Vector3Export _getGameObjectScale(object)` | Get object scale |

---

### 🖼 Frame

| Function | Purpose |
|:---------|:--------|
| `Frame* _createFrame(width, height)` | Create a framebuffer |
| `void _updateFrameSize(frame, width, height)` | Resize a framebuffer |

---

### 🎨 Rendering

| Function | Purpose |
|:---------|:--------|
| `unsigned char* _renderFrame(renderer, gameObjects, count, camera, frame)` | Render scene to frame, returns pointer to RGBA pixel array |

---

### 🛠 Debug Logging

| Function | Purpose |
|:---------|:--------|
| `void _print(message)` | Print regular log |
| `void _printWarning(message)` | Print warning log |
| `void _printError(message)` | Print error log |
| `const char* _getLog()` | Get accumulated log |
| `const char* _getWarningLog()` | Get accumulated warnings |
| `const char* _getErrorLog()` | Get accumulated errors |
| `int _getErrorFlag()` | Check if any error has occurred |

---

## 📦 Data Types

### Vector3Export

Simple struct for position, rotation, and scale data:

```cpp
struct Vector3Export {
    float x;
    float y;
    float z;
};
```

- Returned by value safe, no pointers needed.

---

## ⚡ Important Notes

- `unsigned char*` pixel data returned by `_renderFrame` is **RGBA format**, size = `width × height × 4`.
- Memory management:
    - You **own** the camera, gameobject, frame, renderer pointers.
    - **Always reuse** created objects instead of creating too many in a loop.
- For logging, call `_print`, `_printWarning`, or `_printError` from your app if needed.

---

## 📋 Minimum Example (Pseudo-F# or C)

```c
Renderer* renderer = _createRenderer();
Camera* camera = _createCamera(60.0f, 1.33f, 0.1f, 100.0f);
Frame* frame = _createFrame(800, 600);

GameObject* cube = _createGameObject("Cube", "cube.obj", "diffuse.png", "normal.png", "metallic.png", "roughness.png");

_moveGameObject(cube, 0.0f, 0.0f, -5.0f);

GameObject* objects[] = { cube };
unsigned char* pixelData = _renderFrame(renderer, objects, 1, camera, frame);

// Use pixelData...
```

---

# 📢 Quick Setup Tips

| Step | Note |
|:-----|:-----|
| DLL and `.lib` must be copied near your executable | (or configure linker properly) |
| Always match your platform (x64 vs x86) | |
| External dependencies are statically or dynamically linked (GLEW, GLFW, ASSIMP) | |
| If you need shader files, they are automatically copied by the build system | |

---

# 🎯 Final Good Luck!

Enjoy building apps with **OpenGLRenderEngine.dll** 🚀  
Simple design easy to extend later!

---
