#include "Scene.h"

#include "Entity.h"
#include "Components.h"

//#include "State.h"

#include <glm/ext.hpp>

namespace Skruv 
{
    Scene::Scene() 
    {
        
    }
    
    Scene::~Scene() 
    {
        
    }
    
    Entity Scene::CreateEntity(const std::string& name) 
    {
        // not the cleanest code ive written :(, but it should work.
        // also, if this function is being called, then this should 
        // be the active scene anyway.
        Entity entity = { m_Registry.create(), this};
        
        entity.AddComponent<TransformComponent>();
        entity.AddComponent<NameComponent>(name);
        
        return entity;
    }
}