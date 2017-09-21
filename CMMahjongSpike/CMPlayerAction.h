//
//  CMPlayerAction.h
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-05.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMPlayerAction_h
#define CMPlayerAction_h
#include "CMAction.h"
class CMTile;

class CMPlayer;

class CMSelectDiscardAction : public CMAction{

public:
    CMSelectDiscardAction(CMPlayer* player, CMTile* tile);
    bool Do() const;
    bool Undo() const;
    string name() const;
    
private:
    CMPlayer* player_;
    CMTile* tile_;
};

#endif /* CMPlayerAction_h */
