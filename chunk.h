#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include <cstddef>
#include <cstdint>

typedef enum {
  OP_RETURN,
} Opcode;

typedef struct {
  int count;
  int capacity;
  uint8_t *code;
} Chunk;

void initChunk(Chunk *chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
}

void writeChunk(Chunk *chunk, uint8_t byte) {
  if (chunk->capacity < chunk->count + 1) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->code =
        GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
  }
}
#endif
