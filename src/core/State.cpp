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
            // scene module should also be updated each frame lol
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
        
        std::string basicShaderString = "src/shaders/Basic.shader";
        ShaderSource src = Shader::ParseShaderSource(basicShaderString);
        
        std::cout << "vertex" << "\n";
        std::cout << src.VertexSource << "\n";
        
        std::cout << "fragment" << "\n";
        std::cout << src.FragmentSource << "\n";
        
        Shader basicShader(src);
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