//
//  CMPlayerAction.cpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-05.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#include "CMPlayerAction.h"
#include "CMPlayer.h"
#include "CMHand.h"

CMSelectDiscardAction::CMSelectDiscardAction(CMPlayer* player, CMTile* tile){
    player_ = player;
    tile_ = tile;
}

bool CMSelectDiscardAction::Do() const{
    
    player_->hand->selected = tile_;
    return true;
}

bool CMSelectDiscardAction::Undo() const{
    return true;
}

string CMSelectDiscardAction::name() const{
    return "";
}


