//
//  CMPlayerMode.h
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-05.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMPlayerMode_h
#define CMPlayerMode_h

#include "CMGlobalEnums.h"
#include <cstdint>

class CMWall;
class CMRuleBook;
class CMActions;
class CMPlayer;


class CMPlayerMode{
public:
    virtual ~CMPlayerMode(){}
    virtual CMPlayer* newPlayer(CMWind seatWind, CMWind prevailingWind, CMRuleBook* ruleBook, uint32_t playerID, uint32_t networkID) = 0;
private:
};

class CMNetworkPlayer : public CMPlayerMode{
public:
    CMPlayer* newPlayer(CMWind seatWind, CMWind prevailingWind, CMRuleBook* ruleBook, uint32_t playerID, uint32_t networkID);
};

class CMLocalPlayer : public CMPlayerMode{
public:
    CMPlayer* newPlayer(CMWind seatWind, CMWind prevailingWind, CMRuleBook* ruleBook, uint32_t playerID, uint32_t networkID);
};

class CMVirtualPlayer : public CMPlayerMode{
public:
    CMPlayer* newPlayer(CMWind seatWind, CMWind prevailingWind, CMRuleBook* ruleBook, uint32_t playerID, uint32_t networkID);
};

#endif /* CMPlayerMode_h */
