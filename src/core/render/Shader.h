/* date = August 8th 2023 4:28 pm */

#include "../Base.h"
#include "ShaderProperties.h"

#include <glad/glad.h>
#include <glm/ext.hpp>

#include <string>
#include <type_traits>

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
        
        template <typename T> void SetProperty(std::string name, T value) 
        {
            m_Properties.properties[name] = value;
            
            if (tag<T> == tag<int> ||
                tag<T> == tag<bool>) 
            {
                glUniform1i(glGetUniformLocation(m_Handle, name.c_str()), (int)value); 
            }
            if (tag<T> == tag<float>) 
            {
                glUniform1f(glGetUniformLocation(m_Handle, name.c_str()), value); 
            }
            if (tag<T> == tag<glm::vec3>) 
            {
                glUniform3f(glGetUniformLocation(m_Handle, name.c_str()), value.x, value.y, value.z);
            }
        }
        unsigned int GetHandle() { return m_Handle; }
        static ShaderSource ParseShaderSource(std::string& path);
        
        
        
        private:
        
        unsigned int m_Handle;
        ShaderProperties m_Properties;
    };
}

#endif //_SHADER_H
