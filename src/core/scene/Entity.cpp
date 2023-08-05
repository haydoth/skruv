#include "Entity.h"

namespace Skruv 
{
    Entity::Entity(entt::entity handle, Scene* scene) 
        : m_Handle(handle), m_Scene(scene)
    {
        
    }
}