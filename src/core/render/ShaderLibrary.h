/* date = August 9th 2023 2:35 pm */

#include "../Base.h"

#include "Shader.h"

#include <string>
#include <unordered_map>

#ifndef _SHADER_LIBRARY_H
#define _SHADER_LIBRARY_H

namespace Skruv 
{
    class ShaderLibrary 
    {
        public:
        
        ShaderLibrary() = default;
        
        void AddShader(std::string name, Shader shader) 
        {
            m_ShaderMap[name] = Ref<Shader>(&shader);
        }
        
        Ref<Shader> GetByName(std::string name) 
        {
            return m_ShaderMap[name];
        }
        
        private:
        
        std::unordered_map<std::string, Ref<Shader>> m_ShaderMap;
    };
}

#endif //_SHADER_LIBRARY_H
