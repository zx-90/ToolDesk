/*
 * Copyright © 2018 Evgenii Zaitcev.
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD 3-Clause license.
 *
 * BSD License Usage
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     (1) Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *     (2) Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *
 *     (3)The name of the author may not be used to
 *     endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef IDATADIMENTION_H
#define IDATADIMENTION_H

#include "IData.h"
#include <math.h>

namespace DeskData {

struct metrixPrefix {
    const wchar_t* name;
    const wchar_t* prefix;
    const char factorPower;
};

const metrixPrefix METRIC_PREFIXES[] = {
    {      L"",   L"",   0},

    {  L"deca", L"da",   1},
    { L"hecto",  L"h",   2},
    {  L"kilo",  L"k",   3},
    {  L"mega",  L"M",   6},
    {  L"giga",  L"G",   9},
    {  L"tera",  L"T",  12},
    {  L"peta",  L"P",  15},
    {   L"exa",  L"E",  18},
    { L"zetta",  L"Z",  21},
    { L"yotta",  L"Y",  24},

    {  L"deci",  L"d",  -1},
    { L"centi",  L"c",  -2},
    { L"milli",  L"m",  -3},
    { L"micro",  L"μ",  -6},
    {  L"nano",  L"n",  -9},
    {  L"pico",  L"p", -12},
    { L"femto",  L"f", -15},
    {  L"atto",  L"a", -18},
    { L"zepto",  L"z", -21},
    { L"yocto",  L"y", -24}
};

const Size METRIC_PREFIXES_SIZE = sizeof(METRIC_PREFIXES) / sizeof(metrixPrefix);

const Size PREFIX_NONE = 0;
const Size PREFIX_DECA = 1;
const Size PREFIX_HECTO = 2;
const Size PREFIX_KILO = 3;
const Size PREFIX_MEGA = 4;
const Size PREFIX_GIGA = 5;
const Size PREFIX_TERA = 6;
const Size PREFIX_PETA = 7;
const Size PREFIX_EXA = 8;
const Size PREFIX_ZETTA = 9;
const Size PREFIX_YOTTA = 10;
const Size PREFIX_DECI = 11;
const Size PREFIX_CENTI = 12;
const Size PREFIX_MILLI = 13;
const Size PREFIX_MICRO = 14;
const Size PREFIX_NANO = 15;
const Size PREFIX_PICO = 16;
const Size PREFIX_FEMTO = 17;
const Size PREFIX_ATTO = 18;
const Size PREFIX_ZEPTO = 19;
const Size PREFIX_YOCTO = 20;

struct metricUnit {
    // const DataSize code;
    const wchar_t* name;
    const wchar_t* symbol;
    const bool isPrefixesAllowed;
    const bool isLogarithm10;
    const Double koefficient;
    const Double offset;
    const char metrePower;
    const char kilogramPower;
    const char secondPower;
    const char amperePower;
    const char kelvinPower;
    const char candelaPower;
};

const Double AVOGADRO = 6.02214085774e23;
const Double CELSIUS = 273.15;

const Double MINUTE = 60; // in seconds
const Double HOUR = 3600; // in seconds
const Double DAY = 86400; // in seconds
const Double YEAR = 31556926; // in seconds
const Double PI = M_PI;
const Double DEGREE = PI / 180.0; // degree to rad.
const Double DMINUTE = PI / 180.0 / 60.0; // degree to rad.
const Double DSECOND = PI / 180.0 / 60.0 / 60.0; // degree to rad.
const Double HECTAR = 10000.0;
const Double LITRE = 0.001;
const Double TONNE = 1000;

const Double ELECTRONVOLT = 1.6021765314e-19;
const Double DALTON = 1.6605388628e-27;
const Double UNIFIED_ATOMIC_MASS = DALTON;
const Double ASTRONOMICAL_UNIT = 1.495978706916e11;
const Double NU_OF_SPEED = 299792458;
const Double NU_OF_ACTION = 1.0545716818e-34;
const Double NU_OF_MASS = 9.109382616e-31;
const Double NU_OF_TIME = 1.288088667786e-21;
const Double AU_OF_CHARGE = 1.6021765314e-19;
const Double AU_OF_MASS = 9.109382616e-31;
const Double AU_OF_ACTION = 1.0545716818e-34;
const Double AU_OF_LENGHT = 0.529177210818e-10;
const Double AU_OF_ENERGY = 4.3597441775e-18;
const Double AU_OF_TIME = 2.41888432650516e-17;

const Double BAR = 100000;
const Double MILLIMETRE_OF_MERCURY = 133.332;
const Double ANGSTREM = 1e-10;
const Double NAUTICAL_MILE = 1852;
const Double BARN = 1e-28;
const Double KNOT = NAUTICAL_MILE / HOUR;
const Double NEPER_KOEF = log(10);
const Double NEPER_OFFSET = 1;
const Double BEL_KOEF = 1.0;
const Double BEL_OFFSET = 1;
const Double DECIBEL_KOEF = BEL_KOEF / 10.0;
const Double DECIBEL_OFFSET = BEL_OFFSET;
const Double OERSTED = 1000.0 / 4.0 / PI;

const Double ATMOSPHERE = 101325;
const Double MAGNITUDE_KOEF = -2.5;
const Double MAGNITUDE_OFFSET = 2.54e-6;
const Double SIDEREAL_DAY = 86164.090530833;
const Double FREE_FALL = 9.8;
const Double EARTH_MASS = 5.97219e24;
const Double EARTH_RADIUS = 6371e3;
const Double JUPITER_MASS = 1.8986e27;
const Double JUPITER_RADIUS = 69911e3;
const Double SOLAR_MASS = 1.98892e30;
const Double SOLAR_RADIUS = 6.960e8;
const Double SOLAR_LUMINOSTY = 3.827e26;
const Double PARSEK = 3.0856776e16;
const Double CRAB_NEBULAS_FLUX = 2.4e-11;
const Double FOE = 1e44;
const Double LIGHT_SECOND = NU_OF_SPEED;
const Double LIGHT_MINUTE = NU_OF_SPEED * MINUTE;
const Double LIGHT_HOUR = NU_OF_SPEED * HOUR;
const Double LIGHT_DAY = NU_OF_SPEED * DAY;
const Double LIGHT_WEEK = NU_OF_SPEED * 7 * DAY;
const Double LIGHT_YEAR = NU_OF_SPEED * YEAR;

const metricUnit METRIX_UNITS[] = {
/*
 *                 NAME  SYMBOL  PREFIX  LOG10         KOEF   OFFSET      m  kg   s   A   K  cd
 */
    {               L"",    L"",  false, false,           1,       0,     0,  0,  0,  0,  0,  0},
/*
 * Base SI units.
 *
 *
 *                 NAME  SYMBOL PREFIX  LOG10         KOEF   OFFSET      m  kg   s   A   K  cd
 */
    {          L"metre",   L"m",  true, false,           1,       0,     1,  0,  0,  0,  0,  0},
    {           L"gram",   L"g",  true, false,       0.001,       0,     0,  1,  0,  0,  0,  0},
    {         L"second",   L"s", false, false,           1,       0,     0,  0,  1,  0,  0,  0},
    {         L"ampere",   L"A",  true, false,           1,       0,     0,  0,  0,  1,  0,  0},
    {         L"kelvin",   L"K",  true, false,           1,       0,     0,  0,  0,  0,  1,  0},
    {           L"mole", L"mol",  true, false,    AVOGADRO,       0,     0,  0,  0,  0,  0,  0},
    {        L"candela",  L"cd",  true, false,           1,       0,     0,  0,  0,  0,  0,  1},

/*
 * Coherent derived SI units.
 *
 *
 *                 NAME  SYMBOL PREFIX  LOG10         KOEF   OFFSET      m  kg   s   A   K  cd
 */
    {         L"radian", L"rad", false, false,           1,       0,     0,  0,  0,  0,  0,  0},
    {      L"steradian",  L"sr", false, false,           1,       0,     0,  0,  0,  0,  0,  0},
    {          L"hertz",  L"Hz",  true, false,           1,       0,     0,  0, -1,  0,  0,  0},
    {         L"newton",   L"N",  true, false,           1,       0,     1,  1, -2,  0,  0,  0},
    {         L"paskal",  L"Pa",  true, false,           1,       0,    -1,  1, -2,  0,  0,  0},
    {          L"joule",   L"J",  true, false,           1,       0,     2,  1, -2,  0,  0,  0},
    {           L"watt",   L"W",  true, false,           1,       0,     2,  1, -3,  0,  0,  0},
    {        L"coulomb",   L"C",  true, false,           1,       0,     0,  0,  1,  1,  0,  0},
    {           L"volt",   L"V",  true, false,           1,       0,     2,  1, -3, -1,  0,  0},
    {          L"farad",   L"F",  true, false,           1,       0,    -2, -1,  4,  2,  0,  0},
    {            L"ohm",   L"Ω",  true, false,           1,       0,     2,  1, -3, -2,  0,  0},
    {        L"siemens",   L"S",  true, false,           1,       0,    -2, -1,  3,  2,  0,  0},
    {          L"weber",  L"Wb",  true, false,           1,       0,     2,  1, -2, -1,  0,  0},
    {          L"tesla",   L"T",  true, false,           1,       0,     0,  1, -2, -1,  0,  0},
    {          L"henry",   L"H",  true, false,           1,       0,     2,  1, -2, -2,  0,  0},
    { L"degree Celsius",  L"°C", false, false,           1, CELSIUS,     0,  0,  0,  0,  1,  0},
    {          L"lumen",  L"lm",  true, false,           1,       0,     0,  0,  0,  0,  0,  1},
    {            L"lux",  L"lx",  true, false,           1,       0,    -2,  0,  0,  0,  0,  1},
    {      L"becquerel",  L"Bq",  true, false,           1,       0,     0,  0, -1,  0,  0,  0},
    {           L"gray",  L"Gy",  true, false,           1,       0,     2,  0, -2,  0,  0,  0},
    {        L"sievert",  L"Sv",  true, false,           1,       0,     2,  0, -2,  0,  0,  0},
    {          L"katal", L"kat",  true, false,    AVOGADRO,       0,     0,  0, -1,  0,  0,  0},

/*
 * Non-SI units accepted for use with the International System of Units.
 *
 *
 *                 NAME  SYMBOL PREFIX  LOG10         KOEF  OFFSET      m  kg   s   A   K  cd
 */
    {         L"minute", L"min", false, false,      MINUTE,       0,     0,  0,  1,  0,  0,  0},
    {           L"hour",   L"h", false, false,        HOUR,       0,     0,  0,  1,  0,  0,  0},
    {            L"day",   L"d", false, false,         DAY,       0,     0,  0,  1,  0,  0,  0},
    {           L"year",   L"y", false, false,        YEAR,       0,     0,  0,  1,  0,  0,  0},
    {         L"degree",   L"°", false, false,      DEGREE,       0,     0,  0,  0,  0,  0,  0},
    {         L"minute",   L"'", false, false,     DMINUTE,       0,     0,  0,  0,  0,  0,  0},
    {         L"second",  L"''", false, false,     DSECOND,       0,     0,  0,  0,  0,  0,  0},
    {        L"hectare",  L"ha", false, false,      HECTAR,       0,     2,  0,  0,  0,  0,  0},
    {          L"litre",   L"L", false, false,       LITRE,       0,     3,  0,  0,  0,  0,  0},
    {          L"tonne",   L"t",  true, false,       TONNE,       0,     0,  1,  0,  0,  0,  0},
/*
 * Non-SI units whose values in SI units must be obtained experimentally.
 *273.15
 *
 *                           NAME       SYMBOL PREFIX  LOG10                 KOEF  OFFSET    m  kg   s   A   K  cd
 */
    {             L"electronvolt",       L"eV",  true, false,        ELECTRONVOLT,      0,   2,  1, -2,  0,  0,  0},
    {                   L"dalton",       L"Da",  true, false,              DALTON,      0,   0,  1,  0,  0,  0,  0},
    { L"unified atomic mass unit",        L"u", false, false, UNIFIED_ATOMIC_MASS,      0,   0,  1,  0,  0,  0,  0},
    {        L"astronomical unit",       L"ua", false, false,   ASTRONOMICAL_UNIT,      0,   1,  0,  0,  0,  0,  0},
    {            L"n.u. of speed",       L"c₀", false, false,         NU_OF_SPEED,      0,   1,  0, -1,  0,  0,  0},
    {           L"n.u. of action",        L"ℏ", false, false,        NU_OF_ACTION,      0,   2,  1, -1,  0,  0,  0},
    {             L"n.u. of mass",       L"mₑ", false, false,          NU_OF_MASS,      0,   1,  0,  0,  0,  0,  0},
    {             L"n.u. of time", L"ℏ/(mₑc₀)", false, false,          NU_OF_TIME,      0,   0,  0,  1,  0,  0,  0},
    {           L"a.u. of charge",        L"e", false, false,        AU_OF_CHARGE,      0,   0,  0,  1,  1,  0,  0},
    {             L"a.u. of mass",       L"mₑ", false, false,          AU_OF_MASS,      0,   0,  1,  0,  0,  0,  0},
    {           L"a.u. of action",        L"ℏ", false, false,        AU_OF_ACTION,      0,   2,  1, -1,  0,  0,  0},
    {           L"a.u. of length",       L"a₀", false, false,        AU_OF_LENGHT,      0,   1,  0,  0,  0,  0,  0},
    {           L"a.u. of energy",       L"Eₕ", false, false,        AU_OF_ENERGY,      0,   2,  1, -2,  0,  0,  0},
    {             L"a.u. of time",     L"ℏ/Eₕ", false, false,          AU_OF_TIME,      0,   0,  0,  1,  0,  0,  0},

/*
 * Other non-SI units.
 *
 *
 *                        NAME   SYMBOL PREFIX  LOG10                   KOEF          OFFSET      m  kg   s   A   K  cd
 */
    {                   L"bar",  L"bar", false, false,                   BAR,              0,    -1,  1, -2,  0,  0,  0},
    { L"millimetre of mercury", L"mmHg", false, false, MILLIMETRE_OF_MERCURY,              0,    -1,  1, -2,  0,  0,  0},
    {              L"ångström",    L"Å", false, false,              ANGSTREM,              0,     1,  0,  0,  0,  0,  0},
    {         L"nautical mile",    L"M", false, false,         NAUTICAL_MILE,              0,     1,  0,  0,  0,  0,  0},
    {                  L"barn",    L"b", false, false,                  BARN,              0,     2,  0,  0,  0,  0,  0},
    {                  L"knot",   L"kn", false, false,                  KNOT,              0,     1,  0, -1,  0,  0,  0},
    {                 L"neper",   L"Np", false,  true,            NEPER_KOEF,   NEPER_OFFSET,     0,  0,  0,  0,  0,  0},
    {                   L"bel",    L"B", false,  true,              BEL_KOEF,     BEL_OFFSET,     0,  0,  0,  0,  0,  0},
    {               L"decibel",   L"dB", false,  true,          DECIBEL_KOEF, DECIBEL_OFFSET,     0,  0,  0,  0,  0,  0},
/*
 * Non-SI units associated with the CGS and the CGS-Gaussian system of units.
 *
 *
 *          NAME   SYMBOL PREFIX  LOG10     KOEF  OFFSET      m  kg   s   A   K  cd
 */
    {     L"erg",  L"erg", false, false,    1e-7,      0,     2,  1, -2,  0,  0,  0},
    {    L"dyne",  L"dyn", false, false,    1e-5,      0,     1,  1, -2,  0,  0,  0},
    {   L"poise",    L"P", false, false,    1e-1,      0,    -1,  1, -1,  0,  0,  0},
    {  L"stokes",   L"St", false, false,    1e-4,      0,     2,  0, -1,  0,  0,  0},
    {   L"stilb",   L"sb", false, false,     1e4,      0,    -2,  0,  0,  0,  0,  1},
    {    L"phot",   L"ph", false, false,     1e4,      0,    -2,  0,  0,  0,  0,  1},
    {     L"gal",  L"Gal", false, false,    1e-2,      0,     1,  0, -2,  0,  0,  0},
    { L"maxwell",   L"Mx", false, false,    1e-8,      0,     2,  1, -2, -1,  0,  0},
    {   L"gauss",    L"G", false, false,    1e-4,      0,     0,  1, -2, -2,  0,  0},
    {  L"œrsted",   L"Oe", false, false, OERSTED,      0,    -1,  0,  0,  1,  0,  0},
/*
 * Astronomic units.
 *
 *
 *                      NAME      SYMBOL PREFIX  LOG10               KOEF            OFFSET      m  kg   s   A   K  cd
 */
    { L"standart atmosphere",     L"atm", false, false,        ATMOSPHERE,                0,    -1,  1, -2,  0,  0,  0},
    {           L"magnitude",       L"m", false,  true,    MAGNITUDE_KOEF, MAGNITUDE_OFFSET,    -2,  0,  0,  0,  0,  1},
    {        L"sidereal day", L"sid.day", false, false,      SIDEREAL_DAY,                0,     0,  0,  1,  0,  0,  0},
    {           L"free fall",       L"g", false, false,         FREE_FALL,                0,     1,  0,  2,  0,  0,  0},
    {   L"mass of the Earth",      L"M⊕", false, false,        EARTH_MASS,                0,     0,  1,  0,  0,  0,  0},
    { L"radius of the Earth",      L"R⊕", false, false,      EARTH_RADIUS,                0,     1,  0,  0,  0,  0,  0},
    {        L"Jupiter mass",      L"Mⱼ", false, false,      JUPITER_MASS,                0,     0,  1,  0,  0,  0,  0},
    {      L"Jupiter radius",      L"Rⱼ", false, false,    JUPITER_RADIUS,                0,     1,  0,  0,  0,  0,  0},
    {          L"solar mass",      L"M☉", false, false,        SOLAR_MASS,                0,     0,  1,  0,  0,  0,  0},
    {        L"solar radius",      L"R☉", false, false,      SOLAR_RADIUS,                0,     1,  0,  0,  0,  0,  0},
    {    L"solar luminosity",      L"L☉", false, false,   SOLAR_LUMINOSTY,                0,     2,  1, -3,  0,  0,  0},
    {              L"parsec",      L"pc", false, false,            PARSEK,                0,     1,  0,  0,  0,  0,  0},
    {  L"Crab Nebula's flux",    L"сrab",  true, false, CRAB_NEBULAS_FLUX,                0,     0,  1, -3,  0,  0,  0},
    {          L"10^51 ergs",     L"foe",  true, false,               FOE,                0,     2,  1, -2,  0,  0,  0},
    {        L"light second",      L"ls", false, false,      LIGHT_SECOND,                0,     1,  0,  0,  0,  0,  0},
    {        L"light minute",      L"lm", false, false,      LIGHT_MINUTE,                0,     1,  0,  0,  0,  0,  0},
    {          L"light hour",      L"lh", false, false,        LIGHT_HOUR,                0,     1,  0,  0,  0,  0,  0},
    {           L"light day",      L"ld", false, false,         LIGHT_DAY,                0,     1,  0,  0,  0,  0,  0},
    {          L"light week",      L"lw", false, false,        LIGHT_WEEK,                0,     1,  0,  0,  0,  0,  0},
    {          L"light year",      L"ly", false, false,        LIGHT_YEAR,                0,     1,  0,  0,  0,  0,  0},
    {                   L"π",       L"π", false, false,                PI,                0,     0,  0,  0,  0,  0,  0}

    // TODO: How to translate to SI.
    //    { L"solar neutrino unit",     L"SNU", false, false,    1e-7,      0,     2,  1, -2,  0,  0,  0},
};

const Size METRIX_UNITS_SIZE = sizeof(METRIX_UNITS) / sizeof(metricUnit);

const Size METRIX_NONE = 0;

const Size METRIX_METRE = 1;
const Size METRIX_GRAM = 2;
const Size METRIX_SECOND = 3;
const Size METRIX_AMPERE = 4;
const Size METRIX_KELVIN = 5;
const Size METRIX_MOLE = 6;
const Size METRIX_CANDELA = 7;

const Size METRIX_RADIAN = 8;
const Size METRIX_STERADIAN = 9;
const Size METRIX_HERZ = 10;
const Size METRIX_NEWTON = 11;
const Size METRIX_PASKAL = 12;
const Size METRIX_JOULE = 13;
const Size METRIX_WATT = 14;
const Size METRIX_COULOMB = 15;
const Size METRIX_VOLT = 16;
const Size METRIX_FARAD = 17;
const Size METRIX_OHM = 18;
const Size METRIX_SIEMENS = 19;
const Size METRIX_WEBER = 20;
const Size METRIX_TESLA = 21;
const Size METRIX_HENRY = 22;
const Size METRIX_CELSIUS = 23;
const Size METRIX_LUMEN = 24;
const Size METRIX_LUX = 25;
const Size METRIX_BECQUEREL = 26;
const Size METRIX_GRAY = 27;
const Size METRIX_SIEVERT = 28;
const Size METRIX_KATAL = 29;

const Size METRIX_MINUTE = 30;
const Size METRIX_HOUR = 31;
const Size METRIX_DAY = 32;
const Size METRIX_YEAR = 33;
const Size METRIX_ANGLE_DEGREE = 34;
const Size METRIX_ANGLE_MINUTE = 35;
const Size METRIX_ANGLE_SECOND = 36;
const Size METRIX_HECTARE = 37;
const Size METRIX_LITRE = 38;
const Size METRIX_TONNE = 39;

const Size METRIX_ELECTRONVOLT = 40;
const Size METRIX_DALTON = 41;
const Size METRIX_UNIFIED_ATOMIC_MASS_UNIT = 42;
const Size METRIX_ASTRONOMICAL_UNIT = 43;
const Size METRIX_NU_OF_SPEED = 44;
const Size METRIX_NU_OF_ACTION = 45;
const Size METRIX_NU_OF_MASS = 46;
const Size METRIX_NU_OF_TIME = 47;
const Size METRIX_AU_OF_CHARGE = 48;
const Size METRIX_AU_OF_MASS = 49;
const Size METRIX_AU_OF_ACTION = 50;
const Size METRIX_AU_OF_LENGTH = 51;
const Size METRIX_AU_OF_ENERGY = 52;
const Size METRIX_AU_OF_TIME = 53;

const Size METRIX_BAR = 54;
const Size METRIX_MILLIMETRE_OF_MERCURY = 55;
const Size METRIX_ANGSTROM = 56;
const Size METRIX_NAUTICAL_MILE = 57;
const Size METRIX_BARN = 58;
const Size METRIX_KNOT = 59;
const Size METRIX_NEPER = 60;
const Size METRIX_BEL = 61;
const Size METRIX_DECIBEL = 62;

const Size METRIX_ERG = 63;
const Size METRIX_DYNE = 64;
const Size METRIX_POISE = 65;
const Size METRIX_STOKES = 66;
const Size METRIX_STILB = 67;
const Size METRIX_PHOT = 68;
const Size METRIX_GAL = 69;
const Size METRIX_MAXWELL = 70;
const Size METRIX_GAUSS = 71;
const Size METRIX_OERSTED = 72;

const Size METRIX_STANDART_ATMOSPHERE = 73;
const Size METRIX_MAGNITUDE = 74;
const Size METRIX_SIDEREAL_DAY = 75;
const Size METRIX_FREE_FALL = 76;
const Size METRIX_MASS_OF_EARTH = 77;
const Size METRIX_RADIUS_OF_EARTH = 78;
const Size METRIX_MASS_OF_JUPITER = 79;
const Size METRIX_RADIUS_OF_JUPITER = 80;
const Size METRIX_MASS_OF_SOLAR = 81;
const Size METRIX_RADIUS_OF_SOLAR = 82;
const Size METRIX_LUMINOSITY_OF_SOLAR = 83;
const Size METRIX_PARSEC = 84;
const Size METRIX_CRAB_NEBULAS_FLUX = 85;
const Size METRIX_FOE = 86;
const Size METRIX_LIGHT_SECOND = 87;
const Size METRIX_LIGHT_MINUTE = 88;
const Size METRIX_LIGHT_HOUR = 89;
const Size METRIX_LIGHT_DAY = 90;
const Size METRIX_LIGHT_WEEK = 91;
const Size METRIX_LIGHT_YEAR = 92;
const Size METRIX_PI = 93;

const Size DIMENTION_MAX_SIZE = 8;

class IDimention : public IData {
protected:
    IDimention() {}
    virtual ~IDimention() {}

public:
    virtual IDimention* clone() const = 0;

    virtual void clear() = 0;

    virtual Size getSize() const = 0;
    virtual Size getDimentionType(Size number) const = 0;
    virtual Int getDimentionPower(Size number) const = 0;
    virtual Size getDimentionPrefix(Size number) const = 0;
    virtual bool addDimention(Size dimention, Int power,Int prefix = 0) = 0;
    virtual bool eraseDimention(Size number) = 0;
};

}

#endif // IDATADIMENTION_H
