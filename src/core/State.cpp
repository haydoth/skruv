#include "State.h"

#include <iostream>

#include "Skruv.h"

namespace Skruv {
    
    bool State::LoadModules()
    {
        m_WindowModule = WindowModule();
        if(!m_WindowModule.Init()) return false;
        
        m_SceneModule = SceneModule();
        m_SceneModule.Init();
        
        return true;
    }
    
    void State::Update() 
    {
        while (!m_WindowModule.GetWindowShouldClose())
        {
            // update modules
            m_WindowModule.Update();
        }
    }
    void State::Exit() 
    {
        m_WindowModule.Exit();
    }
    
    void State::Start() 
    {
        Entity guy = GetActiveSceneRef().get()->CreateEntity("guy");
        std::cout << guy.GetComponent<NameComponent>().Name << "\n";
    }
    
    void State::Run() 
    {
        if(LoadModules()) 
        {
            Start();
            Update();
        }
        Exit();
    }
    
    Ref<Scene> State::GetActiveSceneRef() 
    {
        return m_SceneModule.m_ActiveScene;
    }
}