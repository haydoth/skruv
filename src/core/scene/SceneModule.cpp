#include "core/scene/SceneModule.h"

#include "core/scene/Scene.h"

namespace Skruv 
{
    void SceneModule::Init() 
    {
        // create a new scene object 
        m_ActiveScene.reset(new Scene());
    }
    
    void SceneModule::Start() 
    {
        m_ActiveScene.get()->Start();
    }
    
    void SceneModule::Update() 
    {
        m_ActiveScene.get()->Update();
    }
}