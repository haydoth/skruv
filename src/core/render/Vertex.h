/* date = August 14th 2023 10:10 pm */

#include <glm/ext.hpp>

#ifndef _VERTEX_H
#define _VERTEX_H

namespace Skruv 
{
    struct Vertex 
    {
        glm::vec3 Position;
        glm::vec2 TextureCoordinate;
        glm::vec3 Normal;
        glm::vec3 Tangent;
        glm::vec3 Bitangent;
        glm::vec3 Color;
    };
}

#endif //_VERTEX_H
