/* date = August 24th 2023 5:31 pm */

#include <tiny_gltf.h>

#include <string>

#ifndef _MODEL_H
#define _MODEL_H

namespace Skruv 
{
    enum class ModelEncodingType 
    {
        ASCII = 0, BINARY = 1
    };
    class Model
    {
        public:
        Model() = default;
        bool LoadFromPath(std::string path, ModelEncodingType met);
        
        private:
        ModelEncodingType m_EncodingType;
        tinygltf::Model m_Model;
        
        static tinygltf::TinyGLTF m_Loader;
    };
}

#endif //_MODEL_H
