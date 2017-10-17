//
//  CMRuleBook.h
//  CMMahjongSpike
//
//  Created by Richard Dalley on 2017-09-02.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMRuleBook_h
#define CMRuleBook_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory>
#include "CMMeld.h"

using melds_t =  std::vector<CMMeld>;
using melds_itr =  melds_t::iterator;
using achievements_t =  std::vector<std::string> ;
using achievements_itr = achievements_t::iterator;

using namespace std;


class CMRuleBook {
public:
    virtual ~CMRuleBook(){}
    virtual size_t score(melds_t& melds) = 0;
    virtual size_t handSize() = 0;
    virtual achievements_t achievements() = 0;
};

class Flowers {
public:
    size_t scoreFromMelds(melds_t& melds) {
        return melds.size();
    }
};

class SelfDrawn {
public:
    size_t scoreFromMelds(melds_t& melds) {
        return 99;
    }
};

template <typename T>
class NineOrphans: public T {
public:
    size_t scoreFromMelds(melds_t& melds) {
        return 1000 + T::scoreFromMelds(melds);
    }
};

template <typename T>
class ChickenHand: public T {
public:
    size_t scoreFromMeld(melds_t& melds) {
        return 2000 + T::scoreFromMeld(melds);
    }
};

template <typename T>
class Competition: public T, public CMRuleBook {
public:
    Competition(){
        achievements_.push_back("Competition. ");
        score_ = 0;
    }
    
    achievements_t achievements(){
        return achievements_;
    }
    
    
    size_t score(melds_t& melds) {
        return score_ + T::scoreFromMelds(melds);
    }
    size_t handSize(){ return 13; }
    
private:
    achievements_t achievements_;
    size_t score_;
};

template <typename T>
class HongKong: public T, public CMRuleBook {
public:
    HongKong(){
        achievements_.push_back("HongKong. ");
        score_ = 0;
    }
    
    achievements_t achievements(){
        return achievements_;
    }
    
    size_t score(melds_t& melds) { return score_ + T::scoreFromMelds(melds); }
    size_t handSize(){ return 13; }
    
private:
    achievements_t achievements_;
    int score_;
};

template <typename T>
class American: public T, public CMRuleBook {
public:
    American(){
        achievements_.push_back("American. ");
        score_ = 0;
    }
    achievements_t achievements(){
        return achievements_;
    }
    size_t score(melds_t& melds) { return score_ + T::scoreFromMelds(melds); }
    size_t handSize(){ return 13; }
    
private:
    achievements_t achievements_;
    size_t score_;
};


template <typename T>
class Riichi: public T, public CMRuleBook {
public:
    Riichi(){
        achievements_.push_back("Riichi. ");
        _score = 0;
    }
    achievements_t achievements(){
        return achievements_;
    }
    size_t score(melds_t& melds) { return  _score + T::scoreFromMelds(melds); }
    size_t handSize(){ return 13; }
    
private:
    achievements_t achievements_;
    size_t _score;
};
#endif /* CMRuleBook_hpp */
