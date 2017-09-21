//
//  CMPlayer.h
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-04.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMPlayer_h
#define CMPlayer_h

#include <string>
#include "CMHand.h"
#include "CMPlayerAction.h"
#include "CMPlayerState.h"
#include "CMPlayerMode.h"
#include "CMColour.h"
#include "CMCue.h"

using namespace std;


class CMPlayer{

    friend class CMPlayerMode;
    friend class CMPlayer;

private:
    uint32_t playerID_;
    uint32_t networkID_;
    CMColour colour_;
    
    CMPlayerState* state_;
    CMActions* actions_;
    CMWall* wall_;
    CMPlayerMode* mode_;
    CMCue<> cue_;
    
    string alias_;
    string imagePath_;

public:
    CMPlayer(CMPlayerMode* breed, CMWind seatWind, CMWind prevailingWind, CMRuleBook* ruleBook, uint32_t playerID, uint32_t networkID);
    ~CMPlayer();
    unique_ptr<CMHand> hand;
    CMPlayer* next;
    CMTile* autoDiscard();
    void handleAction(CMPlayerAction action, CMTile* tile=nullptr, CMPlayer* other=nullptr);
    
    uint32_t playerID() const;
    uint32_t networkID() const;
    CMColour colour() const;
    string alias() const;
    
    void setAlias(const string alias);
    void setPlayerID(const uint32_t playerID);
    void setNetworkID(const uint32_t networkID);
    void setColour(const CMColour colour);
    
};



#endif /* CMPlayer_h */
