cmake_minimum_required(VERSION 3.10)
project(OpenGLProject)

# Configure GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(deps/glfw)

# Define project files
set(SOURCES src/main.cpp deps/glad/src/glad.c)

add_executable(${PROJECT_NAME} ${SOURCES})

# Point to header locations
target_include_directories(${PROJECT_NAME} PRIVATE 
    deps/glfw/include 
    deps/glad/include
)

# Link GLFW and OS-specific libraries
target_link_libraries(${PROJECT_NAME} glfw)
if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} GL X11 lpthread ldlt lXinerama lXcursor)
endif()
