//
//  CMPlayer.cpp
//  CMMahjongSpike
//
//  Created by Richard Dalley on 2017-09-04.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#include "CMPlayer.h"
#include "CMAchievement.h"

CMPlayer::CMPlayer(CMPlayerMode* mode, CMWind seatWind, CMWind prevailingWind, CMRuleBook* ruleBook, uint32_t playerID, uint32_t networkID) : mode_(mode) {
    wall_ = &CMWall::getInstance();
    actions_ = &CMActions::getInstance();
    
    hand = unique_ptr<CMHand>(new CMHand(seatWind, prevailingWind, ruleBook));
    state_ = new CMWaitGameStartState();
    playerID_ = playerID;
    networkID_ = networkID;
    CMAchievementHandler achievement(this, CMPlayerAction::Mahjong);
    cue_.connectAgent(&achievement, &CMAchievementHandler::perform);
    cue_.send();
}

CMPlayer::~CMPlayer(){

}

void CMPlayer::handleAction(CMPlayerAction action, CMTile* tile, CMPlayer* other){

    CMPlayerState* state = state_->handleAction(action, this, tile, other);
    if (state) {
        delete state_;
        state_ = state;
    }
}


CMTile* CMPlayer::autoDiscard(){
    return hand->autoDiscard();
}

uint32_t CMPlayer::playerID() const{
    return playerID_;
}

uint32_t CMPlayer::networkID() const{
    return networkID_;
}

CMColour CMPlayer::colour() const{
    return colour_;
}

void CMPlayer::setAlias(const string alias) {
    alias_ = alias;
}
void CMPlayer::setPlayerID(const uint32_t playerID) {
    playerID_ = playerID;
}
void CMPlayer::setNetworkID(const uint32_t networkID) {
    networkID_ = networkID;
}

void CMPlayer::setColour(const CMColour colour) {
    colour_ = colour_;
}
