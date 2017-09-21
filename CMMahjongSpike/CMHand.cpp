//
//  CMHand.cpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-03.
//  Copyright © 2017 CodeMojo. All rights reserved.
//
#include "CMHand.h"
#define MAX_HAND_SIZE 13;


CMHand::CMHand(CMWind seatWind, CMWind prevailingWind, CMRuleBook* ruleBook) : ruleBook_(ruleBook) {
    wall = &CMWall::getInstance();
    actions_ = &CMActions::getInstance();
    seatWind_ = seatWind;
    _prevailingWind = prevailingWind;
    _score = new CMHandScore(hand.begin(), prevailingWind, seatWind, nullptr, wall, ruleBook_);
    state_ = new CMStartGameState();
}

CMHand::~CMHand(){
    if (state_) {
        delete state_;
    }
    hand.clear();
    discards.clear();
    flowers.clear();
    seasons.clear();
}

void CMHand::handleAction(CMHandAction action, CMTile* tile, CMHand* other){
    CMHandState* state = state_->handleAction(action, this, tile, other);
    if(state != nullptr){
        delete state_;
        state_ = state;
    }
}

void CMHand::selectMeld(CMMeld* meld, bool concealed){
    
}

void CMHand::setConcealedKong(CMMeld* kong){
    
}
CMTile* CMHand::autoDiscard(){
    return hand.back();
}

CMTile* CMHand::discard(){
    if (discards.empty()) {
        return nullptr;
    }
    return discards.back();
}

bool CMHand::contains(unsigned int uid){
    for (rawTile_it itr = hand.begin(); itr != hand.end(); ++itr) {
        if ((*itr)->uid() == uid) {
            return true;
        }
    }
    return false;
}

bool CMHand::contains(CMTile* tile){
    
    return contains(tile->uid());
}


size_t CMHand::size(){
    return hand.size();
}


bool CMHand::canPung(){
    return pungs_.size() > 0;
}

bool CMHand::canChow(){
    return chows_.size() > 0;
}

bool CMHand::canKong(){
    return kongs_.size() > 0;
}

bool CMHand::canPair(CMTile* tile){
    for (rawTile_it itr = hand.begin(); itr != hand.end(); ++itr) {
        
        if( tile->sameAs((*itr)) ) {
            return true;
        }
    }

    return false;
}

bool CMHand::drewKong(){
    return false;
}

bool CMHand::hasKongInHand(){
    return false;
}
bool CMHand::canMahjong(){
    return canMahjong(drawnTile);
}


bool CMHand::canMahjong(CMTile* mahjongTile){
    evaluate(mahjongTile);
    return _score->canMahjong();
}

bool CMHand::match(CMTile* first, CMTile* second) {
    
    if (_score->tileIsInAMeld(first) || _score->tileIsInAMeld(second)) {
        return false;
    }
    if (first  && second) {
        first->sameAs(second);
    }
    return false;
}

bool CMHand::lastMeld( rawTile_it& itr ) {
    if (itr == hand.end() || itr + 1 == hand.end())
    {
        return true;
    }
    return false;
}

rawTile_it CMHand::firstFree( rawTile_it begin, CMMeld& chow){
    rawTile_it itr = begin;
    itr ++;
    for (rawTile_it itr = begin; itr != hand.end(); ++itr) {
        CMTile* tile = (*itr);
        if (tile != chow.first && tile != chow.second && tile != chow.third) {
            if (!_score->tileIsInAMeld(tile)) {
                return itr;
            }
        }
    }
    return hand.end();
}

rawTile_it CMHand::nextInSequence(rawTile_it itr){
    
    CMTile* thisTile = (*itr);
    ++itr;
    CMTile* nextTile = (*itr);
    if (nextTile->after(thisTile) ) {
        if (!_score->tileIsInAMeld( nextTile ) ){
            return itr;
        }
    }
    
    return hand.end();
}

void CMHand::evaluateMelds(rawTile_it& begin) {
    
    rawTile_it itr = begin;
    rawTile_it startFrom = itr;
    if (begin == hand.end()) {
        return;
    }
    
    ++itr;
    if (itr == hand.end()) {
        return;
    }
    
    CMTile* prev = (*begin);
    CMTile* tile = (*itr);
    
    if (prev == nullptr || tile == nullptr) {
        return;
    }
    
    
    CMMeld pair(CMMeldKind::Pair, startFrom);
    CMMeld pung(CMMeldKind::Pung, startFrom);
    CMMeld kong(CMMeldKind::Kong, startFrom);
    CMMeld chow(CMMeldKind::Chow, startFrom);
    if ((*startFrom)->meldKind() != CMMeldKind::None) {
        CMMeldKind kind = (*itr)->meldKind();
        switch (kind) {
            case CMMeldKind::Chow:{
                CMMeld chow(CMMeldKind::Chow, startFrom);
                chow.second = tile;
                ++itr;
                chow.third = (*itr);
                chow.complete = true;
                ++itr;
                chow.next = itr;
                if( _score->addedMeld(chow) ){
                    evaluateMelds(chow.next);
                }
            }
                break;
                
            case CMMeldKind::Pung:{
                CMMeld pung(CMMeldKind::Pung, startFrom);
                pung.second = tile;
                ++itr;
                pung.third = (*itr);
                pung.complete = true;
                ++itr;
                pung.next = itr;
                if( _score->addedMeld(pung) ){
                    evaluateMelds( pung.next);
                }
            }
                
                break;
                
            case CMMeldKind::Kong:{
                CMMeld kong(CMMeldKind::Kong, startFrom);
                kong.second = tile;
                ++itr;
                kong.third = (*itr);
                ++itr;
                kong.fourth = (*itr);
                kong.complete = true;
                ++itr;
                kong.next = itr;
                if( _score->addedMeld(kong) ){
                    evaluateMelds( kong.next);
                }
            }
                break;
                
            case CMMeldKind::Pair:{
                CMMeld pair(CMMeldKind::Pair, startFrom);
                pair.second = tile;
                ++itr;
                pair.next = itr;
                if( _score->addedMeld(pair) ){
                    evaluateMelds( pair.next);
                }
            }
                break;
                
            default:
                break;
        }
        
    }
    else
    {
        if (match(prev, tile)) {
            pair.second = tile;
            ++itr;
            pair.next = itr;
            pair.complete = true;
        }
        
        if (pair.complete) {
            pung.first = pair.first;
            pung.second = pair.second;
            if (pair.next != hand.end()) {
                tile = (*pair.next);
                if (match(pung.second, tile)) {
                    pung.third = tile;
                    ++itr;
                    pung.next = itr;
                    pung.complete = true;
                }
            }
        }
        
        if (pung.complete) {
            kong.first = pung.first;
            kong.second = pung.second;
            kong.third = pung.third;
            if (pung.next != hand.end()) {
                tile = (*pung.next);
                if (match(kong.third, tile) && pung.complete) {
                    kong.fourth = tile;
                    ++itr;
                    kong.next = itr;
                    kong.complete = true;
                }
            }
        }
    }
    
    if (pair.complete) {
        if(_score->addedMeld(pair)){
            if (lastMeld(itr)) {
                _score->assess();
                if (_score->canMahjong()) {
                    return;
                }
            }
            evaluateMelds(pair.next);
            _score->pop();
        }
    }
    
    if (pung.complete) {
        if( _score->addedMeld(pung) ){
            if (lastMeld(itr)) {
                _score->assess();
                if (_score->canMahjong()) {
                    return;
                }
            }
            evaluateMelds(pung.next);
            _score->pop();
        }
    }
    
    if (kong.complete) {
        if( _score->addedMeld(kong) ){
            if (lastMeld(itr)) {
                _score->assess();
                if (_score->canMahjong()) {
                    return;
                }
            }
            evaluateMelds(kong.next);
            _score->pop();
        }
    }
    
    if ( begin == hand.end() ) {
        return;
    }
    
    itr = nextInSequence(startFrom);
    if (itr != hand.end()) {
        chow.second = (*itr);
        itr = nextInSequence(itr);
        if (itr != hand.end()) {
            chow.third =(*itr);
            chow.next = firstFree(begin, chow);
            if(_score->addedMeld(chow)) {
                if (lastMeld(itr)) {
                    _score->assess();
                    if (_score->canMahjong()) {
                        return;
                    }
                }
                evaluateMelds(chow.next);
                _score->pop();
                
            }
        }
    }
    
}


bool CMHand::evaluate(CMTile* matchingTile){
    if (hand.empty()) {
        return false;
    }
    
    
    //tiles.push_back(_drawnTile.get());
    hand.push_back(matchingTile);
//    sort();
    
    rawTile_it begin = hand.begin();

    evaluateMelds(begin);

    for (rawTile_it itr = hand.begin(); itr != hand.end(); ++itr) {
        if ((*itr) == matchingTile) {
            hand.erase(itr);
            break;
        }
    }
//    sort();
    return _score->canMahjong();
    
}


size_t CMHand::score(){
    return ruleBook_->score(melds_);
}

string CMHand::chowStrings(){
    return "";
}

string CMHand::pungString(){
    return "";
}

string CMHand::kongString(){
    return "";
}

string CMHand::flowerStrings(){
    return "";
}


void CMHand::findMelds(CMTile* matchingTile){
    melds_.clear();
}


