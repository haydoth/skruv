/* date = August 9th 2023 0:13 pm */

#include "../Base.h"

#include <string>
#include <unordered_map>

#ifndef _SHADER_PROPERTIES_H
#define _SHADER_PROPERTIES_H

namespace Skruv 
{
    class ShaderPropertyBase
    {
        
    };
    template<typename T> class ShaderProperty : public ShaderPropertyBase
    {
        public:
        
        T value;
        
        ShaderProperty(std::string name) : m_Name(name) {}
        ~ShaderProperty() {}
        
        private:
        
        std::string m_Name;
    };
    
    struct ShaderProperties 
    {
        ShaderProperties(std::unordered_map<std::string, ShaderPropertyBase> props) : properties(props) {}
        
        std::unordered_map<std::string, ShaderPropertyBase> properties;
    };
}

#endif //_SHADER_PROPERTIES_H
