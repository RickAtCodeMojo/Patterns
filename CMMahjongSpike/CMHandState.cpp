//
//  CMHandState.cpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-05.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#include "CMHandState.h"
#include "CMHand.h"
#include "CMAction.h"

CMHandState* CMHandMahjongState::handleAction(CMHandAction action, CMHand* hand, CMTile* tile, CMHand* other){
    return nullptr;
}
void CMHandMahjongState::update(CMTile* tile){
    
}
CMHandState* CMInTurnState::handleAction(CMHandAction action, CMHand* hand, CMTile* tile, CMHand* other){
    CMActions* actions = &CMActions::getInstance();

    switch (action) {
        case CMHandAction::Discard:{
            if(hand->hand.size() > hand->ruleBook_->handSize()){
                actions->Do(new CMDiscardAction(hand));
                return new CMWaitingTurnState();
            }
                
        }
            break;
            
        default:
            break;
    }
    return nullptr;
}
void CMInTurnState::update(CMTile* tile){
    
}

CMHandState* CMBuildHandState::handleAction(CMHandAction action, CMHand* hand, CMTile* tile, CMHand* other){
    CMActions* actions = &CMActions::getInstance();
    switch (action) {
        case CMHandAction::Draw:{
            actions->Do(new CMDrawAction(hand));
            actions->Do( new CMKeepAction(hand) );
            actions->Do( new CMSortAction(hand) );
            return new CMInTurnState();
        }
            break;
        case CMHandAction::Show:{
            actions->Do(new CMShowAction(hand));
            return nullptr;
        }
            break;
            
        default:
            break;
    }
    return nullptr;
}
void CMBuildHandState::update(CMTile* tile){
    
}


CMHandState* CMStartGameState::handleAction(CMHandAction action, CMHand* hand, CMTile* tile, CMHand* other){
    CMActions* actions = &CMActions::getInstance();
    switch (action) {
        case CMHandAction::BuildHand:{
            while(hand->hand.size() < hand->ruleBook_->handSize()){
                actions->Do( new CMDrawAction(hand) );
                actions->Do( new CMKeepAction(hand) );
            }
            actions->Do( new CMSortAction(hand) );
            return new CMWaitingTurnState();
        }
            break;
            
        default:
            break;
    }
    return nullptr;
}
void CMStartGameState::update(CMTile* tile){
    
}

CMHandState* CMWaitingTurnState::handleAction(CMHandAction action, CMHand* hand, CMTile* tile, CMHand* other){
    
    CMActions* actions = &CMActions::getInstance();

    switch (action) {
            
        case CMHandAction::Draw:{
            if(actions->Do( new CMDrawAction(hand) )){
                actions->Do( new CMKeepAction(hand) );
                actions->Do( new CMSortAction(hand) );
                return new CMInTurnState();
            }
        }
            break;
            
        case CMHandAction::Show:{
            actions->Do(new CMShowAction(hand));
            return nullptr;
        }
            break;
                        
        case CMHandAction::Rob:{
            if (!other) {
                return nullptr;
            }
            actions->Do( new CMRobKongAction(hand, tile) );
            actions->Do( new CMRemoveAction(other, tile) );
            return new CMHandMahjongState();
        }
            break;
            
        default:
            break;
    }
    return nullptr;
}

void CMWaitingTurnState::update(CMTile* tile){
    
}

CMHandState* CMWaitingMahjong::handleAction(CMHandAction action, CMHand* hand, CMTile* tile, CMHand* other){
    CMActions* actions = &CMActions::getInstance();
    switch (action) {
        case CMHandAction::StartTurn:{
            return new CMInTurnState();
        }
            break;
        case CMHandAction::Show:{
            actions->Do(new CMShowAction(hand));
            return nullptr;
        }
            break;
            
        default:
            break;
    }
    return nullptr;
}
void CMWaitingMahjong::update(CMTile* tile){
    
}

