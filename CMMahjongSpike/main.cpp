//
//  main.cpp
//  CMMahjongSpike
//
//  Created by Richard Dalley on 2017-09-02.
//  Copyright © 2017 CodeMojo. All rights reserved.
//


#include "CMMatch.h"
#include <cstdint>

using namespace std;

int main(int argc, const char * argv[]) {
    /*
    std::vector<std::unique_ptr<CMRuleBook>> rulebooks;
    
    rulebooks.emplace_back(new Competition<ChickenHand<Flowers>>());
    rulebooks.emplace_back(new Competition<ChickenHand<SelfDrawn>>());
    rulebooks.emplace_back(new Competition<NineOrphans<Flowers>>());
    rulebooks.emplace_back(new Competition<NineOrphans<SelfDrawn>>());
    rulebooks.emplace_back(new HongKong<ChickenHand<Flowers>>());
    rulebooks.emplace_back(new HongKong<ChickenHand<SelfDrawn>>());
    rulebooks.emplace_back(new HongKong<NineOrphans<Flowers>>());
    rulebooks.emplace_back(new HongKong<NineOrphans<SelfDrawn>>());
    rulebooks.emplace_back(new American<ChickenHand<Flowers>>());
    rulebooks.emplace_back(new American<ChickenHand<SelfDrawn>>());
    rulebooks.emplace_back(new American<NineOrphans<Flowers>>());
    rulebooks.emplace_back(new American<NineOrphans<SelfDrawn>>());
    rulebooks.emplace_back(new Riichi<ChickenHand<SelfDrawn>>());
    rulebooks.emplace_back(new Riichi<ChickenHand<Flowers>>());
    rulebooks.emplace_back(new Riichi<NineOrphans<SelfDrawn>>());
    rulebooks.emplace_back(new Riichi<NineOrphans<Flowers>>());
    */
    
//    for (auto &rules: rulebooks) { cout << rules->score(_melds) << endl; }

    //create a match
    CMMatch match;
    
    //add the four players
    match.handleInput(0, 0, ADD_player);
    match.handleInput(UINT32_MAX, 1, ADD_player);
    match.handleInput(UINT32_MAX, 2, ADD_player);
    match.handleInput(UINT32_MAX, UINT32_MAX, ADD_player);
    
    //play a match
    while(!match.ended()) {
        //every player takes a turn
        for (int playerID = 0; playerID < 4; ++playerID) {
            match.handleInput(playerID, UINT32_MAX, TAP_Wall); //draw a tile
            match.handleInput(playerID, UINT32_MAX, TAP_HandMember, UINT8_MAX); //select a card for potential discard
            match.handleInput(playerID, UINT32_MAX, TAP_SelectedHandMember); //if the player taps the selected card, discard it
        }
    }

    return 0;
 
}
