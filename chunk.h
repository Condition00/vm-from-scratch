#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "memory.h"
#include <stdint.h>

#include "value.h"

typedef enum {
  OP_RETURN,
  OP_NEGATE,
  OP_ADD,
  OP_SUBTRACT,
  OP_MULTIPLY,
  OP_DIVIDE,
  OP_CONSTANT,
} Opcode;

typedef struct {
  int count;
  int capacity;
  uint8_t *code;
  int *lines;
  ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte,
                int line); // also mentioned whihch line it came from
// convenience method to add a new constant to the chunk.
int addConstant(Chunk *chunk, Value value);

#endif
