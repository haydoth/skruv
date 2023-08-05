/* date = July 31st 2023 8:03 pm */

#ifndef _WINDOW_MODULE_H
#define _WINDOW_MODULE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <memory>

struct DestroyGLFWwindow {
    
    void operator()(GLFWwindow* ptr){
        glfwDestroyWindow(ptr);
    }
    
};

namespace Skruv 
{
    class State;
    
    class WindowModule {
        
        public:
        
        WindowModule() {}
        
        bool GetWindowShouldClose();
        GLFWwindow* GetHandle();
        
        private:
        
        friend class State;
        
        bool Init();
        void Update();
        void Exit();
        
        std::unique_ptr<GLFWwindow, DestroyGLFWwindow> m_Handle;
    };
}
#endif //_WINDOW_H
