#ifndef _arcada_extensions_h
#define _arcada_extensions_h
#include <Adafruit_Arcada.h>

//#include "game_lib_sprites.h"
//#include "game_lib_layers.h"

void blitToFrame(uint16_t * framebuffer, uint16_t * img, uint16_t img_width, uint16_t img_height, uint16_t x_pos, uint16_t y_pos) {
    for (int y = 0; y < img_height; y++) {
        for (int x = 0; x < img_width; x++) {
            *((framebuffer+((y+y_pos)*ARCADA_TFT_WIDTH)) + x+x_pos) = *((img+(y*img_width)) + x);
        }
    }
}

void blitToFrame(uint16_t * framebuffer, const uint16_t * img, uint16_t img_width, uint16_t img_height, uint16_t x_pos, uint16_t y_pos) {
    for (int y = 0; y < img_height; y++) {
        for (int x = 0; x < img_width; x++) {
            *((framebuffer+((y+y_pos)*ARCADA_TFT_WIDTH)) + x+x_pos) = *((img+(y*img_width)) + x);
        }
    }
}

void blitToFrameWithMask (uint16_t * framebuffer, uint16_t * img, bool * mask, uint16_t img_width, uint16_t img_height, uint16_t x_pos, uint16_t y_pos) {
    for (int y = 0; y < img_height; y++) {
        for (int x = 0; x < img_width; x++) {
            if (*((mask+(y*img_width)) + x)) {
                *((framebuffer+((y+y_pos)*ARCADA_TFT_WIDTH)) + x+x_pos) = *((img+(y*img_width)) + x);
            }
        }
    }
}

void blitToFrameWithMask (uint16_t * framebuffer, const uint16_t * img, const bool * mask, uint16_t img_width, uint16_t img_height, uint16_t x_pos, uint16_t y_pos) {
    for (int y = 0; y < img_height; y++) {
        for (int x = 0; x < img_width; x++) {
            if (*((mask+(y*img_width)) + x)) {
                *((framebuffer+((y+y_pos)*ARCADA_TFT_WIDTH)) + x+x_pos) = *((img+(y*img_width)) + x);
            }
        }
    }
}

void clearFrameBuffer(uint16_t * framebuffer) {
    for (int i = 0; i < (ARCADA_TFT_WIDTH * ARCADA_TFT_HEIGHT); i++) {
        *(framebuffer + i) = 0;
    }
}

#endif