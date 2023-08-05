/* date = August 5th 2023 0:27 am */

#include <entt/entt.hpp>

#include <string>

#ifndef _SCENE_H
#define _SCENE_H

namespace Skruv 
{
    class Entity;
    
    class Scene 
    {
        public:
        
        Scene();
        ~Scene();
        
        Entity CreateEntity(const std::string& name = "New Entity");
        
        private:
        
        friend class Entity;
        
        // TODO: create entity class. every entity should have its own transform component.
        // the transform keeps track of parent and child transforms, and the entity
        // that owns it.
        
        // Also the this class should maybe extend Entity, since it functions a bit like one.
        
        entt::registry m_Registry;
        
    };
}

#endif //_SCENE_H
