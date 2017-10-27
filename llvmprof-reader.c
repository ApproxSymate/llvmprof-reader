/* llvmprof-reader.c
 *
 * Copyright 2017 National University of Singapore
 */

#include <stdio.h>
#include <stdlib.h>

void usage();

void error_exit(const char* message);

int read_unsigned(FILE *fp, unsigned *result);

int main(int argc, char **argv) {
  FILE *fp;

  if (argc < 2) {
    usage();
    return 1;
  }
  
  fp = fopen(argv[1], "r");

  if (fp == NULL) {
    usage();
    return 1;    
  }

  int flag;

  unsigned path_info;
  flag = read_unsigned(fp, &path_info);
  if (flag)
    error_exit("Unexpected end of file when reading path info");
  printf("Path info: %08x\n", path_info);

  unsigned num_functions;
  flag = read_unsigned(fp, &num_functions);
  if (flag)
    error_exit("Unexpected end of file when reading number of functions");
  printf("Number of functions: %d\n", num_functions);

  unsigned data1, data2;
  while (1) {
    flag = read_unsigned(fp, &data1);
    if (flag)
      break;
    flag = read_unsigned(fp, &data2);
    if (flag)
      error_exit("Unexpected end of file when reading 2nd 4-byte");
    printf("data pair: %08x %08x\n", data1, data2);
  }
  
  fclose(fp);
  return 0;
}

void usage(const char *program_name) {
  fprintf(stderr, "Usage: %s <file>\n", program_name);
}

void error_exit(const char *message) {
  fprintf(stderr, "Error: %s: aborting\n", message);
  exit(1);
}

int read_unsigned(FILE *fp, unsigned *result) {
  int c;
  *result = 0;

  unsigned shamt = 0;

  for (int i = 0; i < 4; ++i) {
    c = fgetc(fp);
    
    if (c == EOF) {
      if (i == 0) {
	return -1;
      }
      error_exit("Unexpected end of file in the middle of 4-byte");
    }

    /* Assuming little endian */
    (*result) |= (c << shamt);
    shamt += 8;
  }

  return 0;
}
