//
//  CMHand.hpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-03.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMHand_h
#define CMHand_h
#include <vector>
#include "CMGlobalEnums.h"
#include "CMTile.h"
#include "CMWall.h"
#include "CMRuleBook.h"
#include "CMMeld.h"
#include "CMHandScore.h"
#include "CMHandState.h"
#include "CMAction.h"
#include "CMHandActions.h"

using namespace std;

class CMBuildHandState;
class CMWaitingTurnState;
class CMInTurnState;
class CMWaitingMahjong;

class CMHand {
    
public:
    
    CMHand(CMWind seatWind, CMWind prevailingWind, CMRuleBook* ruleBook);
    ~CMHand();
    
    void handleAction(CMHandAction action, CMTile* tile = nullptr, CMHand* other=nullptr);

    size_t size();
    
    bool canPung();
    bool canChow();
    bool canKong();
    bool canPair(CMTile* tile);
    bool drewKong();
    bool hasKongInHand();
    bool canMahjong(CMTile* mahjongTile);
    bool canMahjong();
    bool contains(unsigned int uid);
    bool contains(CMTile* tile);
    
    size_t score();
    
    string chowStrings();
    string pungString();
    string kongString();
    string flowerStrings();

    CMTile* tileAt(size_t position);
    CMTile* tileForUid(unsigned int uid);
    CMTile* discard();
    CMTile* autoDiscard();
    CMTile* drawnTile;
    CMTile* selected;
    CMWall* wall;
    
    rawTiles_t hand;
    rawTiles_t discards;
    rawTiles_t flowers;
    rawTiles_t seasons;

    
private:
    CMActions* actions_;
    CMHandState* state_;
    CMRuleBook* ruleBook_;
    CMWind seatWind_;
    CMWind _prevailingWind;
    CMHandScore* _score;
    
    
    melds_t melds_;
    melds_t kongs_;
    melds_t pungs_;
    melds_t chows_;
    
    bool evaluate(CMTile* matchingTile);
    void evaluateMelds(rawTile_it& begin);
    bool match(CMTile* first, CMTile* second);
    bool lastMeld( rawTile_it& itr );
    
    void robKong(CMTile* tile);
    void selectMeld(CMMeld* meld, bool concealed=false);
    void setConcealedKong(CMMeld* kong) ;
    void findMelds(CMTile* matchingTile);
    
    rawTile_it firstFree(rawTile_it begin, CMMeld& chow);
    rawTile_it nextInSequence(rawTile_it itr);
    
    vector<unsigned int> uids_;
    
    friend class CMHandState;
    friend class CMBuildHandState;
    friend class CMWaitingTurnState;
    friend class CMInTurnState;
    friend class CMWaitingMahjong;
    friend class CMStartGameState;
    
};




#endif /* CMHand_h */
