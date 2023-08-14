/* date = August 5th 2023 0:27 am */

#include <entt/entt.hpp>

#include <string>

#ifndef _SCENE_H
#define _SCENE_H

namespace Skruv 
{
    class Entity;
    class SceneModule;
    
    class Scene 
    {
        public:
        
        Scene();
        ~Scene();
        
        Entity CreateEntity(const std::string& name = "New Entity");
        
        private:
        
        friend class Entity;
        friend class SceneModule;
        
        void Start();
        void Update();
        
        entt::registry m_Registry;
        
    };
}

#endif //_SCENE_H
