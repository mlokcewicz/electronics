/*
 * circular_buffer.h
 *
 *  Created on: 21.01.2017
 *      Author: mlokc
 */

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stdbool.h>
#include <stdint.h>

#define BUFFER_MAX_SIZE       32
#define BUFFER_MAX_SIZE_STR   10
#define STRING_MAX_SIZE       64
#define BUFFER_ERROR          0

struct buff_ctx {
    char    buff[BUFFER_MAX_SIZE];
    uint8_t buff_front;
    uint8_t buff_end;
    uint8_t buff_size;
};

struct buff_str_ctx {
    char    buff[BUFFER_MAX_SIZE_STR][STRING_MAX_SIZE];
    uint8_t buff_front;
    uint8_t buff_end;
    uint8_t buff_size;
};

/**  @brief  Remove int element from the front of the buffer queue
 *   @param  ctx - given buffer's context
 *   @return true if removed correctly
 */
bool buffer_pop_front(struct buff_ctx* ctx);

/**  @brief  Remove string element from the front of the buffer queue
 *   @param  ctx - given buffer's context
 *   @return true if removed correctly
 */
bool buffer_pop_front_str(struct buff_str_ctx* ctx);

/**  @brief  Add element at the end of the buffer queue
 *   @param  ctx - given buffer's context
 *   @param  element - value of element
 *   @return true if added correctly
 */
bool buffer_push_back(struct buff_ctx* ctx, uint8_t element);

/**  @brief  Add string element at the end of the buffer queue
 *   @param  ctx - given buffer's context
 *   @param  element - string element
 *   @return true if added correctly
 */
bool buffer_push_back_str(struct buff_str_ctx* ctx, char* element);

/**  @brief  Get number of elements in the buffer queue
 *   @param  ctx - given buffer's context
 *   @return number of elements in the buffer queue
 */
uint16_t buffer_get_size(struct buff_ctx* ctx);

/**  @brief  Get number of string elements in the buffer queue
 *   @param  ctx - given buffer's context
 *   @return number of string elements in the buffer queue
 */
uint16_t buffer_get_size_str(struct buff_str_ctx* ctx);

/**  @brief  Get value of first element (in the front) of the buffer queue
 *   @param  ctx - given buffer's context
 *   @return value of the first element in the buffer queue
 */
uint8_t  buffer_get_first(struct buff_ctx* ctx, bool* was_empty);

/**  @brief  Get value of first string element (in the front) of the buffer queue
 *   @param  ctx - given buffer's context
 *   @return value of the first string element in the buffer queue
 */
char*  buffer_get_first_str(struct buff_str_ctx* ctx, bool* was_empty);

/**  @brief  Get value of last element (rear) in the buffer queue
 *   @param  ctx - given buffer's context
 *   @param  was_empty - output arg to store empty state
 *   @return value of the last element in the buffer queue
 */
uint8_t  buffer_get_last(struct buff_ctx* ctx, bool* was_empty);

/**  @brief  Get value of last string element (rear) in the buffer queue
 *   @param  ctx - given buffer's context
 *   @param  was_empty - output arg to store empty state
 *   @return value of the last string element in the buffer queue
 */
char* buffer_get_last_str(struct buff_str_ctx* ctx, bool* was_empty);

/**  @brief  Check if buffer queue is full
 *   @param  ctx - given buffer's context
 *   @param  was_empty - output arg to store empty state
 *   @return true if its full
 */
bool buffer_is_full(struct buff_ctx* ctx);

/**  @brief  Check if buffer queue is full
 *   @param  ctx - given buffer's context
 *   @param  was_empty - output arg to store empty state
 *   @return true if its full
 */
bool buffer_is_full_str(struct buff_str_ctx* ctx);

/**  @brief  Check if buffer queue is empty
 *   @param  ctx - given buffer's context
 *   @return true if its empty
 */
bool buffer_is_empty(struct buff_ctx* ctx);

/**  @brief  Check if buffer queue is empty
 *   @param  ctx - given buffer's context
 *   @return true if its empty
 */
bool buffer_is_empty_str(struct buff_str_ctx* ctx);

#endif /* CIRCULAR_BUFFER_H_ */
