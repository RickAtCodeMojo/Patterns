//
//  CMDispatcher.h
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-07.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMObserver_h
#define CMObserver_h
#include "CMGlobalEnums.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>

using namespace std;
class CMPlayer;
class CMAction;

template <typename... Args>
class CMDispatcher {
    
public:
    
    CMDispatcher() : dispatchID_(0) {}
    
    // copy creates new notification
    CMDispatcher(CMDispatcher const& other) : dispatchID_(0) {}
    
    // notifies all connected functions
    void notify(Args... p) {
        for(auto it : dispatches_) {
            it.second(p...);
        }
        
    }
    
    // assignment creates new Signal
    CMDispatcher& operator=(CMDispatcher const& other) {
        dismissAll();
    }

    // enroll a std::function to the notification. The returned
    // value can be used to disconnect the function again
    int enroll(std::function<void(Args...)> const& handler) const {
        dispatches_.insert(std::make_pair(++dispatchID_, handler));
        return dispatchID_;
    }
    
    // enrolls a member function to this notification
    template <typename T>
    int enrollMember(T *inst, void (T::*func)(Args...)) {
        return enroll([=](Args... args) {
            (inst->*func)(args...);
        });
    }
    
    // enrolls a const member function to this notification
    template <typename T>
    int enrollMember(T *inst, void (T::*func)(Args...) const) {
        return enroll([=](Args... args) {
            (inst->*func)(args...);
        });
    }
    
    // disconnects a previously connected function
    void dismiss(int dispatchID) const {
        dispatches_.erase(dispatchID);
    }
    
    // disconnects all previously connected functions
    void dismissAll() const {
        dispatches_.clear();
    }
    
    
private:
    mutable std::map<int, std::function<void(Args...)>> dispatches_;
    mutable int dispatchID_;
};


#endif /* CMObserver_h */
