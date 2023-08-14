/* date = August 9th 2023 0:13 pm */

#include "../Base.h"

#include <string>

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
        ShaderProperties(List<ShaderPropertyBase> props) : properties(props) {}
        
        List<ShaderPropertyBase> properties;
    };
}

#endif //_SHADER_PROPERTIES_H
