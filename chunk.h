#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include <cstdint>

typedef enum {
  OP_RETURN,
} Opcode;

typedef struct {
  int count;
  int capacity;
  uint8_t *code;
} Chunk;

#endif
