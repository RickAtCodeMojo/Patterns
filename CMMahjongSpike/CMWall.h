//
//  CMWall.hpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-03.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMWall_hpp
#define CMWall_hpp

#include <vector>
#include <string>
#include "CMTile.h"
#include "CMGlobalEnums.h"
#include <cstdint>

using tiles_t =  vector<unique_ptr<CMTile> >;
using tile_itr = tiles_t::iterator;

class CMWall final{

    CMWall();
    ~CMWall();

public:
    static CMWall& getInstance();
    void build();
    void shuffle();
    void clear();

    size_t countOf(CMTileIdentifier& tileIndex);
    CMTile* draw();
    CMTile* tileFromID(uint32_t tileID);
    tile_itr next();
    size_t size();
    size_t remaining();
    bool empty();
    CMWall(const CMWall&) = delete;
    CMWall& operator=(const CMWall&) = delete;
    CMWall(CMWall&&) = delete;
    CMWall& operator=(CMWall&&) = delete;

private:
    tiles_t wall_;
    tile_itr next_;
    CMTile* drawn_;

};

#endif /* CMWall_hpp */
