//
//  CMTile.hpp
//  CMMahjongSpike
//
//  Created by Richard Dalley on 2017-09-03.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMTile_hpp
#define CMTile_hpp
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "CMGlobalEnums.h"
#include "CMTileState.h"

using namespace std;
using rawTiles_t = vector<CMTile*>;
using rawTile_it = rawTiles_t::iterator;

class CMMeldState;
class CMTakenState;
class CMDrawnState;
class CMHeldState;
class CMMahjongState;
class CMDiscardState;
class CMBuiltState;

class CMTile {
    
    friend class CMMeldState;
    friend class CMTakenState;
    friend class CMDrawnState;
    friend class CMHeldState;
    friend class CMMahjongState;
    friend class CMDiscardState;
    friend class CMBuiltState;

private:
    CMTileState* state_;
    CMMeldKind meldKind_;
    bool concealed_;
    
    const unsigned int uid_;
    const string text_;
    const string imagePath_;
    const CMTileIdentifier tileId_;
    const CMMahjongSuit suit_;
    const CMMahjongCategory category_;
    const unsigned int value_;
    
    void conceal();
    void meld(const CMMeldKind meldKind);

public:
    
    CMTile(CMTileIdentifier tid, unsigned int uid);
    ~CMTile();
    
    unsigned int uid() const;
    unsigned int value() const;
    
    CMTileIdentifier tid() const;
    CMMahjongSuit suit() const;
    CMMahjongCategory category() const;
    CMMeldKind meldKind() const;
    
    string text() const;
    string imagePath() const;
    
    bool concealed() const;
    
    bool sameAs(const CMTile* rhs) const;
    bool after(const CMTile* rhs) const;
    
    bool operator== (const CMTile* rhs) const;
    bool operator== (const CMTile& rhs) const;
    bool operator!= (const CMTile* rhs) const;
    bool operator!= (const CMTile& rhs) const;
    bool operator< (const CMTile* rhs) const;
    bool operator< (const CMTile& rhs) const;
    
    void handleAction(const CMTileAction action);
    

    
};



#endif /* CMTile_hpp */
