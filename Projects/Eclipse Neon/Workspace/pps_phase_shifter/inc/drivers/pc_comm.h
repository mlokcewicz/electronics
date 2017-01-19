/*
 * pc_comm.h
 *
 *  Created on: 07.01.2017
 *      Author: mlokc
 */

#ifndef DRIVERS_PC_COMM_H_
#define DRIVERS_PC_COMM_H_

#include <stdbool.h>
#include <stdint.h>

/** @brief Initializes pc communication module */
void       pc_comm_init(void);

/** @brief Send data */
bool       pc_comm_send_data(uint8_t *data, uint32_t size);

/** @brief Send data */
bool       pc_comm_reveive_data(uint8_t *data, uint32_t size);


#endif /* DRIVERS_PC_COMM_H_ */
