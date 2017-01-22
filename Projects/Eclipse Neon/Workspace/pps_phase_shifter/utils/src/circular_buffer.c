/*
 *  circular_buffer.c
 *
 *  Created on: 21.01.2017
 *      Author: mlokc
 */


#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "../inc/circular_buffer.h"

bool buffer_pop_front(struct buff_ctx* ctx){
    if(buffer_is_empty(ctx)){
        return false;
    }
    ctx->buff_front++;
    ctx->buff_front %= BUFFER_MAX_SIZE;
    ctx->buff_size--;
    return true;
}

bool buffer_pop_front_str(struct buff_str_ctx* ctx){
    if(buffer_is_empty_str(ctx)){
        return false;
    }
    ctx->buff_front++;
    ctx->buff_front %= BUFFER_MAX_SIZE_STR;
    ctx->buff_size--;
    return true;
}

bool buffer_push_back(struct buff_ctx* ctx, uint8_t element){
    if(buffer_is_full(ctx)){
        return false;
    }
    ctx->buff[ctx->buff_end] = element;
    ctx->buff_end++;
    ctx->buff_end %= BUFFER_MAX_SIZE;
    ctx->buff_size++;
    return true;
}

bool buffer_push_back_str(struct buff_str_ctx* ctx, char* element){
    if(buffer_is_full_str(ctx)){
        return false;
    }
    uint16_t len = strlen(element);
    if (len > STRING_MAX_SIZE){
        len = STRING_MAX_SIZE;
    }
    memcpy(ctx->buff[ctx->buff_end], element, len);
    memset(ctx->buff[ctx->buff_end] + STRING_MAX_SIZE - 1, 0x00, 1);
    ctx->buff_end++;
    ctx->buff_end %= BUFFER_MAX_SIZE_STR;
    ctx->buff_size++;
    return true;
}

uint16_t buffer_get_size(struct buff_ctx* ctx){
    return ctx->buff_size;
}

uint16_t buffer_get_size_str(struct buff_str_ctx* ctx){
    return ctx->buff_size;
}

uint8_t buffer_get_first(struct buff_ctx* ctx, bool* was_empty){
    *was_empty = false;
    if(buffer_is_empty(ctx)){
        *was_empty = true;
        return BUFFER_ERROR;
    }
    return ctx->buff[ctx->buff_front];
}

char* buffer_get_first_str(struct buff_str_ctx* ctx, bool* was_empty){
    *was_empty = false;
    if(buffer_is_empty_str(ctx)){
        *was_empty = true;
        return BUFFER_ERROR;
    }
    return ctx->buff[ctx->buff_front];
}

uint8_t buffer_get_last(struct buff_ctx* ctx, bool* was_empty){
    *was_empty = false;
    if(buffer_is_empty(ctx)){
        *was_empty = true;
        return BUFFER_ERROR;
    }
    return ctx->buff[ctx->buff_end - 1];
}

char* buffer_get_last_str(struct buff_str_ctx* ctx, bool* was_empty){
    *was_empty = false;
    if(buffer_is_empty_str(ctx)){
        *was_empty = true;
        return BUFFER_ERROR;
    }
    return ctx->buff[ctx->buff_end - 1];
}

bool buffer_is_full(struct buff_ctx* ctx){
    return buffer_get_size(ctx) == BUFFER_MAX_SIZE;
}

bool buffer_is_full_str(struct buff_str_ctx* ctx){
    return buffer_get_size_str(ctx) == BUFFER_MAX_SIZE_STR;
}

bool buffer_is_empty(struct buff_ctx* ctx){
    return buffer_get_size(ctx) == 0;
}

bool buffer_is_empty_str(struct buff_str_ctx* ctx){
    return buffer_get_size_str(ctx) == 0;
}
