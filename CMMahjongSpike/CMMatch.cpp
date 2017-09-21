//
//  CMMatch.cpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-04.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#include "CMMatch.h"


const int MAX_Players = 4;

CMMatch::CMMatch() {
    wall_ = &CMWall::getInstance();
    actions_ = &CMActions::getInstance();
    ruleBook_ = unique_ptr<CMRuleBook>(new Competition<ChickenHand<Flowers>>());
    playerId_ = 0;
    wall_->build();
    wall_->shuffle();
    fillColors();
}

void CMMatch::fillColors(){
    
    colors.clear();
    colors.push_back(CMColour::White());
    colors.push_back(CMColour::Orange());
    colors.push_back(CMColour::Green());
    colors.push_back(CMColour::Plum());

}

bool CMMatch::ended(){
    return wall_->empty();
}

void CMMatch::addPlayer(const uint32_t playerID, const uint32_t networkID=UINT32_MAX){
    
    CMPlayer* player = nullptr;
    
    if (playerID != UINT32_MAX) {
        //this is the local player
        player = local_.newPlayer(CMWind::East, CMWind::East, ruleBook_.get(), playerId_, networkID);
        localPlayer_ = player;
    }
    else if(playerID == UINT32_MAX && networkID != UINT32_MAX){
        //this is a network player
        player =network_.newPlayer(CMWind::South, CMWind::East, ruleBook_.get(), playerId_, networkID);
    }
    else{
        //this is a virtual player
        player = ai_.newPlayer(CMWind::South, CMWind::East, ruleBook_.get(), playerId_, networkID);
    }
    cout << "CMMatch::addPlayer:" << player->playerID()<< " from " << playerID << endl;
    player->setColour(colors.back());
    player->setNetworkID(networkID);
    player->handleAction(CMPlayerAction::DrawHand);
    colors.pop_back();
    players_.push_back(player);
    if (!players_.empty()) {
        CMPlayer* lastPlayer = players_.back();
        if (lastPlayer) {
            lastPlayer->next = player;
        }
        if (players_.size() == MAX_Players) {
            player->next = players_.front();
        }
    }

}

CMMatch::~CMMatch(){
    player_itr itr = players_.begin();
    while (itr != players_.end()) {
        delete (*itr);
        ++itr;
    }

    players_.clear();
}

CMPlayer* CMMatch::playerFromID(const uint32_t playerID) const{
    CMPlayer* player = nullptr;
    for (auto&& itr : players_) {
        player = itr;
        if (player->playerID() == playerID) {
            return player;
        }
    }
    return nullptr;
}

void CMMatch::handleInput(uint32_t sourcePlayerID, uint32_t otherPlayerID, uint32_t command, uint8_t tileID){
    if(command == ADD_player){
        if (players_.size() < 4) {
            addPlayer(sourcePlayerID, otherPlayerID);
        }
    }
    else if(command == TAP_Wall){
        CMPlayer* player = playerFromID(sourcePlayerID);
        if (!player) {
            return;
        }
        CMPlayer* opponent = nullptr;
        if (otherPlayerID != UINT32_MAX ) {
            opponent = playerFromID(otherPlayerID);
        }
        CMTile* tile = wall_->draw();
        CMCommand* action = inputHandler_.handleInput(command);
        action->perform(player, opponent, tile);
    }
    else if(command == TAP_HandMember){
        CMPlayer* player = playerFromID(sourcePlayerID);
        if (!player) {
            return;
        }
        CMCommand* action = inputHandler_.handleInput(command);
        CMTile* tile = nullptr;
        if (tileID != INT8_MAX) {
            tile = wall_->tileFromID(tileID);
        }
        action->perform(player, nullptr, tile);
    }
    else if(command == TAP_SelectedHandMember){
        CMPlayer* player = playerFromID(sourcePlayerID);
        if (!player) {
            return;
        }
        CMCommand* action = inputHandler_.handleInput(command);
        action->perform(player);
    }
}
