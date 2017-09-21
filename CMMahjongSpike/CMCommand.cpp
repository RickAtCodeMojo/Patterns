//
//  CMCommand.cpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-06.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#include "CMCommand.h"
#include "CMPlayer.h"
#include "CMGlobalEnums.h"
const unsigned int TAP_Discard = 0;
const unsigned int TAP_Wall = 1;
const unsigned int TAP_OpponentKong = 2;
const unsigned int TAP_HandMember = 3;
const unsigned int TAP_SelectedHandMember = 4;
const unsigned int TAP_Chow = 5;
const unsigned int TAP_tapPung = 6;
const unsigned int TAP_tapKong = 7;
const unsigned int ADD_player = 8;

void CMTapDiscard::perform(CMPlayer* player, CMPlayer* opponent, CMTile* tile){
    player->handleAction(CMPlayerAction::Discard, tile);
}

void CMTapWall::perform(CMPlayer* player, CMPlayer* opponent, CMTile* tile){
    player->handleAction(CMPlayerAction::Draw);
}

void CMTapOpponentKong::perform(CMPlayer* player, CMPlayer* opponent, CMTile* tile){
    player->handleAction(CMPlayerAction::RobKong, tile);
    
}

void CMTapHandMember::perform(CMPlayer* player, CMPlayer* opponent, CMTile* tile){
    player->handleAction(CMPlayerAction::SelectDiscard, tile);
}

void CMTapSelectedHandMember::perform(CMPlayer* player, CMPlayer* opponent, CMTile* tile){
    player->handleAction(CMPlayerAction::Discard, tile);
    
}

void CMTapChow::perform(CMPlayer* player, CMPlayer* opponent, CMTile* tile){
    player->handleAction(CMPlayerAction::Chow, tile);

}

void CMTapPung::perform(CMPlayer* player, CMPlayer* opponent, CMTile* tile){
    player->handleAction(CMPlayerAction::Pung, tile);

}

void CMTapKong::perform(CMPlayer* player, CMPlayer* opponent, CMTile* tile){
    player->handleAction(CMPlayerAction::Kong, tile);

}

CMInputHandler::CMInputHandler(){
    tapDiscard_ = unique_ptr<CMCommand>(new CMTapDiscard());
    tapWall_ = unique_ptr<CMCommand>(new CMTapWall());
    tapOpponentKong_ = unique_ptr<CMCommand>(new CMTapOpponentKong());
    tapHandMember_ = unique_ptr<CMCommand>(new CMTapHandMember());
    tapSelectedHandMember_ = unique_ptr<CMCommand>(new CMTapSelectedHandMember());
    tapChow_ = unique_ptr<CMCommand>(new CMTapChow());
    tapPung_ = unique_ptr<CMCommand>(new CMTapPung());
    tapKong_ = unique_ptr<CMCommand>(new CMTapKong());

}

CMInputHandler::~CMInputHandler(){
}

CMCommand* CMInputHandler::handleInput(uint32_t command){
    
    switch (command) {
        case TAP_Discard:{
            return tapDiscard_.get();
        }
            break;
        case TAP_Wall :{
            return tapWall_.get();
        }
            break;

        case TAP_OpponentKong :{
            return tapOpponentKong_.get();
        }
            break;

        case TAP_HandMember :{
            return tapHandMember_.get();
        }
            break;
            
        case TAP_SelectedHandMember :{
            return tapSelectedHandMember_.get();
        }
            break;
            
        case TAP_Chow :{
            return tapChow_.get();
        }
            break;

        case TAP_tapPung :{
            return tapPung_.get();
        }
            break;

        case TAP_tapKong :{
            return tapKong_.get();
        }
            break;


        default:
            break;
    }
    return nullptr;
}
