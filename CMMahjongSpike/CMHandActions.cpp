//
//  CMHandActions.cpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-04.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#include "CMHandActions.h"
#include "CMHand.h"

CMShowAction::CMShowAction(CMHand* hand){
    hand_ = hand;
}
bool CMShowAction::Do() const{
    cout << endl << "Hand:";
    for (rawTile_it itr = hand_->hand.begin(); itr != hand_->hand.end(); ++itr) {
        CMTile* tile = (*itr);
        cout << tile->text() << ":" << tile->uid() << ", ";
    }
    cout << endl << "Flowers:";
    for (rawTile_it itr = hand_->flowers.begin(); itr != hand_->flowers.end(); ++itr) {
        CMTile* tile = (*itr);
        cout << tile->text() << ":" << tile->uid() << ", ";
    }
    cout << endl << "Seasons:";
    for (rawTile_it itr = hand_->seasons.begin(); itr != hand_->seasons.end(); ++itr) {
        CMTile* tile = (*itr);
        cout << tile->text() << ":" << tile->uid() << ", ";
    }
    cout << endl << "Discards:";
    for (rawTile_it itr = hand_->discards.begin(); itr != hand_->discards.end(); ++itr) {
        CMTile* tile = (*itr);
        cout << tile->text() << ":" << tile->uid() << ", ";
    }
    cout << endl;
    return true;
}

bool CMShowAction::Undo() const{
    return true;
}

string CMShowAction::name() const{
    return "CMShowAction";
}

CMDiscardAction::CMDiscardAction(CMHand* hand){
    hand_ = hand;
    discard_ = hand->selected;
}
bool CMDiscardAction::Do() const{

    for (rawTile_it itr = hand_->hand.begin(); itr != hand_->hand.end(); ++itr) {
        if (discard_->uid() == (*itr)->uid()) {
            cout << "Discarded:" << discard_->text() << endl;
            hand_->discards.push_back(discard_);
            discard_->handleAction(CMTileAction::Discard);
            hand_->hand.erase(itr);
            hand_->hand.shrink_to_fit();
            break;
        }
    }
    return true;
}

bool CMDiscardAction::Undo() const{
    return true;
}

string CMDiscardAction::name() const{
    return "CMDiscardAction";
}

CMTakeAction::CMTakeAction(CMHand* giver, CMHand* taker){
    giver_ = giver;
    taker_ = taker;
}
bool CMTakeAction::Do() const{
    taker_->hand.push_back(giver_->discards.back());
    giver_->discards.pop_back();
    return true;
}

bool CMTakeAction::Undo() const{
    return true;
}

string CMTakeAction::name() const{
    return "CMTakeAction";
}


CMDrawAction::CMDrawAction(CMHand* hand) : wall_(hand->wall){
    hand_ = hand;
}


bool CMDrawAction::Do() const{
    hand_->drawnTile = wall_->draw();
    if (hand_->drawnTile == nullptr) {
        return false;
    }
    hand_->drawnTile->handleAction(CMTileAction::Draw);
    CMMahjongSuit suit = hand_->drawnTile->suit();
    
    while (suit == CMMahjongSuit::Flower || suit == CMMahjongSuit::Season) {
        if (suit == CMMahjongSuit::Flower) {
            hand_->flowers.push_back(hand_->drawnTile);
        }
        else{
            hand_->seasons.push_back(hand_->drawnTile);
        }
        hand_->drawnTile = wall_->draw();
        hand_->drawnTile->handleAction(CMTileAction::Draw);
        suit = hand_->drawnTile->suit();
    }
    
    return true;
}

bool CMDrawAction::Undo() const{
    return true;
}

string CMDrawAction::name() const{
    return "CMDrawAction";
}

CMKeepAction::CMKeepAction(CMHand* hand) : wall_(hand->wall){
    hand_ = hand;
}
bool CMKeepAction::Do() const{
    hand_->hand.push_back(hand_->drawnTile);
    hand_->drawnTile->handleAction(CMTileAction::Keep);
    return true;
}

bool CMKeepAction::Undo() const{
    return true;
}

string CMKeepAction::name() const{
    return "CMKeepAction";
}

bool handSort(const CMTile* lhs, const CMTile* rhs) {
    
    if( lhs->meldKind() != rhs->meldKind()) {
        return (lhs->meldKind() != CMMeldKind::None);
    }
    
    return lhs->tid() < rhs->tid();
}

CMSortAction::CMSortAction(CMHand* hand){
    hand_ = hand;
}
bool CMSortAction::Do() const{
    std::sort (hand_->hand.begin(), hand_->hand.end(), handSort);
    return true;
}

bool CMSortAction::Undo() const{
    return true;
}

string CMSortAction::name() const{
    return "CMSortAction";
}


CMRobKongAction::CMRobKongAction(CMHand* taker, CMTile* kongTile){
    taker_ = taker;
    kongTile_ = kongTile;
}

bool CMRobKongAction::Do() const{
    taker_->hand.push_back(kongTile_);
    return true;
}

bool CMRobKongAction::Undo() const{
    return true;
}

string CMRobKongAction::name() const{
    return "CMRobKongAction";
}


CMRemoveAction::CMRemoveAction(CMHand* hand, CMTile* tile){
    hand_ = hand;
    uid_ = tile->uid();
}

bool CMRemoveAction::Do() const{
    for (rawTile_it itr = hand_->hand.begin(); itr != hand_->hand.end(); ++itr) {
        if ((*itr)->uid() == uid_) {
            hand_->hand.erase(itr);
            break;
        }
    }
    return true;
}

bool CMRemoveAction::Undo() const{
    return true;
}

string CMRemoveAction::name() const{
    return "CMRemoveAction";
}

CMSelectAction::CMSelectAction(CMHand* hand, CMTile* tile){
    hand_ = hand;
    tile_ = tile;
}
bool CMSelectAction::Do() const{
    hand_->selected = tile_;
    return true;
}
bool CMSelectAction::Undo() const{
    return true;
}
string CMSelectAction::name() const{
    return "CMSelectAction";
}
