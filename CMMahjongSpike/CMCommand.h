//
//  CMCommand.h
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-06.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMCommand_h
#define CMCommand_h
#include <cstdint>
#include <memory>

using namespace std;

extern const unsigned int TAP_Discard;
extern const unsigned int TAP_Wall;
extern const unsigned int TAP_OpponentKong;
extern const unsigned int TAP_HandMember;
extern const unsigned int TAP_SelectedHandMember;
extern const unsigned int TAP_Chow;
extern const unsigned int TAP_tapPung;
extern const unsigned int TAP_tapKong;
extern const unsigned int ADD_player;

class CMPlayer;
class CMTile;
class CMCommand{
public:
    virtual ~CMCommand(){}
    virtual void perform(CMPlayer* player, CMPlayer* opponent=nullptr, CMTile* tile=nullptr) = 0;
};

class CMTapDiscard : public CMCommand{
    void perform(CMPlayer* player, CMPlayer* opponent, CMTile* tile);
};

class CMTapWall : public CMCommand{
    void perform(CMPlayer* player, CMPlayer* opponent=nullptr, CMTile* tile=nullptr);
    
};

class CMTapOpponentKong : public CMCommand{
    void perform(CMPlayer* player, CMPlayer* opponent, CMTile* tile);
    
};

class CMTapHandMember : public CMCommand{
    void perform(CMPlayer* player, CMPlayer* opponent=nullptr, CMTile* tile=nullptr);
    
};

class CMTapSelectedHandMember : public CMCommand{
    void perform(CMPlayer* player, CMPlayer* opponent=nullptr, CMTile* tile=nullptr);
};

class CMTapChow : public CMCommand{
    void perform(CMPlayer* player, CMPlayer* opponent, CMTile* tile);
    
};

class CMTapPung: public CMCommand{
    void perform(CMPlayer* player, CMPlayer* opponent, CMTile* tile);
    
};

class CMTapKong : public CMCommand{
    void perform(CMPlayer* player, CMPlayer* opponent, CMTile* tile);
    
};

class CMInputHandler{

public:
    CMInputHandler();
    ~CMInputHandler();
    CMCommand* handleInput(uint32_t command);

private:
    unique_ptr<CMCommand> tapDiscard_;
    unique_ptr<CMCommand> tapWall_;
    unique_ptr<CMCommand> tapOpponentKong_;
    unique_ptr<CMCommand> tapHandMember_;
    unique_ptr<CMCommand> tapSelectedHandMember_;
    unique_ptr<CMCommand> tapChow_;
    unique_ptr<CMCommand> tapPung_;
    unique_ptr<CMCommand> tapKong_;

};
#endif /* CMCommand_h */
