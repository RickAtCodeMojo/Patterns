//
//  CMHandActions.hpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-04.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMHandActions_h
#define CMHandActions_h
#include "CMAction.h"
#include <iostream>

class CMHand;
class CMTile;
class CMWall;

using namespace std;

class CMShowAction : public CMAction{
public:
    CMShowAction(CMHand* hand);
    bool Do() const;
    bool Undo() const;
    string name() const;

private:
    CMHand* hand_;
};

class CMDiscardAction : public CMAction{
public:
    CMDiscardAction(CMHand* hand);
    bool Do() const;
    bool Undo() const;
    string name() const;
    
private:
    CMHand* hand_;
    CMTile* discard_;
};

class CMTakeAction : public CMAction{
public:
    CMTakeAction(CMHand* giver, CMHand* taker);
    bool Do() const;
    bool Undo() const;
    string name() const;
private:
    CMHand* taker_;
    CMHand* giver_;
};

class CMDrawAction : public CMAction{
public:
    CMDrawAction(CMHand* hand);
    bool Do() const;
    bool Undo() const;
    string name() const;

private:
    CMHand* hand_;
    CMWall* wall_;
};

class CMKeepAction : public CMAction{
public:
    CMKeepAction(CMHand* hand);
    bool Do() const;
    bool Undo() const;
    string name() const;
private:
    CMHand* hand_;
    CMWall* wall_;
};

class CMSortAction : public CMAction{
public:
    CMSortAction(CMHand* hand);
    bool Do() const;
    bool Undo() const;
    string name() const;
private:
    CMHand* hand_;
    
};

class CMRobKongAction : public CMAction{
public:
    CMRobKongAction(CMHand* taker, CMTile* tile);
    bool Do() const;
    bool Undo() const;
    string name() const;
private:
    CMHand* giver_;
    CMHand* taker_;
    CMTile* kongTile_;
};

class CMRemoveAction : public CMAction{
public:
    CMRemoveAction(CMHand* hand, CMTile* tile);
    bool Do() const;
    bool Undo() const;
    string name() const;
    
private:
    CMHand* hand_;
    unsigned int uid_;
};

class CMSelectAction : public CMAction{
public:
    CMSelectAction(CMHand* hand, CMTile* tile);
    bool Do() const;
    bool Undo() const;
    string name() const;
    
private:
    CMHand* hand_;
    CMTile* tile_;
};


#endif /* CMHandActions_hpp */
