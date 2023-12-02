#include "zlib.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *text = "How does a penguin build its house? Igloos it together!";
  int text_length = strlen(text) + 1; // +1 for the null terminator

  // Allocate memory for the compressed data.
  // The buffer size should be at least 0.1% larger than the original size plus
  // 12 bytes.
  uLong compressed_length = compressBound(text_length);
  char *compressed_text = (char *)malloc(compressed_length);

  // Compress the text.
  int result = compress((Bytef *)compressed_text, &compressed_length,
                        (Bytef *)text, text_length);
  if (result != Z_OK) {
    printf("Compression failed!\n");
    free(compressed_text);
    return 1;
  }

  printf("Original text: %s\n", text);
  printf("Original size: %d\n", text_length);
  printf("Compressed size: %ld\n", compressed_length);

  // Don't forget to free the allocated memory for the compressed text.
  free(compressed_text);

  return 0;
}
