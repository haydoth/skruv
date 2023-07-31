/* date = June 25th 2023 10:32 pm */

#ifndef _STATE_H
#define _STATE_H

namespace Skruv {
    
    class State {
        protected:
        
        State() = default;
        
        static State* instance;
        
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
        
    };
}

#endif //_STATE_H
