//
//  CMWall.cpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-03.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#include "CMWall.h"
int getRandom (int i) {
    return std::rand()%i;
}

CMWall::CMWall(){
    srand( (unsigned int)time(NULL) );
}

CMWall::~CMWall(){
    clear();
}

CMWall& CMWall::getInstance()
{
    static CMWall instance;
    return instance;
}

tile_itr CMWall::next(){
    return next_;
}

CMTile* CMWall::draw(){
    drawn_ = nullptr;
    if (next_ != wall_.end()) {
        ++ next_;
        if (next_ != wall_.end()) {
            drawn_ =  (*next_).get();
            cout << "Drew:" << drawn_->text() << endl;
        }
    }
   
    return (drawn_);
    
}

CMTile* CMWall::tileFromID(uint32_t tileID){
    CMTile* tile = nullptr;
    for (tile_itr itr = next_; itr != wall_.end(); ++itr) {
        tile = (*itr).get();
        if (tile->uid() == tileID) {
            return tile;
        }
    }
    return nullptr;
}

size_t CMWall::size(){
    return wall_.size();
}

bool CMWall::empty(){
    return next_ == wall_.end();
}
size_t CMWall::remaining(){
    return wall_.size() - std::distance(wall_.begin(), next_);
}


size_t CMWall::countOf(CMTileIdentifier& tileIndex){
    size_t count = 0;
    for (tile_itr itr = next_; itr != wall_.end(); ++itr) {
        if ((*itr)->tid() == tileIndex) {
            ++count;
        }
    }
    return count;
}


void CMWall::build(){
    unsigned int uid = 0;
    //for(int n = 0; n < 34; ++ n){
    for (int c = 0; c < 4; ++c ) {
        for(int tid = 0; tid < 34; ++ tid){
            wall_.push_back( unique_ptr<CMTile>(new CMTile((CMTileIdentifier)tid, uid)  ));
            ++uid;
        }
    }
    
    for(int tid = 34; tid < 42; ++ tid){
        wall_.push_back( unique_ptr<CMTile>(new CMTile((CMTileIdentifier)tid, uid)  ));
        ++uid;
    }
    next_ = wall_.begin();
}

void CMWall::shuffle(){
    random_shuffle(wall_.begin(), wall_.end(), getRandom);

}

void CMWall::clear(){
    wall_.clear();
}
