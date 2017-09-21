//
//  CMAction.hpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-04.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMAction_h
#define CMAction_h

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class CMAction{
public:
    virtual bool Do() const = 0;
    virtual bool Undo() const = 0;
    virtual string name() const = 0;
    virtual ~CMAction(){}
};

using actions_t =  std::vector<CMAction*>;
using action_itr = actions_t::iterator;

class CMActions final {
    CMActions(){}
    ~CMActions(){
        action_itr itr = redo_.begin();
        while(itr != redo_.end()){
            if ((*itr)) {
                delete (*itr);
            }
            redo_.erase(itr);
        }
        itr = undo_.begin();
        while(itr != undo_.end()){
            if ((*itr)) {
                delete (*itr);
            }
            undo_.erase(itr);
        }
    }

    actions_t redo_;
    actions_t undo_;

public:
    static CMActions& getInstance(){
        static CMActions instance;
        return instance;

    }

    bool Do(CMAction* action){
        if (!action->Do()) {
            return false;
        }
        undo_.push_back(action);
        return true;
    }
    
    bool Undo(){
        CMAction* action = redo_.back();
        if(! action->Undo()){
            return false;
        }
        redo_.pop_back();
        undo_.push_back(action);
        return true;
    }
    
    bool Redo(){
        CMAction* action = undo_.back();
        if(! action->Do()){
            return false;
        }
        undo_.pop_back();
        redo_.push_back(action);
        return true;
    }
    void Show(){
        action_itr itr = redo_.begin();
        while(itr != redo_.end()){
            CMAction* action = (*itr);
            if (action) {
                cout << action->name() << endl;
            }
        }
    }
    CMActions(const CMActions&) = delete;
    CMActions& operator=(const CMActions&) = delete;
    CMActions(CMActions&&) = delete;
    CMActions& operator=(CMActions&&) = delete;

};

#endif /* CMAction_hpp */
