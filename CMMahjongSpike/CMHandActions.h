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

private:
    CMHand* hand_;

public:
    CMShowAction(CMHand* hand);
    bool Do() const;
    bool Undo() const;
    string name() const;

};

class CMDiscardAction : public CMAction{

private:
    CMHand* hand_;
    CMTile* discard_;

public:
    CMDiscardAction(CMHand* hand);
    bool Do() const;
    bool Undo() const;
    string name() const;
    
};

class CMTakeAction : public CMAction{

private:
    CMHand* taker_;
    CMHand* giver_;

public:
    CMTakeAction(CMHand* giver, CMHand* taker);
    bool Do() const;
    bool Undo() const;
    string name() const;
};

class CMDrawAction : public CMAction{

private:
    CMHand* hand_;
    CMWall* wall_;

public:
    CMDrawAction(CMHand* hand);
    bool Do() const;
    bool Undo() const;
    string name() const;
};

class CMKeepAction : public CMAction{

private:
    CMHand* hand_;
    CMWall* wall_;

public:
    CMKeepAction(CMHand* hand);
    bool Do() const;
    bool Undo() const;
    string name() const;
};

class CMSortAction : public CMAction{

private:
    CMHand* hand_;
    
public:
    CMSortAction(CMHand* hand);
    bool Do() const;
    bool Undo() const;
    string name() const;
};

class CMRobKongAction : public CMAction{

private:
    CMHand* giver_;
    CMHand* taker_;
    CMTile* kongTile_;

public:
    CMRobKongAction(CMHand* taker, CMTile* tile);
    bool Do() const;
    bool Undo() const;
    string name() const;
};

class CMRemoveAction : public CMAction{
    
private:
    CMHand* hand_;
    unsigned int uid_;

public:
    CMRemoveAction(CMHand* hand, CMTile* tile);
    bool Do() const;
    bool Undo() const;
    string name() const;
};

class CMSelectAction : public CMAction{

private:
    CMHand* hand_;
    CMTile* tile_;

public:
    CMSelectAction(CMHand* hand, CMTile* tile);
    bool Do() const;
    bool Undo() const;
    string name() const;
    
};


#endif /* CMHandActions_hpp */
