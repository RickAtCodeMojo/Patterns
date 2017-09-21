//
//  CMGlobalEnums.h
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-03.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMGlobalEnums_h
#define CMGlobalEnums_h

enum class CMAchievementLevel{
    None,
    Noteworthy,
    Rare,
    Epic,
    Legendary
};

enum class CMEvent{
    wonGame,
    robbedKong
};
enum class CMAchievement{
        BigFourWinds,
        BigThreeDragons,
        AllGreen,
        NineGates,
        FourKongs,
        SevenShiftedPairs,
        ThirteenOrphans,
        AllTerminals,
        LittleFourWinds,
        LittleThreeDragons,
        AllHonors,
        FourConcealedPungs,
        PureTerminalChows,
        QuadrupleChow,
        FourPureShiftedPungs,
        FourPureShiftedChows,
        ThreeKongs,
        AllTerminalsAndHonors,
        SevenPairs,
        AllEvenPungs,
        FullFlush,
        PureShiftedPungs,
        UpperTiles,
        MiddleTiles,
        LowerTiles,
        UpperFour,
        LowerFour,
        BigThreeWinds
    
};
enum class CMMeldKind {
    Chow,
    Pung,
    Kong,
    Pair,
    Mahjong,
    None
};

enum class CMPlayerAction{
    DrawHand,
    StartTurn,
    Draw,
    SelectDiscard,
    Discard,
    Chow,
    Pung,
    Kong,
    ConcealKong,
    RobKong,
    Mahjong
};

enum class CMHandAction{
    BuildHand,
    StartTurn,
    Draw,
    Keep,
    Chow,
    Pung,
    Kong,
    ConcealKong,
    Discard,
    SelectDiscard,
    Take,
    Rob,
    Reveal,
    Mahjong,
    Show
};

enum class CMTileIdentifier{
    CoinsOne,
    CoinsTwo,
    CoinsThree,
    CoinsFour,
    CoinsFive,
    CoinsSix,
    CoinsSeven,
    CoinsEight,
    CoinsNine,
    BambooOne,
    BambooTwo,
    BambooThree,
    BambooFour,
    BambooFive,
    BambooSix,
    BambooSeven,
    BambooEight,
    BambooNine,
    WanOne,
    WanTwo,
    WanThree,
    WanFour,
    WanFive,
    WanSix,
    WanSeven,
    WanEight,
    WanNine,
    WindEast,
    WindSouth,
    WindWest,
    WindNorth,
    DragonRed,
    DragonGreen,
    DragonWhite,
    FlowerPlum,
    FlowerOrchid,
    FlowerChrysanthamum,
    FlowerBamboo,
    SeasonSpring,
    SeasonSummer,
    SeasonAutumn,
    SeasonWinter,
    Joker
};

enum class CMMahjongSuit {
    Coins,
    Bamboo,
    Wan,
    Wind,
    Dragon,
    Flower,
    Season,
    None
};

enum class CMMahjongCategory {
    None,
    Simple,
    Honors,
    Flower,
    Season,
    Joker
};

enum class CMWind{
    East = 0,
    South,
    West,
    North
};

enum class CMDragon{
    Red = 0,
    Green,
    White
};

enum class CMSeason{
    Spring = 0,
    Summer,
    Autumn,
    Winter
};

enum class CMFlower{
    Plum = 0,
    Orchid,
    Chrysanthamum,
    Bamboo
    
};

#endif /* CMGlobalEnums_h */
