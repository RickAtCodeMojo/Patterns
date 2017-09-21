//
//  CMTileState.cpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-07.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#include "CMTileState.h"
#include "CMTile.h"

CMTileState* CMMahjongState::handleAction(CMTile* tile, CMTileAction action){
    return nullptr;
}
void CMMahjongState::update(CMTile* tile){
    
}



CMTileState* CMMeldState::handleAction(CMTile* tile, CMTileAction action){
    switch (action) {
            
        case CMTileAction::Kong:{
            if (tile->meldKind() == CMMeldKind::Pung) {
                tile->meld(CMMeldKind::Kong);
                return new CMMeldState();
            }
        }
            break;
            
        case CMTileAction::Rob:{
            if (tile->meldKind() == CMMeldKind::Kong) {
                return new CMMahjongState();
            }
        }
            
        default:
            return nullptr;
    }
    
    return nullptr;
}

void CMMeldState::update(CMTile* tile){
    
}

CMTileState* CMTakenState::handleAction(CMTile* tile, CMTileAction action){
    switch (action) {
            
        case CMTileAction::Mahjong:{
            return new CMMahjongState();
        }
            break;
            
        case CMTileAction::Kong:{
            tile->meld(CMMeldKind::Kong);
            return new CMMeldState();
        }
            break;
            
        case CMTileAction::Pung:{
            tile->meld(CMMeldKind::Pung);
            return new CMMeldState();
        }
            break;
            
        case CMTileAction::Chow:{
            tile->meld(CMMeldKind::Chow);
            return new CMMeldState();
        }
            break;
            
        default:
            return nullptr;
    }
    return nullptr;
}
void CMTakenState::update(CMTile* tile){
    
}

CMTileState* CMDiscardState::handleAction(CMTile* tile, CMTileAction action){
    switch (action) {
        case CMTileAction::Take:{
            return new CMTakenState();
        }
            break;
            
        default:
            return nullptr;
    }
    return nullptr;
}
void CMDiscardState::update(CMTile* tile){
    
}

CMTileState* CMHeldState::handleAction(CMTile* tile, CMTileAction action){
    switch (action) {
        case CMTileAction::Discard:{
            return new CMDiscardState();
        }
            break;
        case CMTileAction::Kong:{
            tile->meld(CMMeldKind::Kong);
            return new CMMeldState();
        }
            break;
            
        case CMTileAction::ConcealKong:{
            tile->meld(CMMeldKind::Kong);
            tile->conceal();
            return new CMMeldState();
        }
            break;
            
        case CMTileAction::Pung:{
            tile->meld(CMMeldKind::Pung);
            return new CMMeldState();
        }
            break;
            
        case CMTileAction::Chow:{
            tile->meld(CMMeldKind::Chow);
            return new CMMeldState();
        }
            break;
            
        default:
            return nullptr;
    }
    return nullptr;
}

void CMHeldState::update(CMTile* tile){
    
}

CMTileState* CMDrawnState::handleAction(CMTile* tile, CMTileAction action){
    switch (action) {
        case CMTileAction::Discard:{
            return new CMDiscardState();
        }
            break;
        case CMTileAction::Keep:{
            return new CMHeldState();
        }
            break;
        case CMTileAction::Mahjong:{
            return new CMMahjongState();
        }
            break;
        default:
            return nullptr;
    }
    return nullptr;
}
void CMDrawnState::update(CMTile* tile){
    
}

CMTileState* CMBuiltState::handleAction(CMTile* tile, CMTileAction action){
    if (action == CMTileAction::Draw) {
        return new CMDrawnState();
    }
    return nullptr;
}
void CMBuiltState::update(CMTile* tile){
    
}
