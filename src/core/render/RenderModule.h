/* date = August 9th 2023 2:17 pm */

#include "ShaderLibrary.h"

#ifndef _RENDER_MODULE_H
#define _RENDER_MODULE_H

namespace Skruv 
{
    class State;
    
    class RenderModule 
    {
        public:
        
        RenderModule() {};
        
        void Init();
        void Update();
        
        ShaderLibrary& GetShaderLibrary() { return m_ShaderLibrary; }
        
        private:
        
        friend class State;
        
        ShaderLibrary m_ShaderLibrary;
    };
}

#endif //_RENDER_MODULE_H
