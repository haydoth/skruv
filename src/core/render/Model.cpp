#include "core/render/Model.h"

#include <stdio.h>

#define TINYGLTF_IMPLEMENTATION

namespace Skruv 
{
    void CreateLoader() 
    {
        m_Loader = tinygltf::TinyGLTF();
    }
    
    Model::LoadFromPath(std::string path, ModelEncodingType met) 
    {
        if(!m_Loader) CreateLoader();
        
        bool ret;
        
        if(met == ModelEncodingType::ASCII)
            ret = loader.LoadASCIIFromFile(&model, &err, &warn, path);
        if(met == ModelEncodingType::BINARY)
            ret = loader.LoadBinaryFromFile(&model, &err, &warn, path);
        
        if (!warn.empty()) {
            printf("Warn: %s\n", warn.c_str());
        }
        
        if (!err.empty()) {
            printf("Err: %s\n", err.c_str());
        }
        
        if (!ret) {
            printf("Failed to parse glTF\n");
        }
    }
}