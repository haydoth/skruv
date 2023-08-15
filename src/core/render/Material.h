/* date = August 9th 2023 0:08 pm */

#include "../Base.h"
#include "Shader.h"

#ifndef _MATERIAL_H
#define _MATERIAL_H

namespace Skruv 
{
    class Material 
    {
        public:
        
        Material(std::string& path);
        
        private:
        
        std::string m_Name;
        // find a way to construct this without the compiler complaining
        // Shader m_Shader;
    };
}

#endif //_MATERIAL_H
