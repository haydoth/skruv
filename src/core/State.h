/* date = June 25th 2023 10:32 pm */

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Base.h"

#include "WindowModule.h"
#include "scene/SceneModule.h"
#include "render/RenderModule.h"

#ifndef _STATE_H
#define _STATE_H

namespace Skruv {
    
    class State {
        
        public:
        
        void Run();
        State();
        
        // ideally these shorthand member variables should
        // get the return value of a lambda function 
        Scene* scene;
        ShaderLibrary* shaderLibrary;
        
        private:
        
        bool LoadModules();
        void Start();
        void Update();
        void Exit();
        
        bool m_LoadedModules;
        
        WindowModule m_WindowModule;
        SceneModule m_SceneModule;
        RenderModule m_RenderModule;
    };
}

#endif //_STATE_H
