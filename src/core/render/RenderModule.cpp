#include "core/render/RenderModule.h"

#include "core/render/ShaderLibrary.h"

namespace Skruv 
{
    void RenderModule::Init() 
    {
        m_ShaderLibrary = ShaderLibrary();
    }
    void RenderModule::Update() 
    {
        // draw stuff
    }
}