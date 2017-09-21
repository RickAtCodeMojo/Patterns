//
//  CMPlayerState.cpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-05.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#include "CMPlayerState.h"
#include "CMPlayer.h"
#include "CMAction.h"

CMPlayerState* CMPlayerInTurnState::handleAction(CMPlayerAction action, CMPlayer* player, CMTile* tile, CMPlayer* other){

    CMActions* actions = &CMActions::getInstance();

    switch(action){
        case CMPlayerAction::Discard:{
            
            player->hand->handleAction(CMHandAction::Discard);
            return new CMPlayerWaitTurnState();
        }
            break;
            
        case CMPlayerAction::SelectDiscard:{
            if (tile) {
                actions->Do(new CMSelectDiscardAction(player, tile));
            }
            else{
                actions->Do(new CMSelectDiscardAction(player, player->autoDiscard()));
            }
            return nullptr;
        }
            break;
            
        default:
            break;
    }
    return nullptr;
}

CMPlayerState* CMPlayerWaitTurnState::handleAction(CMPlayerAction action, CMPlayer* player, CMTile* tile, CMPlayer* other){
    
    switch(action){
            
        case CMPlayerAction::Draw:{
            player->hand->handleAction(CMHandAction::Draw);
            player->hand->handleAction(CMHandAction::Keep);

            return new CMPlayerInTurnState();
        }
            break;
            
        case CMPlayerAction::RobKong:{
            player->hand->handleAction(CMHandAction::Rob);
            return new CMPlayerMahjongState();
        }
            break;
            
        default:
            break;
    }
    return nullptr;
}

CMPlayerState* CMWaitGameStartState::handleAction(CMPlayerAction action, CMPlayer* player, CMTile* tile, CMPlayer* other){
    
    switch(action){
        case CMPlayerAction::DrawHand:{
            player->hand->handleAction(CMHandAction::BuildHand);
            player->hand->handleAction(CMHandAction::Show);
            return new CMPlayerWaitTurnState();
        }
            break;
            
        default:
            break;
    }
    return nullptr;
}
