#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main() {
    // 1. Initialize GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    // 2. Configure GLFW (OpenGL 3.3 Core Profile)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 3. Create Window
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL C", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // 4. Initialize GLAD
    // In C, the cast to (GLADloadproc) is still required
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        fprintf(stderr, "Failed to initialize GLAD\n");
        return -1;
    }

    // 5. Render Loop
    while (!glfwWindowShouldClose(window)) {
        // Poll events (keys, mouse, etc.)
        glfwPollEvents();

        // Clear the screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // 6. Clean up
    glfwTerminate();
    return 0;
}
