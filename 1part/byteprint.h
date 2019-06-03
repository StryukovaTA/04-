#pragma once
#include <iostream>
#include <cassert>

char nibble_to_hex(uint8_t i);
char bit_digit(uint8_t byte, uint8_t bit);
void print_in_hex(uint8_t byte);
void print_in_hex(const void* data, size_t datasize);
void print_in_binary(uint8_t byte);
void print_in_binary(const void* data, size_t datasize);
void byte_calc( uint16_t first, uint16_t second, char oper );
