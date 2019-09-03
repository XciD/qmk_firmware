/*
Copyright 2018 Massdrop Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ctrl.h"
#include "led_matrix.h"

//Teal <-> Salmon
led_setup_t leds_teal_salmon[] = {
    { .hs = 0,  .he = 33,  .rs = 24,  .re = 24,  .gs = 215, .ge = 215, .bs = 204, .be = 204, .ef = EF_NONE },
    { .hs = 33, .he = 66,  .rs = 24,  .re = 255, .gs = 215, .ge = 114, .bs = 204, .be = 118, .ef = EF_NONE },
    { .hs = 66, .he = 100, .rs = 255, .re = 255, .gs = 114, .ge = 114, .bs = 118, .be = 118, .ef = EF_NONE },
    { .end = 1 },
};

//Yellow
led_setup_t leds_yellow[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

//Off
led_setup_t leds_off[] = {
    { .hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

//Red
led_setup_t leds_red[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

//Green
led_setup_t leds_green[] = {
    { .hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 255, .ge = 255, .bs = 0, .be = 0, .ef = EF_NONE },
    { .end = 1 },
};

//Blue
led_setup_t leds_blue[] = {
    { .hs = 0, .he = 100, .rs = 0, .re = 0, .gs = 0, .ge = 0, .bs = 255, .be = 255, .ef = EF_NONE },
    { .end = 1 },
};

//White
led_setup_t leds_white[] = {
    { .hs = 0, .he = 100, .rs = 255, .re = 255, .gs = 255, .ge = 255, .bs = 255, .be = 255, .ef = EF_NONE },
    { .end = 1 },
};

//White with moving red stripe
led_setup_t leds_white_with_red_stripe[] = {
    { .hs = 0, .he = 15, .rs = 0, .re = 255, .gs = 0, .ge = 255, .bs = 0, .be = 0, .ef = EF_SCR_R | EF_SUBTRACT },
    { .hs = 15, .he = 30, .rs = 255, .re = 0, .gs = 255, .ge = 0, .bs = 0, .be = 0, .ef = EF_SCR_R | EF_SUBTRACT},
    { .end = 1 },
};

//Black with moving red stripe
led_setup_t leds_black_with_red_stripe[] = {
    { .hs = 0, .he = 15, .rs = 0, .re = 255, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_SCR_R },
    { .hs = 15, .he = 30, .rs = 255, .re = 0, .gs = 0, .ge = 0, .bs = 0, .be = 0, .ef = EF_SCR_R },
    { .end = 1 },
};

//Rainbow no scrolling
led_setup_t leds_rainbow_ns[] = {
    { .hs = 0,      .he = 16.67,  .rs = 255, .re = 255, .gs = 0,   .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER },
    { .hs = 16.67,  .he = 33.33,  .rs = 255, .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER },
    { .hs = 33.33,  .he = 50,     .rs = 0,   .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 255, .ef = EF_OVER },
    { .hs = 50,     .he = 66.67,  .rs = 0,   .re = 0,   .gs = 255, .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER },
    { .hs = 66.67,  .he = 83.33,  .rs = 0,   .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER },
    { .hs = 83.33,  .he = 100,    .rs = 255, .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 0,   .ef = EF_OVER },
    { .end = 1 },
};

//Rainbow scrolling
led_setup_t leds_rainbow_s[] = {
    { .hs = 0,      .he = 16.67,  .rs = 255, .re = 255, .gs = 0,   .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 16.67,  .he = 33.33,  .rs = 255, .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .hs = 33.33,  .he = 50,     .rs = 0,   .re = 0,   .gs = 255, .ge = 255, .bs = 0,   .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 50,     .he = 66.67,  .rs = 0,   .re = 0,   .gs = 255, .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 66.67,  .he = 83.33,  .rs = 0,   .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 255, .ef = EF_OVER | EF_SCR_R },
    { .hs = 83.33,  .he = 100,    .rs = 255, .re = 255, .gs = 0,   .ge = 0,   .bs = 255, .be = 0,   .ef = EF_OVER | EF_SCR_R },
    { .end = 1 },
};

//Add new LED animations here using one from above as example
//The last entry must be { .end = 1 }
//Add the new animation name to the list below following its format

void *led_setups[] = {
    leds_white_with_red_stripe,
    leds_rainbow_s,
    leds_rainbow_ns,
    leds_teal_salmon,
    leds_yellow,
    leds_red,
    leds_green,
    leds_blue,
    leds_white,
    leds_black_with_red_stripe,
    leds_off
};

#define GOLD    {.r = 255,  .g = 215,   .b = 0    }
#define BLUE    {.r = 0,    .g = 206,   .b = 209  }
#define BLACK   {.r = 0,    .g = 0,     .b = 0    }
#define WHITE   {.r = 255,  .g = 255,   .b = 255  }
#define RED     {.r = 255,  .g = 0,     .b = 0    }
#define GREEN   {.r = 0,    .g = 255,   .b = 0    }

specific_led_t layer_0[] = {
  {.start = 1, .end = 87, .color = WHITE}, // All keys

  {.start = 1, .end = 1, .color = GOLD},

  // F1
  {.start = 2, .end = 13, .color = BLUE},

  // RED
  {.start = 17, .end = 17, .color = RED}, // ``
  {.start = 30, .end = 30, .color = RED}, // back space
  {.start = 34, .end = 34, .color = RED}, // Tab
  {.start = 47, .end = 47, .color = RED}, // backslash
  {.start = 51, .end = 51, .color = RED}, // CAP LOCK
  {.start = 63, .end = 63, .color = RED}, // Enter
  {.start = 64, .end = 64, .color = RED}, // Shift
  {.start = 75, .end = 75, .color = RED}, // Shift
  {.start = 77, .end = 84, .color = RED}, // Lower line


  {.start = 85, .end = 87, .color = GOLD}, // Arrows
  {.start = 76, .end = 76, .color = GOLD}, // Arrows
  {.start = 18, .end = 29, .color = WHITE}, // Arrows


  {.start = 18, .end = 29, .color = WHITE}, // Arrows

  {.start = 14, .end = 16, .color = GREEN},  // PRINT PAUSE
  {.start = 31, .end = 33, .color = GREEN},  // PRINT PAUSE
  {.start = 48, .end = 50, .color = GREEN},  // INS PUP

  //{.start = 88, .end = 119, .color = WHITE}, // Arrows

  {.stop = 1 }
};

specific_led_t layer_1[] = {
  {.start = 19, .end = 19, .color = WHITE},
  {.start = 24, .end = 24, .color = WHITE},
  {.start = 27, .end = 27, .color = WHITE},
  {.start = 88, .end = 119, .color = WHITE}, // Arrows
  {.stop = 1}
};

void *led_specific_colors[] = {
  layer_0,
  layer_1
};

const uint8_t led_setups_count = sizeof(led_setups) / sizeof(led_setups[0]);
