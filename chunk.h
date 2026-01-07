#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "memory.h"
#include <stdint.h>

#include "value.h"

typedef enum {
  OP_RETURN,
} Opcode;

typedef struct {
  int count;
  int capacity;
  uint8_t *code;
  ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte);
// convenience method to add a new constant to the chunk.
int addConstant(Chunk *chunk, Value value);

#endif
