cmake_minimum_required(VERSION 3.29)
project(OpenGLRenderEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(OpenGLRenderEngine
        src/DebugLog/EngineLog.cpp
        src/DebugLog/EngineLog.h
        src/MeshHandling/Vertex.h
        src/MeshHandling/Texture.h
        src/Importer/MeshImporter.cpp
        src/Importer/MeshImporter.h
        src/Importer/TextureImporter.cpp
        src/Importer/TextureImporter.h
        src/Matrix/Camera.cpp
        src/Matrix/Camera.h
        src/Matrix/Transform.cpp
        src/Matrix/Transform.h
        src/Basic/GameObject.cpp
        src/Basic/GameObject.h
        src/MeshHandling/Material.cpp
        src/MeshHandling/Material.h
        src/Utils/ShaderTypes.h
        src/MeshHandling/Mesh.h
        src/Utils/stb_image.h
        src/Render/ShaderCache.cpp
        src/Render/ShaderCache.h
        src/Utils/Vector3.h
        src/Render/ShaderCompiler.cpp
        src/Render/ShaderCompiler.h
        src/Utils/GlobalConstants.h
        src/Render/ShaderErrorHandler.cpp
        src/Render/ShaderErrorHandler.h
        src/Basic/Light.cpp
        src/Basic/Light.h
        src/Render/Renderer.cpp
        src/Render/Renderer.h
        src/Render/Frame.cpp
        src/Render/Frame.h
        src/main.cpp
)
#link opengl
find_package(OpenGL REQUIRED)
target_include_directories(OpenGLRenderEngine PRIVATE external)
target_link_libraries(OpenGLRenderEngine OpenGL::GL)
# === Detect Platform ===
if (APPLE)
    set(PLATFORM "mac")
elseif (WIN32)
    set(PLATFORM "win")
endif()

# === GLEW ===
set(GLEW_DIR "${CMAKE_SOURCE_DIR}/external/glew_${PLATFORM}")
set(GLEW_INCLUDE_DIR "${GLEW_DIR}/include")
set(GLEW_LIBRARY_DIR "${GLEW_DIR}/lib")
if (APPLE)
    set(GLEW_LIBRARY_FILE "${GLEW_LIBRARY_DIR}/libGLEW.dylib")
    set(GLEW_COPY_FILE "${GLEW_LIBRARY_FILE}")
else()
    set(GLEW_LIBRARY_DIR "${GLEW_LIBRARY_DIR}/Release/X64")
    set(GLEW_LIBRARY_FILE "${GLEW_LIBRARY_DIR}/glew32.lib")
    set(GLEW_COPY_FILE "${GLEW_DIR}/bin/Release/x64/glew32.dll")
endif()

target_include_directories(OpenGLRenderEngine PRIVATE ${GLEW_INCLUDE_DIR})
target_link_libraries(OpenGLRenderEngine ${GLEW_LIBRARY_FILE})
add_custom_command(TARGET OpenGLRenderEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${GLEW_COPY_FILE}"
        $<TARGET_FILE_DIR:OpenGLRenderEngine>
)

# === GLFW ===
set(GLFW_DIR "${CMAKE_SOURCE_DIR}/external/glfw_${PLATFORM}")
set(GLFW_INCLUDE_DIR "${GLFW_DIR}/include")
if (APPLE)
    set(GLFW_LIBRARY_FILE "${GLFW_DIR}/lib-arm64/libglfw.3.dylib")
    set(GLFW_COPY_FILE "${GLFW_LIBRARY_FILE}")
else()
    set(GLFW_LIBRARY_DIR "${GLFW_DIR}/lib-vc2022")
    set(GLFW_LIBRARY_FILE "${GLFW_LIBRARY_DIR}/glfw3.lib")
    set(GLFW_COPY_FILE "${GLFW_LIBRARY_DIR}/glfw3.dll")
endif()

target_include_directories(OpenGLRenderEngine PRIVATE ${GLFW_INCLUDE_DIR})
target_link_libraries(OpenGLRenderEngine ${GLFW_LIBRARY_FILE})
add_custom_command(TARGET OpenGLRenderEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${GLFW_COPY_FILE}"
        $<TARGET_FILE_DIR:OpenGLRenderEngine>
)

# === ASSIMP ===
set(ASSIMP_DIR "${CMAKE_SOURCE_DIR}/external/assimp_${PLATFORM}")
set(ASSIMP_INCLUDE_DIR "${ASSIMP_DIR}/include")
if (APPLE)
    set(ASSIMP_LIBRARY_FILE "${ASSIMP_DIR}/lib/libassimp.5.4.3.dylib")
    set(ASSIMP_COPY_FILE "${ASSIMP_LIBRARY_FILE}")
else()
    set(ASSIMP_LIBRARY_FILE "${ASSIMP_LIBRARY_DIR}/assimp-vc143-mt.lib")
    set(ASSIMP_COPY_FILE "${ASSIMP_DIR}/bin/x64/assimp-vc143-mt.dll")
endif ()

target_include_directories(OpenGLRenderEngine PRIVATE ${ASSIMP_INCLUDE_DIR})
target_link_libraries(OpenGLRenderEngine ${ASSIMP_LIBRARY_FILE})
add_custom_command(TARGET OpenGLRenderEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${ASSIMP_COPY_FILE}"
        $<TARGET_FILE_DIR:OpenGLRenderEngine>
)

# === GLM (Header Only) ===
set(GLM_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/external/glm")
target_include_directories(OpenGLRenderEngine PRIVATE ${GLM_INCLUDE_DIR})

# === Shader Copy Targets ===
set(SHADER_DIRECTORY "${CMAKE_SOURCE_DIR}/shaders")
set(SHADER_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/shaders")

add_custom_target(CopyShaders ALL
        COMMAND ${CMAKE_COMMAND} -E remove_directory "${SHADER_OUTPUT_DIRECTORY}"
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${SHADER_DIRECTORY}" "${SHADER_OUTPUT_DIRECTORY}"
        COMMENT "Refreshing and copying shader folder..."
)
add_dependencies(OpenGLRenderEngine CopyShaders)
