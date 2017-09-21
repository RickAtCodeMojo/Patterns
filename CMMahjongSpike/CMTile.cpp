//
//  CMTile.cpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-03.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#include "CMTile.h"
#include "CMTileConst.h"
CMTile::CMTile(CMTileIdentifier tid, unsigned int uid) :
meldKind_ (CMMeldKind::None),
concealed_(false),
tileId_(tid),
uid_(uid),
suit_(suitFromTileID(tid)),
category_(categoryFromTileID(tid)),
value_(valueFromTileID(tid)),
text_(textFromTileID(tid)),
imagePath_(imagePathFromTileID(tid))
{
    state_ = new CMBuiltState();
}
CMTile::~CMTile(){

    if(state_) {
        delete state_;
    }
}

unsigned int CMTile::uid() const{
    return uid_;
}

CMMahjongSuit CMTile::suit() const{
    return suit_;
}

CMMahjongCategory CMTile::category() const{
    return category_;
}

void CMTile::conceal(){
    concealed_ = true;
}

bool CMTile::concealed() const{
    return concealed_;
}
bool CMTile::sameAs(const CMTile* rhs) const{
    if (rhs) {
        if (rhs->tid() == tileId_) {
            return true;
        }
        
    }
    return false;
}

bool CMTile::after(const CMTile* rhs) const{
    if (rhs) {
        if (rhs->category() == CMMahjongCategory::Simple && category_ == CMMahjongCategory::Simple) {
            if (rhs->suit() == suit_) {
                if (value_ - rhs->value() == 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

unsigned int CMTile::value() const {
    return value_;
}

string CMTile::text() const{
    return text_;
}

string CMTile::imagePath() const{
    return imagePath_;
}

CMMeldKind CMTile::meldKind() const{
    return meldKind_;
}


bool CMTile::operator==(const CMTile& rhs) const{
    return uid_ == rhs.uid();
}

bool CMTile::operator==(const CMTile* rhs) const{
    return uid_ == rhs->uid();
}

bool CMTile::operator< (const CMTile* rhs) const{
    return tileId_ < rhs->tid();
}
bool CMTile::operator< (const CMTile& rhs) const{
    return tileId_ < rhs.tid();
}

bool CMTile::operator!= (const CMTile* rhs) const{
    return !(this==rhs);
}

bool CMTile::operator!= (const CMTile& rhs) const{
    return!(this == &rhs);
}

CMTileIdentifier CMTile::tid() const{
    return tileId_;
}

void CMTile::meld(const CMMeldKind meldKind){
    meldKind_ = meldKind;
}

void CMTile::handleAction(const CMTileAction action){
    CMTileState* state = state_->handleAction(this, action);
    if (state != nullptr) {
        delete state_;
        state_ = state;
    }
}


