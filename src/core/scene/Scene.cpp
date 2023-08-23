#include "core/scene/Scene.h"

#include "core/scene/Entity.h"
#include "core/scene/Components.h"

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
    
    void Scene::Start() 
    {
        // start all entities
    }
    
    void Scene::Update() 
    {
        // update all entities
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