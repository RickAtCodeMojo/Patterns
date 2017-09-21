//
//  CMCue.h
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-07.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMObserver_h
#define CMObserver_h
#include "CMGlobalEnums.h"

#include <vector>
#include <string>
#include <map>
#include <functional>
#include <iostream>

using namespace std;
class CMPlayer;
class CMAction;


template <typename... Args>
class CMCue {
private:
    mutable std::map<int, std::function<void(Args...)>> agents_;
    mutable int cueId_;

public:
    
    CMCue() : cueId_(0) {}
    
    // copy creates new signal
    CMCue(CMCue const& other) : cueId_(0) {}
    
    // connects a member agent function to this cue
    template <typename T>
    constexpr int connectAgent(T *inst, void (T::*func)(Args...)) {
        return connectAgent([=](Args... args) {
            (inst->*func)(args...);
        });
    }
    
    // connects a const member agent function to this cue
    template <typename T>
    constexpr int connectAgent(T *inst, void (T::*func)(Args...) const) {
        return connectAgent([=](Args... args) {
            (inst->*func)(args...);
        });
    }
    
    // connects a std::function to the signal. The returned
    // value can be used to disconnect the function again
    constexpr int connectAgent(std::function<void(Args...)> const& agent) const {
        agents_.insert(std::make_pair(++cueId_, agent));
        return cueId_;
    }
    
    // disconnects a previously connected function
    void disconnectAgent(int id) const {
        agents_.erase(id);
    }
    
    // disconnects all previously connected functions
    void dismissAllAgents() const {
        agents_.clear();
    }
    
    // calls all connected functions
    void send(Args... p) {
        for(auto it : agents_) {
            auto func = it.second;
            func(p...);
        }
    }
    
    // assignment creates new Signal
    CMCue& operator=(CMCue const& other) const {
        dismissAllAgents();
    }
};


#endif /* CMObserver_h */
