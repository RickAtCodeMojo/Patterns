//
//  CMTileState.h
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-07.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMTileState_h
#define CMTileState_h
class CMTile;

enum class CMTileAction{
    Build,
    Draw,
    Keep,
    Chow,
    Pung,
    Kong,
    ConcealKong,
    Discard,
    Take,
    Rob,
    Reveal,
    Mahjong,
    Show
};

class CMTileState{
public:
    virtual ~CMTileState(){}
    virtual CMTileState* handleAction(CMTile* tile, CMTileAction action) = 0;
    virtual void update(CMTile* tile) = 0;
    
};

class CMMahjongState : public CMTileState{
    ~CMMahjongState(){}
    CMTileState* handleAction(CMTile* tile, CMTileAction action);
    void update(CMTile* tile);
};



class CMMeldState : public CMTileState{
    
    ~CMMeldState(){}
    
    CMTileState* handleAction(CMTile* tile, CMTileAction action);
    void update(CMTile* tile);
};

class CMTakenState : public CMTileState{
    ~CMTakenState(){}
    CMTileState* handleAction(CMTile* tile, CMTileAction action);
    void update(CMTile* tile);
};

class CMDiscardState : public CMTileState{
public:
    ~CMDiscardState(){}
    CMTileState* handleAction(CMTile* tile, CMTileAction action);
    void update(CMTile* tile);
};

class CMHeldState : public CMTileState{
    ~CMHeldState(){}
    CMTileState* handleAction(CMTile* tile, CMTileAction action);
    void update(CMTile* tile);
};

class CMDrawnState : public CMTileState{
    ~CMDrawnState(){}
    CMTileState* handleAction(CMTile* tile, CMTileAction action);
    void update(CMTile* tile);
};

class CMBuiltState : public CMTileState{
    ~CMBuiltState(){}
    CMTileState* handleAction(CMTile* tile, CMTileAction action);
    void update(CMTile* tile);
};




#endif /* CMTileState_h */
