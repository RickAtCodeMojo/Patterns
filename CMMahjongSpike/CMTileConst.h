//
//  CMTileConst.h
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-20.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMTileConst_h
#define CMTileConst_h

string imagePathFromTileID(const CMTileIdentifier& tileIndex){
    switch(tileIndex){
        case  CMTileIdentifier::CoinsOne:  return "Bing1.svg"; break;
        case  CMTileIdentifier::CoinsTwo:  return "Bing2.svg"; break;
        case  CMTileIdentifier::CoinsThree:  return "Bing3.svg"; break;
        case  CMTileIdentifier::CoinsFour:  return "Bing4.svg"; break;
        case  CMTileIdentifier::CoinsFive:  return "Bing5.svg"; break;
        case  CMTileIdentifier::CoinsSix:  return "Bing6.svg"; break;
        case  CMTileIdentifier::CoinsSeven:  return "Bing7.svg"; break;
        case  CMTileIdentifier::CoinsEight:  return "Bing8.svg"; break;
        case  CMTileIdentifier::CoinsNine:  return "Bing9.svg"; break;
        case  CMTileIdentifier::BambooOne:  return "Tiao1.svg"; break;
        case  CMTileIdentifier::BambooTwo:  return "Tiao2.svg"; break;
        case  CMTileIdentifier::BambooThree:  return "Tiao3.svg"; break;
        case  CMTileIdentifier::BambooFour:  return "Tiao4.svg"; break;
        case  CMTileIdentifier::BambooFive:  return "Tiao5.svg"; break;
        case  CMTileIdentifier::BambooSix:  return "Tiao6.svg"; break;
        case  CMTileIdentifier::BambooSeven:  return "Tiao7.svg"; break;
        case  CMTileIdentifier::BambooEight:  return "Tiao8.svg"; break;
        case  CMTileIdentifier::BambooNine:  return "Tiao9.svg"; break;
        case  CMTileIdentifier::WanOne:  return "Wan1.svg"; break;
        case  CMTileIdentifier::WanTwo:  return "Wan2.svg"; break;
        case  CMTileIdentifier::WanThree:  return "Wan3.svg"; break;
        case  CMTileIdentifier::WanFour:  return "Wan4.svg"; break;
        case  CMTileIdentifier::WanFive:  return "Wan5.svg"; break;
        case  CMTileIdentifier::WanSix:  return "Wan6.svg"; break;
        case  CMTileIdentifier::WanSeven:  return "Wan7.svg"; break;
        case  CMTileIdentifier::WanEight:  return "Wan8.svg"; break;
        case  CMTileIdentifier::WanNine:  return "Wan9.svg"; break;
        case  CMTileIdentifier::WindEast:  return "FengDong.svg"; break;
        case  CMTileIdentifier::WindSouth:  return "FengNan.svg"; break;
        case  CMTileIdentifier::WindWest:  return "FengXi.svg"; break;
        case  CMTileIdentifier::WindNorth:  return "FengBei.svg"; break;
        case  CMTileIdentifier::DragonRed:  return "DHongZhong.svg"; break;
        case  CMTileIdentifier::DragonGreen:  return "DFa.svg"; break;
        case  CMTileIdentifier::DragonWhite:  return "DBei.svg"; break;
        case  CMTileIdentifier::FlowerPlum:  return "FMei"; break;
        case  CMTileIdentifier::FlowerOrchid:  return "FLan"; break;
        case  CMTileIdentifier::FlowerChrysanthamum:  return "FJu"; break;
        case  CMTileIdentifier::FlowerBamboo:  return "FZhu"; break;
        case  CMTileIdentifier::SeasonSpring:  return "Spring.svg"; break;
        case  CMTileIdentifier::SeasonSummer:  return "Summer.svg"; break;
        case  CMTileIdentifier::SeasonAutumn:  return "Autumn.svg"; break;
        case  CMTileIdentifier::SeasonWinter:  return "Winter.svg"; break;
        case  CMTileIdentifier::Joker:  return "Joker.svg"; break;
    }
    return "";
}


string textFromTileID(const CMTileIdentifier& tileIndex) {
    switch(tileIndex)
    {
        case CMTileIdentifier::CoinsOne:{
            return "One Coins";
        }
            break;
            
        case CMTileIdentifier::CoinsTwo:{
            return "Two Coins";
        }
            break;
            
        case CMTileIdentifier::CoinsThree:{
            return "Three Coins";
        }
            break;
            
        case CMTileIdentifier::CoinsFour:{
            return "Four Coins";
        }
            break;
            
        case CMTileIdentifier::CoinsFive:{
            return "Five Coins";
        }
            break;
            
        case CMTileIdentifier::CoinsSix:{
            return "Six Coins";
        }
            break;
            
        case CMTileIdentifier::CoinsSeven:{
            return "Seven Coins";
        }
            break;
            
        case CMTileIdentifier::CoinsEight:{
            return "Eight Coins";
        }
            break;
            
        case CMTileIdentifier::CoinsNine:{
            return "Nine Coins";
        }
            break;
            
        case CMTileIdentifier::BambooOne:{
            return "One Bamboo";
        }
            break;
            
        case CMTileIdentifier::BambooTwo:{
            return "Two Bamboo";
        }
            break;
            
        case CMTileIdentifier::BambooThree:{
            return "Three Bamboo";
        }
            break;
            
        case CMTileIdentifier::BambooFour:{
            return "Four Bamboo";
        }
            break;
            
        case CMTileIdentifier::BambooFive:{
            return "Five Bamboo";
        }
            break;
            
        case CMTileIdentifier::BambooSix:{
            return "Six Bamboo";
        }
            break;
            
        case CMTileIdentifier::BambooSeven:{
            return "Seven Bamboo";
        }
            break;
            
        case CMTileIdentifier::BambooEight:{
            return "Eight Bamboo";
        }
            break;
            
        case CMTileIdentifier::BambooNine:{
            return "Nine Bamboo";
        }
            break;
            
        case CMTileIdentifier::WanOne:{
            return "One Wan";
        }
            break;
            
        case CMTileIdentifier::WanTwo:{
            return "Two Wan";
        }
            break;
            
        case CMTileIdentifier::WanThree:{
            return "Three Wan";
        }
            break;
            
        case CMTileIdentifier::WanFour:{
            return "Four Wan";
        }
            break;
            
        case CMTileIdentifier::WanFive:{
            return "Five Wan";
        }
            break;
            
        case CMTileIdentifier::WanSix:{
            return "Six Wan";
        }
            break;
            
        case CMTileIdentifier::WanSeven:{
            return "Seven Wan";
        }
            break;
            
        case CMTileIdentifier::WanEight:{
            return "Eight Wan";
        }
            break;
            
        case CMTileIdentifier::WanNine:{
            return "Nine Wan";
        }
            break;
            
        case CMTileIdentifier::WindEast:{
            return "East Wind";
        }
            break;
            
        case CMTileIdentifier::WindSouth:{
            return "South Wind";
        }
            break;
            
        case CMTileIdentifier::WindWest:{
            return "West Wind";
        }
            break;
            
        case CMTileIdentifier::WindNorth:{
            return "North Wind";
        }
            break;
            
        case CMTileIdentifier::DragonRed:{
            return "Red Dragon";
        }
            break;
            
        case CMTileIdentifier::DragonGreen:{
            return "Green Dragon";
        }
            break;
            
        case CMTileIdentifier::DragonWhite:{
            return "White Dragon";
        }
            break;
            
        case CMTileIdentifier::FlowerPlum:{
            return "Plum";
        }
            break;
            
        case CMTileIdentifier::FlowerOrchid:{
            return "Orchid";
        }
            break;
            
        case CMTileIdentifier::FlowerChrysanthamum:{
            return "Chrysanthamum";
        }
            break;
            
        case CMTileIdentifier::FlowerBamboo:{
            return "Bamboo";
        }
            break;
            
        case CMTileIdentifier::SeasonSpring:{
            return "Spring";
        }
            break;
            
        case CMTileIdentifier::SeasonSummer:{
            return "Summer";
        }
            break;
            
        case CMTileIdentifier::SeasonAutumn:{
            return "Autumn";
        }
            break;
            
        case CMTileIdentifier::SeasonWinter:{
            return "Winter";
        }
            break;
            
        default:{
            return "Joker";
        }
            
    }
}
constexpr CMMahjongSuit suitFromTileID(const CMTileIdentifier& tileIndex){
    switch(tileIndex)
    {
        case CMTileIdentifier::CoinsOne:{
            return CMMahjongSuit::Coins;
        }
            break;
            
        case CMTileIdentifier::CoinsTwo:{
            return CMMahjongSuit::Coins;
        }
            break;
            
        case CMTileIdentifier::CoinsThree:{
            return CMMahjongSuit::Coins;
        }
            break;
            
        case CMTileIdentifier::CoinsFour:{
            return CMMahjongSuit::Coins;
        }
            break;
            
        case CMTileIdentifier::CoinsFive:{
            return CMMahjongSuit::Coins;
        }
            break;
            
        case CMTileIdentifier::CoinsSix:{
            return CMMahjongSuit::Coins;
        }
            break;
            
        case CMTileIdentifier::CoinsSeven:{
            return CMMahjongSuit::Coins;
        }
            break;
            
        case CMTileIdentifier::CoinsEight:{
            return CMMahjongSuit::Coins;
        }
            break;
            
        case CMTileIdentifier::CoinsNine:{
            return CMMahjongSuit::Coins;
        }
            break;
            
        case CMTileIdentifier::BambooOne:{
            return CMMahjongSuit::Bamboo;
        }
            break;
            
        case CMTileIdentifier::BambooTwo:{
            return CMMahjongSuit::Bamboo;
        }
            break;
            
        case CMTileIdentifier::BambooThree:{
            return CMMahjongSuit::Bamboo;
        }
            break;
            
        case CMTileIdentifier::BambooFour:{
            return CMMahjongSuit::Bamboo;
        }
            break;
            
        case CMTileIdentifier::BambooFive:{
            return CMMahjongSuit::Bamboo;
        }
            break;
            
        case CMTileIdentifier::BambooSix:{
            return CMMahjongSuit::Bamboo;
        }
            break;
            
        case CMTileIdentifier::BambooSeven:{
            return CMMahjongSuit::Bamboo;
        }
            break;
            
        case CMTileIdentifier::BambooEight:{
            return CMMahjongSuit::Bamboo;
        }
            break;
            
        case CMTileIdentifier::BambooNine:{
            return CMMahjongSuit::Bamboo;
        }
            break;
            
        case CMTileIdentifier::WanOne:{
            return CMMahjongSuit::Wan;
        }
            break;
            
        case CMTileIdentifier::WanTwo:{
            return CMMahjongSuit::Wan;
        }
            break;
            
        case CMTileIdentifier::WanThree:{
            return CMMahjongSuit::Wan;
        }
            break;
            
        case CMTileIdentifier::WanFour:{
            return CMMahjongSuit::Wan;
        }
            break;
            
        case CMTileIdentifier::WanFive:{
            return CMMahjongSuit::Wan;
        }
            break;
            
        case CMTileIdentifier::WanSix:{
            return CMMahjongSuit::Wan;
        }
            break;
            
        case CMTileIdentifier::WanSeven:{
            return CMMahjongSuit::Wan;
        }
            break;
            
        case CMTileIdentifier::WanEight:{
            return CMMahjongSuit::Wan;
        }
            break;
            
        case CMTileIdentifier::WanNine:{
            return CMMahjongSuit::Wan;
        }
            break;
            
        case CMTileIdentifier::WindEast:{
            return CMMahjongSuit::Wind;
        }
            break;
            
        case CMTileIdentifier::WindSouth:{
            return CMMahjongSuit::Wind;
        }
            break;
            
        case CMTileIdentifier::WindWest:{
            return CMMahjongSuit::Wind;
        }
            break;
            
        case CMTileIdentifier::WindNorth:{
            return CMMahjongSuit::Wind;
        }
            break;
            
        case CMTileIdentifier::DragonRed:{
            return CMMahjongSuit::Dragon;
        }
            break;
            
        case CMTileIdentifier::DragonGreen:{
            return CMMahjongSuit::Dragon;
        }
            break;
            
        case CMTileIdentifier::DragonWhite:{
            return CMMahjongSuit::Dragon;
        }
            break;
            
        case CMTileIdentifier::FlowerPlum:{
            return CMMahjongSuit::Flower;
        }
            break;
            
        case CMTileIdentifier::FlowerOrchid:{
            return CMMahjongSuit::Flower;
        }
            break;
            
        case CMTileIdentifier::FlowerChrysanthamum:{
            return CMMahjongSuit::Flower;
        }
            break;
            
        case CMTileIdentifier::FlowerBamboo:{
            return CMMahjongSuit::Flower;
        }
            break;
            
        case CMTileIdentifier::SeasonSpring:{
            return CMMahjongSuit::Season;
        }
            break;
            
        case CMTileIdentifier::SeasonSummer:{
            return CMMahjongSuit::Season;
        }
            break;
            
        case CMTileIdentifier::SeasonAutumn:{
            return CMMahjongSuit::Season;
        }
            break;
            
        case CMTileIdentifier::SeasonWinter:{
            return CMMahjongSuit::Season;
        }
            break;
            
        default:{
            return CMMahjongSuit::Wan;
        }
            
    }
    return CMMahjongSuit::None;
}

constexpr CMMahjongCategory categoryFromTileID(const CMTileIdentifier& tileIndex){
    switch(tileIndex)
    {
        case CMTileIdentifier::CoinsOne:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::CoinsTwo:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::CoinsThree:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::CoinsFour:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::CoinsFive:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::CoinsSix:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::CoinsSeven:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::CoinsEight:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::CoinsNine:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::BambooOne:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::BambooTwo:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::BambooThree:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::BambooFour:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::BambooFive:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::BambooSix:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::BambooSeven:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::BambooEight:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::BambooNine:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::WanOne:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::WanTwo:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::WanThree:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::WanFour:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::WanFive:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::WanSix:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::WanSeven:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::WanEight:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::WanNine:{
            return CMMahjongCategory::Simple;
        }
            break;
            
        case CMTileIdentifier::WindEast:{
            return CMMahjongCategory::Honors;
        }
            break;
            
        case CMTileIdentifier::WindSouth:{
            return CMMahjongCategory::Honors;
        }
            break;
            
        case CMTileIdentifier::WindWest:{
            return CMMahjongCategory::Honors;
        }
            break;
            
        case CMTileIdentifier::WindNorth:{
            return CMMahjongCategory::Honors;
        }
            break;
            
        case CMTileIdentifier::DragonRed:{
            return CMMahjongCategory::Honors;
        }
            break;
            
        case CMTileIdentifier::DragonGreen:{
            return CMMahjongCategory::Honors;
        }
            break;
            
        case CMTileIdentifier::DragonWhite:{
            return CMMahjongCategory::Honors;
        }
            break;
            
        case CMTileIdentifier::FlowerPlum:{
            return CMMahjongCategory::Flower;
        }
            break;
            
        case CMTileIdentifier::FlowerOrchid:{
            return CMMahjongCategory::Flower;
        }
            break;
            
        case CMTileIdentifier::FlowerChrysanthamum:{
            return CMMahjongCategory::Flower;
        }
            break;
            
        case CMTileIdentifier::FlowerBamboo:{
            return CMMahjongCategory::Flower;
        }
            break;
            
        case CMTileIdentifier::SeasonSpring:{
            return CMMahjongCategory::Season;
        }
            break;
            
        case CMTileIdentifier::SeasonSummer:{
            return CMMahjongCategory::Season;
        }
            break;
            
        case CMTileIdentifier::SeasonAutumn:{
            return CMMahjongCategory::Season;
        }
            break;
            
        case CMTileIdentifier::SeasonWinter:{
            return CMMahjongCategory::Season;
        }
            break;
            
        default:{
            return CMMahjongCategory::Joker;
        }
            
    }
    
}
constexpr unsigned int valueFromTileID(const CMTileIdentifier& tileIndex){
    switch(tileIndex)
    {
        case CMTileIdentifier::CoinsOne:{
            return 1;
        }
            break;
            
        case CMTileIdentifier::CoinsTwo:{
            return 2;
        }
            break;
            
        case CMTileIdentifier::CoinsThree:{
            return 3;
        }
            break;
            
        case CMTileIdentifier::CoinsFour:{
            return 4;
        }
            break;
            
        case CMTileIdentifier::CoinsFive:{
            return 5;
        }
            break;
            
        case CMTileIdentifier::CoinsSix:{
            return 6;
        }
            break;
            
        case CMTileIdentifier::CoinsSeven:{
            return 7;
        }
            break;
            
        case CMTileIdentifier::CoinsEight:{
            return 8;
        }
            break;
            
        case CMTileIdentifier::CoinsNine:{
            return 9;
        }
            break;
            
        case CMTileIdentifier::BambooOne:{
            return 1;
        }
            break;
            
        case CMTileIdentifier::BambooTwo:{
            return 2;
        }
            break;
            
        case CMTileIdentifier::BambooThree:{
            return 3;
        }
            break;
            
        case CMTileIdentifier::BambooFour:{
            return 4;
        }
            break;
            
        case CMTileIdentifier::BambooFive:{
            return 5;
        }
            break;
            
        case CMTileIdentifier::BambooSix:{
            return 6;
        }
            break;
            
        case CMTileIdentifier::BambooSeven:{
            return 7;
        }
            break;
            
        case CMTileIdentifier::BambooEight:{
            return 8;
        }
            break;
            
        case CMTileIdentifier::BambooNine:{
            return 9;
        }
            break;
            
        case CMTileIdentifier::WanOne:{
            return 1;
        }
            break;
            
        case CMTileIdentifier::WanTwo:{
            return 2;
        }
            break;
            
        case CMTileIdentifier::WanThree:{
            return 3;
        }
            break;
            
        case CMTileIdentifier::WanFour:{
            return 4;
        }
            break;
            
        case CMTileIdentifier::WanFive:{
            return 5;
        }
            break;
            
        case CMTileIdentifier::WanSix:{
            return 6;
        }
            break;
            
        case CMTileIdentifier::WanSeven:{
            return 7;
        }
            break;
            
        case CMTileIdentifier::WanEight:{
            return 8;
        }
            break;
            
        case CMTileIdentifier::WanNine:{
            return 9;
        }
            break;
            
        case CMTileIdentifier::WindEast:{
            return (unsigned int)CMWind::East;
        }
            break;
            
        case CMTileIdentifier::WindSouth:{
            return (unsigned int)CMWind::South;
        }
            break;
            
        case CMTileIdentifier::WindWest:{
            return (unsigned int)CMWind::West;
        }
            break;
            
        case CMTileIdentifier::WindNorth:{
            return (unsigned int)CMWind::North;
        }
            break;
            
        case CMTileIdentifier::DragonRed:{
            return (unsigned int)CMDragon::Red;
        }
            break;
            
        case CMTileIdentifier::DragonGreen:{
            return (unsigned int)CMDragon::Green;
        }
            break;
            
        case CMTileIdentifier::DragonWhite:{
            return (unsigned int)CMDragon::White;
        }
            break;
            
        case CMTileIdentifier::FlowerPlum:{
            return (unsigned int)CMFlower::Plum;
        }
            break;
            
        case CMTileIdentifier::FlowerOrchid:{
            return (unsigned int)CMFlower::Orchid;
        }
            break;
            
        case CMTileIdentifier::FlowerChrysanthamum:{
            return (unsigned int)CMFlower::Chrysanthamum;
        }
            break;
            
        case CMTileIdentifier::FlowerBamboo:{
            return (unsigned int)CMFlower::Bamboo;
        }
            break;
            
        case CMTileIdentifier::SeasonSpring:{
            return (unsigned int)CMSeason::Spring;
        }
            break;
            
        case CMTileIdentifier::SeasonSummer:{
            return (unsigned int)CMSeason::Summer;
        }
            break;
            
        case CMTileIdentifier::SeasonAutumn:{
            return (unsigned int)CMSeason::Autumn;
        }
            break;
            
        case CMTileIdentifier::SeasonWinter:{
            return (unsigned int)CMSeason::Winter;
        }
            break;
            
        default:{
            return 0;
        }
            
    }
}

#endif /* CMTileConst_h */
