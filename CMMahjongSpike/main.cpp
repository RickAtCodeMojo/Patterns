//
//  main.cpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-02.
//  Copyright © 2017 CodeMojo. All rights reserved.
//


#include "CMMatch.h"
#include <cstdint>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
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
    
    melds_t _melds;
//    for (auto &rules: rulebooks) { cout << rules->score(_melds) << endl; }

    CMMatch match;
    match.handleInput(0, 0, ADD_player);
    match.handleInput(UINT32_MAX, 1, ADD_player);
    match.handleInput(UINT32_MAX, 2, ADD_player);
    match.handleInput(UINT32_MAX, UINT32_MAX, ADD_player);
    while(!match.ended()) {
        for (int playerID = 0; playerID < 4; ++playerID) {
            match.handleInput(playerID, UINT32_MAX, TAP_Wall);
            match.handleInput(playerID, UINT32_MAX, TAP_HandMember, UINT8_MAX);
            match.handleInput(playerID, UINT32_MAX, TAP_SelectedHandMember);
        }

 
    }
//    std::cout << "Press enter to exit...";
//    std::cin.get();
    return 0;
 
}
