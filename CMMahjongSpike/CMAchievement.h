//
//  CMAchievement.h
//  CMMahjongSpike
//
//  Created by Richard Dalley on 2017-09-07.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMAchievement_h
#define CMAchievement_h
#include "CMCue.h"
#include "CMAction.h"
#include "CMPlayer.h"

class CMAchievementHandler {
public:
    CMAchievementHandler(CMPlayer* player, CMPlayerAction action): player_(player), action_(action){
   
    }
    void perform() const;

private:
    CMPlayer* player_;
    CMPlayerAction action_;
};

#endif /* CMAchievement_h */
