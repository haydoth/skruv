#include "core/WindowModule.h"

#include <iostream>

namespace Skruv 
{
    bool WindowModule::Init() 
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
        
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
        
        m_Handle.reset(glfwCreateWindow(1280, 720, "SKRUV", NULL, NULL));
        if (GetHandle() == NULL)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return false;
        }
        
        glfwMakeContextCurrent(GetHandle());
        glfwSetFramebufferSizeCallback(GetHandle(), [](GLFWwindow* window, int width, int height)
                                       {
                                           glViewport(0, 0, width, height);
                                       });
        
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return false;
        } 
        
        glEnable(GL_DEPTH_TEST);
        
        return true;
    }
    
    void WindowModule::Update() 
    {
        // TODO: move this clearing code somewhere else
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glfwSwapBuffers(GetHandle());
        glfwPollEvents();
    }
    
    void WindowModule::Exit() 
    {
        glfwDestroyWindow(GetHandle());
        glfwTerminate();
    }
    
    bool WindowModule::GetWindowShouldClose() 
    {
        return glfwWindowShouldClose(GetHandle());
    }
    
    GLFWwindow* WindowModule::GetHandle() 
    {
        return m_Handle.get();
    }
};