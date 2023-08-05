/* date = August 5th 2023 0:44 am */

#include <glm/ext.hpp>

#include <string> 

#ifndef _COMPONENTS_H
#define _COMPONENTS_H

namespace Skruv 
{
    struct TransformComponent 
    {
        glm::mat4 Transform { 1.0f };
        
        TransformComponent() = default;
        TransformComponent(const TransformComponent&) = default;
        TransformComponent(const glm::mat4& transform) : Transform(transform) {}
        
        operator const glm::mat4&() { return Transform; }
    };
    
    struct NameComponent 
    {
        std::string Name;
        
        NameComponent() = default;
        NameComponent(const NameComponent&) = default;
        NameComponent(const std::string& name) : Name(name) {}
        
        operator const std::string&() { return Name; }
    };
}

#endif //_COMPONENTS_H
