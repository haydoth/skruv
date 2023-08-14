/* date = August 8th 2023 4:28 pm */

#include "../Base.h"
#include "ShaderProperties.h"
#include <string>

#ifndef _SHADER_H
#define _SHADER_H

namespace Skruv 
{
    enum class ShaderType 
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };
    
    struct ShaderSource
    {
        std::string VertexSource;
        std::string FragmentSource;
    };
    
    class Shader 
    {
        public:
        
        Shader(ShaderSource src, ShaderProperties props);
        
        unsigned int GetHandle() { return m_Handle; }
        static ShaderSource ParseShaderSource(std::string& path);
        
        private:
        
        unsigned int m_Handle;
        ShaderProperties m_Properties;
    };
}

#endif //_SHADER_H
