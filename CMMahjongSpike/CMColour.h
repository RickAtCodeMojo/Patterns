//
//  CMColour.hpp
//  CMDesignPatterns
//
//  Created by Richard Dalley on 2017-09-05.
//  Copyright © 2017 CodeMojo. All rights reserved.
//

#ifndef CMColour_h
#define CMColour_h
#include <cstdint>
#define RGBA(r,g,b,a) ( ((uint32_t)(uint8_t)r)|((uint32_t)((uint8_t)g)<<8)|((uint32_t)((uint8_t)b)<<16) |((uint32_t)((uint8_t)a)<<24) )
#define GetRED(RGBAColor) (uint8_t) (RGBAColor)
#define GetGREEN(RGBAColor) (uint8_t) (((uint32_t)RGBAColor) >> 8)
#define GetBLUE(RGBAColor) (uint8_t) (((uint32_t)RGBAColor) >> 16)
#define GetALPHA(RGBAColor) (uint8_t) (((uint32_t)RGBAColor) >> 24)

struct CMColour{

    CMColour() : red(0), green(0), blue(0), alpha(UINT8_MAX){}
    CMColour(uint8_t r, uint8_t g, uint8_t b, uint8_t a=UINT8_MAX) : red(r), green(g), blue(b), alpha(a) {COLOR = RGBA(r, g, b, a);}
    CMColour(float r, float g, float b, float a=1.0f) : red(r * UINT8_MAX), green(g * UINT8_MAX), blue(b * UINT8_MAX), alpha(a * UINT8_MAX) {}
    CMColour(uint32_t rgba){red = GetRED(rgba); green = GetGREEN(rgba); blue = GetBLUE(rgba); alpha = GetALPHA(rgba);}
    constexpr CMColour& operator=(const CMColour& other){
        if(this != &other){
            this->red = other.red;
            this->green = other.green;
            this->blue = other.blue;
            this->alpha = other.alpha;
            COLOR = RGBA(other.red, other.green, other.blue, other.alpha);
        }
        return *this;
    }
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
    uint32_t COLOR;
    constexpr float redF(){ return red/UINT8_MAX; }
    constexpr float greenF(){ return green/UINT8_MAX; }
    constexpr float blueF(){ return blue/UINT8_MAX; }
    constexpr float alphaF(){ return alpha/UINT8_MAX; }
    static CMColour Black(){ return CMColour(0);}
    static CMColour White(){ return CMColour(0xFF);}
    static CMColour Red(){ return CMColour(RGBA(0xFF, 0, 0, 0xFF));}
    static CMColour Green(){ return CMColour(RGBA(0, 0xFF, 0, 0xFF));}
    static CMColour Blue(){ return CMColour(RGBA(0, 0, 0xFF, 0xFF));}
    static CMColour Aquamarine(){ return CMColour(RGBA( 0x70, 0xDB, 0x93, 0xFF)); }
    static CMColour Chocolate(){ return CMColour(RGBA( 0x5C, 0x33, 0x17, 0xFF)); }
    static CMColour BlueViolet(){ return CMColour(RGBA( 0x9F, 0x5F, 0x9F, 0xFF)); }
    static CMColour Brass(){ return CMColour(RGBA( 0xB5, 0xA6, 0x42, 0xFF)); }
    static CMColour LightGold(){ return CMColour(RGBA( 0xD9, 0xD9, 0x19, 0xFF)); }
    static CMColour Brown(){ return CMColour(RGBA( 0xA6, 0x2A, 0x2A, 0xFF)); }
    static CMColour Bronze(){ return CMColour(RGBA( 0x8C, 0x78, 0x53, 0xFF)); }
    static CMColour CadetBlue(){ return CMColour(RGBA( 0x5F, 0x9F, 0x9F, 0xFF)); }
    static CMColour LightCopper(){ return CMColour(RGBA( 0xD9, 0x87, 0x19, 0xFF)); }
    static CMColour Copper(){ return CMColour(RGBA( 0xB8, 0x73, 0x33, 0xFF)); }
    static CMColour Coral(){ return CMColour(RGBA( 0xFF, 0x7F, 0x00, 0xFF)); }
    static CMColour CornFlowerBlue(){ return CMColour(RGBA( 0x42, 0x42, 0x6F, 0xFF)); }
    static CMColour Cyan(){ return CMColour(RGBA( 0x00, 0xFF, 0xFF, 0xFF)); }
    static CMColour DarkBrown(){ return CMColour(RGBA( 0x5C, 0x40, 0x33, 0xFF)); }
    static CMColour DarkGreen(){ return CMColour(RGBA( 0x2F, 0x4F, 0x2F, 0xFF)); }
    static CMColour DarkGreenCopper(){ return CMColour(RGBA( 0x4A, 0x76, 0x6E, 0xFF)); }
    static CMColour DarkOliveGreen(){ return CMColour(RGBA( 0x4F, 0x4F, 0x2F, 0xFF)); }
    static CMColour DarkOrchid(){ return CMColour(RGBA( 0x99, 0x32, 0xCD, 0xFF)); }
    static CMColour DarkPurple(){ return CMColour(RGBA( 0x87, 0x1F, 0x78, 0xFF)); }
    static CMColour DarkSlateBlue(){ return CMColour(RGBA( 0x6B, 0x23, 0x8E, 0xFF)); }
    static CMColour DarkSlateGrey(){ return CMColour(RGBA( 0x2F, 0x4F, 0x4F, 0xFF)); }
    static CMColour DarkTan(){ return CMColour(RGBA( 0x97, 0x69, 0x4F, 0xFF)); }
    static CMColour DarkTurquoise(){ return CMColour(RGBA( 0x70, 0x93, 0xDB, 0xFF)); }
    static CMColour DarkWood(){ return CMColour(RGBA( 0x85, 0x5E, 0x42, 0xFF)); }
    static CMColour DarkGrey(){ return CMColour(RGBA( 0x54, 0x54, 0x54, 0xFF)); }
    static CMColour DustyRose(){ return CMColour(RGBA( 0x85, 0x63, 0x63, 0xFF)); }
    static CMColour Feldspar(){ return CMColour(RGBA( 0xD1, 0x92, 0x75, 0xFF)); }
    static CMColour Firebrick(){ return CMColour(RGBA( 0x8E, 0x23, 0x23, 0xFF)); }
    static CMColour ForestGreen(){ return CMColour(RGBA( 0x23, 0x8E, 0x23, 0xFF)); }
    static CMColour Gold(){ return CMColour(RGBA( 0xCD, 0x7F, 0x32, 0xFF)); }
    static CMColour Goldenrod(){ return CMColour(RGBA( 0xDB, 0xDB, 0x70, 0xFF)); }
    static CMColour Grey(){ return CMColour(RGBA( 0xC0, 0xC0, 0xC0, 0xFF)); }
    static CMColour GreenYellow(){ return CMColour(RGBA( 0x93, 0xDB, 0x70, 0xFF)); }
    static CMColour HunterGreen(){ return CMColour(RGBA( 0x21, 0x5E, 0x21, 0xFF)); }
    static CMColour IndianRed(){ return CMColour(RGBA( 0x4E, 0x2F, 0x2F, 0xFF)); }
    static CMColour Khaki(){ return CMColour(RGBA( 0x9F, 0x9F, 0x5F, 0xFF)); }
    static CMColour LightBlue(){ return CMColour(RGBA( 0xC0, 0xD9, 0xD9, 0xFF)); }
    static CMColour LightGrey(){ return CMColour(RGBA( 0xA8, 0xA8, 0xA8, 0xFF)); }
    static CMColour LightSteelBlue(){ return CMColour(RGBA( 0x8F, 0x8F, 0xBD, 0xFF)); }
    static CMColour LightWood(){ return CMColour(RGBA( 0xE9, 0xC2, 0xA6, 0xFF)); }
    static CMColour LimeGreen(){ return CMColour(RGBA( 0x32, 0xCD, 0x32, 0xFF)); }
    static CMColour Magenta(){ return CMColour(RGBA( 0xFF, 0x00, 0xFF, 0xFF)); }
    static CMColour LightOrange(){ return CMColour(RGBA( 0xE4, 0x78, 0x33, 0xFF)); }
    static CMColour Maroon(){ return CMColour(RGBA( 0x8E, 0x23, 0x6B, 0xFF)); }
    static CMColour MediumAquamarine(){ return CMColour(RGBA( 0x32, 0xCD, 0x99, 0xFF)); }
    static CMColour MediumBlue(){ return CMColour(RGBA( 0x32, 0x32, 0xCD, 0xFF)); }
    static CMColour MediumForestGreen(){ return CMColour(RGBA( 0x6B, 0x8E, 0x23, 0xFF)); }
    static CMColour MediumGoldenrod(){ return CMColour(RGBA( 0xEA, 0xEA, 0xAE, 0xFF)); }
    static CMColour MediumOrchid(){ return CMColour(RGBA( 0x93, 0x70, 0xDB, 0xFF)); }
    static CMColour MediumSeaGreen(){ return CMColour(RGBA( 0x42, 0x6F, 0x42, 0xFF)); }
    static CMColour MediumSlateBlue(){ return CMColour(RGBA( 0x7F, 0x00, 0xFF, 0xFF)); }
    static CMColour MediumSpringGreen(){ return CMColour(RGBA( 0x7F, 0xFF, 0x00, 0xFF)); }
    static CMColour MediumTurquoise(){ return CMColour(RGBA( 0x70, 0xDB, 0xDB, 0xFF)); }
    static CMColour MediumVioletRed(){ return CMColour(RGBA( 0xDB, 0x70, 0x93, 0xFF)); }
    static CMColour MediumWood(){ return CMColour(RGBA( 0xA6, 0x80, 0x64, 0xFF)); }
    static CMColour MidnightBlue(){ return CMColour(RGBA( 0x2F, 0x2F, 0x4F, 0xFF)); }
    static CMColour NavyBlue(){ return CMColour(RGBA( 0x23, 0x23, 0x8E, 0xFF)); }
    static CMColour HotBlue(){ return CMColour(RGBA( 0x4D, 0x4D, 0xFF, 0xFF)); }
    static CMColour HotPink(){ return CMColour(RGBA( 0xFF, 0x6E, 0xC7, 0xFF)); }
    static CMColour NewMidnightBlue(){ return CMColour(RGBA( 0x00, 0x00, 0x9C, 0xFF)); }
    static CMColour NewTan(){ return CMColour(RGBA( 0xEB, 0xC7, 0x9E, 0xFF)); }
    static CMColour OldGold(){ return CMColour(RGBA( 0xCF, 0xB5, 0x3B, 0xFF)); }
    static CMColour Orange(){ return CMColour(RGBA( 0xFF, 0x7F, 0x00, 0xFF)); }
    static CMColour BloodOrange(){ return CMColour(RGBA( 0xFF, 0x24, 0x00, 0xFF)); }
    static CMColour Orchid(){ return CMColour(RGBA( 0xDB, 0x70, 0xDB, 0xFF)); }
    static CMColour PaleGreen(){ return CMColour(RGBA( 0x8F, 0xBC, 0x8F, 0xFF)); }
    static CMColour Pink(){ return CMColour(RGBA( 0xBC, 0x8F, 0x8F, 0xFF)); }
    static CMColour Plum(){ return CMColour(RGBA( 0xEA, 0xAD, 0xEA, 0xFF)); }
    static CMColour Quartz(){ return CMColour(RGBA( 0xD9, 0xD9, 0xF3, 0xFF)); }
    static CMColour RichBlue(){ return CMColour(RGBA( 0x59, 0x59, 0xAB, 0xFF)); }
    static CMColour Salmon(){ return CMColour(RGBA( 0x6F, 0x42, 0x42, 0xFF)); }
    static CMColour Scarlet(){ return CMColour(RGBA( 0x8C, 0x17, 0x17, 0xFF)); }
    static CMColour SeaGreen(){ return CMColour(RGBA( 0x23, 0x8E, 0x68, 0xFF)); }
    static CMColour ChocolateBar(){ return CMColour(RGBA( 0x6B, 0x42, 0x26, 0xFF)); }
    static CMColour Sienna(){ return CMColour(RGBA( 0x8E, 0x6B, 0x23, 0xFF)); }
    static CMColour Silver(){ return CMColour(RGBA( 0xE6, 0xE8, 0xFA, 0xFF)); }
    static CMColour SkyBlue(){ return CMColour(RGBA( 0x32, 0x99, 0xCC, 0xFF)); }
    static CMColour SlateBlue(){ return CMColour(RGBA( 0x00, 0x7F, 0xFF, 0xFF)); }
    static CMColour SpicyPink(){ return CMColour(RGBA( 0xFF, 0x1C, 0xAE, 0xFF)); }
    static CMColour SpringGreen(){ return CMColour(RGBA( 0x00, 0xFF, 0x7F, 0xFF)); }
    static CMColour SteelBlue(){ return CMColour(RGBA( 0x23, 0x6B, 0x8E, 0xFF)); }
    static CMColour SummerSky(){ return CMColour(RGBA( 0x38, 0xB0, 0xDE, 0xFF)); }
    static CMColour Tan(){ return CMColour(RGBA( 0xDB, 0x93, 0x70, 0xFF)); }
    static CMColour Thistle(){ return CMColour(RGBA( 0xD8, 0xBF, 0xD8, 0xFF));}
    static CMColour Turquoise(){ return CMColour(RGBA( 0xAD, 0xEA, 0xEA, 0xFF)); }
    static CMColour VeryDarkBrown(){ return CMColour(RGBA( 0x5C, 0x40, 0x33, 0xFF)); }
    static CMColour PaleGrey(){ return CMColour(RGBA( 0xCD, 0xCD, 0xCD, 0xFF)); }
    static CMColour Violet(){ return CMColour(RGBA( 0x4F, 0x2F, 0x4F, 0xFF)); }
    static CMColour VioletRed(){ return CMColour(RGBA( 0xCC, 0x32, 0x99, 0xFF)); }
    static CMColour Wheat(){ return CMColour(RGBA( 0xD8, 0xD8, 0xBF, 0xFF)); }
    static CMColour Yellow(){ return CMColour(RGBA( 0xFF, 0xFF, 0x00, 0xFF)); }
    static CMColour Lemon(){ return CMColour(RGBA( 0x99, 0xCC, 0x32, 0xFF)); }
    static CMColour Citron(){ return CMColour(RGBA( 0x99, 0xCC, 0x32, 0xFF)); }
};

#endif /* CMColour_h */
