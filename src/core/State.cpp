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
        
        m_RenderModule = RenderModule();
        m_RenderModule.Init();
        
        return true;
    }
    
    void State::Update() 
    {
        while (!m_WindowModule.GetWindowShouldClose())
        {
            // update modules
            m_WindowModule.Update();
            m_SceneModule.Update();
            m_RenderModule.Update();
            
            // set references
            // idk if i should be doing this tbh
            scene = m_SceneModule.m_ActiveScene.get();
            shaderLibrary = &m_RenderModule.m_ShaderLibrary;
        }
    }
    void State::Exit() 
    {
        m_WindowModule.Exit();
    }
    
    void State::Start() 
    {
        m_SceneModule.Start();
    }
    
    State::State()
    {
        m_LoadedModules = LoadModules();
        if(m_LoadedModules) 
        {
            // set references
            scene = m_SceneModule.m_ActiveScene.get();
            shaderLibrary = &m_RenderModule.m_ShaderLibrary;
        }
    }
    
    void State::Run() 
    {
        if(m_LoadedModules) 
        {
            Start();
            Update();
        }
        Exit();
    }
}