//
//  CMMeld.h
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-03.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMMeld_h
#define CMMeld_h

#include "CMTile.h"
#include "CMWall.h"

struct CMMeld {
    
    CMMeld(CMMeldKind _kind) : kind(_kind){
        first = nullptr;
        second = nullptr;
        third = nullptr;
        fourth = nullptr;
        complete = false;
    }
    
    CMMeld(CMMeldKind _kind, rawTile_it _first) :
    kind(_kind),
    suit((*_first)->suit()),
    first( (*_first) ),
    category( (*_first)->category() ) {
        second = nullptr;
        third = nullptr;
        fourth = nullptr;
        complete = false;
    }
    
    CMMahjongSuit suit;
    CMMeldKind kind;
    CMMahjongCategory category;
    
    CMTile* first;
    CMTile* second;
    CMTile* third;
    CMTile* fourth;
    rawTile_it next;
    
    bool complete;
    
    bool operator==(const CMMeld& other) {
        
        bool same = true;
        
        if(first && other.first)
        {
            same = first->sameAs(other.first);
        }
        if(second && other.second ){
            same = same && second->sameAs(other.second);
        }
        if(third && other.third ) {
            same = same && third->sameAs(other.third);
        }
        if(fourth && other.fourth ) {
            same = same && fourth->sameAs(other.fourth);
        }
        return same;
    }
    
    bool operator!=(const CMMeld& other) {
        
        return !(*this == other);
    }
    
    CMMeld& operator = (const CMMeld &rhs ) {
        suit = rhs.suit;
        kind = rhs.kind;
        category = rhs.category;
        first = rhs.first;
        second = rhs.second;
        third = rhs.third;
        fourth = rhs.fourth;
        complete = rhs.complete;
        
        return *this;
    }
    
    bool contains(CMTile* tile) {
        
        if (first != nullptr ) {
            if( first == tile ) {
                return true;
            }
        }
        if (second != nullptr  ) {
            if( second == tile ) {
                return true;
            }
        }
        if (third != nullptr ) {
            if( third == tile ) {
                return true;
            }
        }
        if (fourth != nullptr) {
            if( fourth == tile ) {
                return true;
            }
        }
        return false;
    }
    
    bool containsTileFrom(CMMeld& other){
        
        if (other.first != nullptr ) {
            if( contains(other.first) ) {
                return true;
            }
        }
        if (other.second != nullptr  ) {
            if( contains(other.second) ) {
                return true;
            }
        }
        if (other.third != nullptr ) {
            if( contains(other.third) ) {
                return true;
            }
        }
        if (other.fourth != nullptr) {
            if( contains(other.fourth) ) {
                return true;
            }
        }
        return false;
        
    }
    
    void show(){
        if (first != nullptr && second != nullptr && third != nullptr && fourth != nullptr) {
            cout << first->text() << ", " << second->text() << ", " << third->text() << ", "<< fourth->text() << endl;
        }
        else if (first != nullptr && second != nullptr && third != nullptr ) {
            cout << first->text() << ", " << second->text() << ", "<< third->text() << endl;
        }
        else if (first != nullptr && second != nullptr ) {
            cout << first->text() << ", " << second->text() << endl;
        }
    }
};

#endif /* CMMeld_h */
