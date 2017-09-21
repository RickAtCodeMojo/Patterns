//
//  CMPlayerMode.cpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-05.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#include "CMPlayerMode.h"
#include "CMPlayer.h"

CMPlayer* CMNetworkPlayer::newPlayer(CMWind seatWind, CMWind prevailingWind, CMRuleBook* ruleBook, uint32_t playerID, uint32_t networkID) {
    return new CMPlayer(this, seatWind, prevailingWind, ruleBook, playerID, networkID);
}

CMPlayer* CMLocalPlayer::newPlayer(CMWind seatWind, CMWind prevailingWind, CMRuleBook* ruleBook, uint32_t playerID, uint32_t networkID) {
    return new CMPlayer(this, seatWind, prevailingWind, ruleBook, playerID, networkID);
}

CMPlayer* CMVirtualPlayer::newPlayer(CMWind seatWind, CMWind prevailingWind, CMRuleBook* ruleBook, uint32_t playerID, uint32_t networkID) {
    return new CMPlayer(this, seatWind, prevailingWind, ruleBook, playerID, networkID);
}


