
# 📖 OpenGLRenderEngine DLL Basic Usage Guide

Welcome!  
This DLL provides a simple interface to manage **game objects**, **cameras**, and **render frames** using **OpenGL**, exported for easy use in external applications (e.g., F#, C#, C++ frontend).

📥 **Before you start, download the DLL here:**  
[🔗 OpenGLRenderEngine.zip (GitHub Link)](https://github.com/SirHotIce/OpenGLRenderingEngineLibrary/blob/main/OpenGLRenderEngine.zip)

---

## 📦 Summary of What’s Inside

- ✅ Create and control **GameObjects**
- ✅ Create and control a **Camera**
- ✅ Create a **Frame** to render into
- ✅ Create a **Renderer**
- ✅ Render **GameObjects** into a **Frame** and get raw pixel data
- ✅ Built-in **logging** functions for debug, warnings, and errors

---

## 📚 Quick Start Workflow

| Step | What to Call |
|:-----|:-------------|
| 1 | `_createRenderer()` |
| 2 | `_createCamera(fov, aspect, near, far)` |
| 3 | `_createFrame(width, height)` |
| 4 | `_createGameObject(name, meshPath, diffuse, normal, metallic, roughness)` |
| 5 | Use `_moveGameObject`, `_rotateGameObject`, `_scaleGameObject` |
| 6 | Call `_renderFrame(renderer, gameObjects, count, camera, frame)` |
| 7 | Access rendered pixel data via `PixelData.p` and size via `PixelData.count` |

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
| `Camera* _createCamera(fov, aspect, near, far)` | Create a perspective camera |
| `void _setCameraFov(camera, fov)` | Set field of view |
| `void _setCameraAspect(camera, aspect)` | Set aspect ratio |
| `void _setCameraNear(camera, near)` | Set near plane distance |
| `void _setCameraFar(camera, far)` | Set far plane distance |
| `void _setCameraPosition(camera, x, y, z)` | Set camera position |
| `void _setCameraRotation(camera, pitch, yaw)` | Set camera rotation (Euler) |
| `Vector3Export _getCameraPosition(camera)` | Get current camera position |
| `Vector3Export _getCameraRotation(camera)` | Get current camera rotation |

---

### 🎮 GameObject

| Function | Purpose |
|:---------|:--------|
| `GameObject* _createGameObject(name, meshPath, diffusePath, normalPath, metallicPath, roughnessPath)` | Create a 3D object with material maps |
| `void _moveGameObject(object, x, y, z)` | Set object position |
| `void _rotateGameObject(object, x, y, z)` | Set object rotation |
| `void _scaleGameObject(object, x, y, z)` | Set object scale |
| `Vector3Export _getGameObjectPosition(object)` | Get object position |
| `Vector3Export _getGameObjectRotation(object)` | Get object rotation |
| `Vector3Export _getGameObjectScale(object)` | Get object scale |

---

### 🖼 Frame

| Function | Purpose |
|:---------|:--------|
| `Frame* _createFrame(width, height)` | Create a framebuffer target |
| `void _updateFrameSize(frame, width, height)` | Resize framebuffer resolution |

---

### 🎨 Rendering

| Function | Purpose |
|:---------|:--------|
| `PixelData _renderFrame(renderer, gameObjects, count, camera, frame)` | Render the current scene and return pixel buffer + count |

> 🔹 **Note**: `PixelData` contains:
```cpp
struct PixelData {
    unsigned char* p; // Pointer to raw RGBA pixel buffer
    int count;        // Total number of bytes (width × height × 4)
};
```

---

### 🛠 Debug Logging

| Function | Purpose |
|:---------|:--------|
| `void _print(message)` | Print regular log message |
| `void _printWarning(message)` | Print warning log |
| `void _printError(message)` | Print error log |
| `const char* _getLog()` | Get accumulated info/debug log |
| `const char* _getWarningLog()` | Get accumulated warnings |
| `const char* _getErrorLog()` | Get accumulated errors |
| `int _getErrorFlag()` | Returns non-zero if any error was logged |

---

## 📦 Data Types

### `Vector3Export`

Simple struct for position, rotation, or scale:

```cpp
struct Vector3Export {
    float x;
    float y;
    float z;
};
```

### `PixelData`

Returned by the render function:

```cpp
struct PixelData {
    unsigned char* p; // Pointer to RGBA pixel buffer
    int count;        // Total number of bytes (width * height * 4)
};
```