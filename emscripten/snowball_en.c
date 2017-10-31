/* This is a simple program which uses libstemmer to provide a command
 * line interface for stemming using any of the algorithms provided.
 */

#include <stdio.h>
#include <stdlib.h> /* for malloc, free */
#include <string.h> /* for memmove */
#include <ctype.h>  /* for isupper, tolower */
#include <emscripten.h>

#include "../include/libstemmer.h"

static const char * EMSCRIPTEN_KEEPALIVE stem(char * c_in) {
  struct sb_stemmer * stemmer = sb_stemmer_new("en", NULL);
  const unsigned char * stemmed;

  size_t size_stemmed;
  size_t n = 0;
  const size_t size_char = sizeof(char);
  const size_t len = strlen(c_in);
  char * c_out = malloc(len * size_char);
  const char delimiter[2] = " ";

  /* get the first token */
  char * token = strtok(c_in, delimiter);

  /* walk through other tokens */
  while( token != NULL ) {
    stemmed = sb_stemmer_stem(stemmer, (unsigned char *) token, strlen(token));
    size_stemmed = strlen((char *) stemmed);

    if (n != 0) {
      c_out[n] = ' ';
      n += 1;
    }

    memcpy(&c_out[n], (char *) stemmed, size_stemmed);
    n += size_stemmed;

    token = strtok(NULL, delimiter);
  }
  sb_stemmer_delete(stemmer);
  c_out[n] = 0;
  return c_out;
}
