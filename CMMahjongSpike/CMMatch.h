//
//  CMMatch.h
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-04.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMMatch_h
#define CMMatch_h

#include <vector>
#include <string>
#include "CMPlayer.h"
#include "CMRuleBook.h"
#include "CMHand.h"
#include "CMAction.h"
#include "CMCommand.h"
#include <cstdint>

using players_t = vector< CMPlayer* >;
using player_itr = players_t::iterator;

class CMMatch{
private:
    players_t players_;
    const CMPlayer* localPlayer_;
    unique_ptr<CMRuleBook> ruleBook_;
    CMWall* wall_;
    uint32_t playerId_;
    CMInputHandler inputHandler_;
    CMActions* actions_;
    CMLocalPlayer local_;
    CMNetworkPlayer network_;
    CMVirtualPlayer ai_;
    vector<CMColour> colors;
    
    CMPlayer* playerFromID(const uint32_t playerID) const;
    void configurePlayers();
    void addPlayer(const uint32_t playerID, const uint32_t networkID);
    void fillColors();

public:
    CMMatch();
    ~CMMatch();
    void handleInput(uint32_t sourcePlayerID, uint32_t otherPlayerID=UINT32_MAX, uint32_t command=UINT32_MAX, uint8_t tileID=UINT8_MAX);
    bool ended();

};

#endif /* CMMatch_h */
