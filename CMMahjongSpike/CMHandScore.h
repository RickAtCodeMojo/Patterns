//
//  CMHandScore.hpp
//  CMMahjongSpike
//
//  Created by Richard Dalley on 2017-09-03.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMHandScore_hpp
#define CMHandScore_hpp

#include <vector>
#include "CMMeld.h"
#include "CMGlobalEnums.h"
#include "CMRuleBook.h"
#include "CMWall.h"
#include "CMTile.h"

using namespace std;

class CMHandScore{

private:
    bool canMahjong_;
    bool selfDrawn_;
    CMWind prevailingWind_;
    CMWind seatWind_;
    CMRuleBook* ruleBook_;
    CMWall* wall_;
    
    size_t remainingTiles_;
    size_t score_;
    
    //meld and tile variables
    melds_t melds_;
    melds_t chows_;
    melds_t pungs_;
    melds_t kongs_;
    melds_t pairs_;
    
    tile_itr start_;
    tile_itr end_;
    
    //functions
    bool tilesAreInAnotherMeld(CMMeld& meld);
    bool tilesMatch(CMTile* first, CMTile* second);
    unsigned int getPointsFromFan(unsigned int fan);
    unsigned int minValue(CMMeld* meld, unsigned int currentMinValue);
    unsigned int maxValue(CMMeld* meld, unsigned int currentMaxValue);

public:
    
    CMHandScore(rawTile_it begin,
                CMWind prevailingWind,
                CMWind seatWind,
                CMTile* lastTile,
                CMWall* wall,
                CMRuleBook* ruleBook);
    ~CMHandScore();
    
    bool addedMeld(CMMeld& meld) ;
    bool canMahjong();
    bool tileIsInAMeld(CMTile* tile) ;
    
    size_t score();

    void assess();
    void pop();
    void clear();
    void show();

    
};



#endif /* CMHandScore_hpp */
