//
//  CMHandState.h
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-05.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMHandState_h
#define CMHandState_h
#include "CMGlobalEnums.h"

class CMHand;
class CMTile;
class CMActions;

class CMHandState{
public:
    virtual ~CMHandState(){}
    virtual CMHandState* handleAction(CMHandAction action, CMHand* hand, CMTile* tile=nullptr, CMHand* other=nullptr) = 0;
    
};

class CMHandMahjongState: public CMHandState{
public:
    ~CMHandMahjongState(){}
    CMHandState* handleAction(CMHandAction action, CMHand* hand, CMTile* tile, CMHand* other);
    void update(CMTile* tile);
};

class CMInTurnState : public CMHandState{
public:
    ~CMInTurnState(){}
    CMHandState* handleAction(CMHandAction action, CMHand* hand, CMTile* tile, CMHand* other);
    void update(CMTile* tile);
    
};

class CMBuildHandState : public CMHandState{
public:
    ~CMBuildHandState(){}
    CMHandState* handleAction(CMHandAction action, CMHand* hand, CMTile* tile, CMHand* other);
    void update(CMTile* tile);
};


class CMStartGameState : public CMHandState{
public:
    ~CMStartGameState(){}
    CMHandState* handleAction(CMHandAction action, CMHand* hand, CMTile* tile, CMHand* other);
    void update(CMTile* tile);
};

class CMWaitingTurnState: public CMHandState{
public:
    ~CMWaitingTurnState(){}
    CMHandState* handleAction(CMHandAction action, CMHand* hand, CMTile* tile, CMHand* other);
    void update(CMTile* tile);
    
};

class CMWaitingMahjong: public CMHandState{
public:
    ~CMWaitingMahjong(){}
    CMHandState* handleAction(CMHandAction action, CMHand* hand, CMTile* tile, CMHand* other);
    void update(CMTile* tile);
    
};


#endif /* CMHandState_h */
