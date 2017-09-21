//
//  CMPlayerState.h
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-05.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMPlayerState_h
#define CMPlayerState_h
#include "CMGlobalEnums.h"

class CMPlayer;
class CMTile;
class CMActions;

class CMPlayerState{
public:
    virtual ~CMPlayerState(){}
    virtual CMPlayerState* handleAction(CMPlayerAction action, CMPlayer* hand, CMTile* tile=nullptr, CMPlayer* other=nullptr) = 0;
    
};

class CMPlayerMahjongState : public CMPlayerState{
    CMPlayerState* handleAction(CMPlayerAction action, CMPlayer* player, CMTile* tile, CMPlayer* other){
        return nullptr;
    }
};

class CMPlayerInTurnState : public CMPlayerState{
    
    CMPlayerState* handleAction(CMPlayerAction action, CMPlayer* player, CMTile* tile, CMPlayer* other);
};

class CMPlayerWaitTurnState : public CMPlayerState{
    
    CMPlayerState* handleAction(CMPlayerAction action, CMPlayer* player, CMTile* tile, CMPlayer* other);
};

class CMWaitGameStartState : public CMPlayerState{
    
    CMPlayerState* handleAction(CMPlayerAction action, CMPlayer* player, CMTile* tile, CMPlayer* other);
    
};

#endif /* CMPlayerState_h */
