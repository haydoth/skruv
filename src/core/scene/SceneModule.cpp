#include "SceneModule.h"

#include "Scene.h"

namespace Skruv 
{
    void SceneModule::Init() 
    {
        // create a new scene object 
        m_ActiveScene.reset(new Scene());
    }
}