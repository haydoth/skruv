/* date = June 25th 2023 10:32 pm */

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Base.h"

#include "WindowModule.h"
#include "scene/SceneModule.h"

#ifndef _STATE_H
#define _STATE_H

namespace Skruv {
    
    class State {
        protected:
        
        State() = default;
        
        static inline State* instance;
        
        public:
        
        State(State &other) = delete;
        void operator=(const State&) = delete;
        static State *Instance() {
            if(instance == nullptr) {
                return new State();
            }
            return instance;
        }
        
        // define this in the source file.
        // this should create instances of all engine modules and
        // the game
        void Run();
        Ref<Scene> GetActiveSceneRef();
        
        private:
        
        bool LoadModules();
        void Start();
        void Update();
        void Exit();
        
        WindowModule m_WindowModule;
        SceneModule m_SceneModule;
    };
}

#endif //_STATE_H
