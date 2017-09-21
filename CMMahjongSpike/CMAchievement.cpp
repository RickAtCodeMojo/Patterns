//
//  CMAchievement.cpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-07.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#include "CMAchievement.h"

void CMAchievementHandler::perform() const{
    //do something with the achievement
    cout << "PlayerID:" << player_->playerID() << " checked for achievement " << (unsigned int)action_ << endl;
}
