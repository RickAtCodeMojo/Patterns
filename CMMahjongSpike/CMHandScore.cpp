//
//  CMHandScore.cpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-03.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#include "CMHandScore.h"
CMHandScore::CMHandScore(rawTile_it begin,
                         CMWind prevailingWind,
                         CMWind seatWind,
                         CMTile* lastTile,
                         CMWall* wall,
                         CMRuleBook* ruleBook) : ruleBook_(ruleBook), wall_(wall){
    prevailingWind_ = prevailingWind;
    seatWind_ = seatWind;
}

CMHandScore::~CMHandScore(){
    
}

bool CMHandScore::tilesAreInAnotherMeld(CMMeld& meld){
    bool isAlreadyUsed = false;
    for (melds_itr itr = melds_.begin(); itr != melds_.end(); ++itr) {
        if (meld.containsTileFrom( (*itr) ) ) {
            return true;
        }
    }
    return isAlreadyUsed;
}

bool CMHandScore::addedMeld(CMMeld& meld){
    
    if (tilesAreInAnotherMeld(meld)) {
        return false;
    }
    
    melds_.push_back(meld);
    
    return true;

}

bool CMHandScore::canMahjong(){
    return canMahjong_;
}
bool CMHandScore::tileIsInAMeld(CMTile* tile){
    return false;
}

void CMHandScore::assess(){
    score_ = ruleBook_->score(melds_);
    canMahjong_ = score_ > 0;
}

void CMHandScore::pop(){
    melds_.pop_back();

}

void CMHandScore::clear(){
    melds_.clear();
    chows_.clear();
    pungs_.clear();
    kongs_.clear();
    pairs_.clear();
    canMahjong_ = false;
}

void CMHandScore::show(){
    
}

size_t CMHandScore::score(){
    return score_;
}
