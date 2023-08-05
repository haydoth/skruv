/* date = August 5th 2023 7:24 pm */

#ifndef _ENTITY_H
#define _ENTITY_H

#include "../Base.h"

#include "Scene.h"

#include <entt/entt.hpp>

namespace Skruv 
{
    class Scene;
    
    class Entity 
    {
        public:
        
        Entity(entt::entity handle, Scene* scene);
        Entity(const Entity& other) = default;
        
        template<typename T> bool HasComponent() 
        {
            return m_Scene->m_Registry.any_of<T>(m_Handle);
        }
        
        template<typename T, typename... Args> T& AddComponent(Args&&... args)
        {
            SKR_ASSERT(!HasComponent<T>(), "Entity already has component!");
            
            return m_Scene->m_Registry.emplace<T>(m_Handle, std::forward<Args>(args)...);
        }
        template<typename T> T& GetComponent() 
        {
            SKR_ASSERT(HasComponent<T>(), "Entity does not have component!");
            
            return m_Scene->m_Registry.get<T>(m_Handle);
        }
        template<typename T> void RemoveComponent() 
        {
            return m_Scene->m_Registry.remove<T>(m_Handle);
        }
        
        
        private:
        
        entt::entity m_Handle;
        Scene* m_Scene; // bad!!! raw pointer!!
    };
}

#endif //_ENTITY_H
