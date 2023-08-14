/* date = August 3rd 2023 2:18 pm */

#include "../Base.h"

#ifndef _SCENE_MODULE_H
#define _SCENE_MODULE_H

namespace Skruv 
{
    class State;
    class Scene;
    
    class SceneModule 
    {
        private:
        
        friend class State;
        
        void Init();
        void Start();
        void Update();
        
        Ref<Scene> m_ActiveScene;
    };
}

#endif //_SCENE_MODULE_H
