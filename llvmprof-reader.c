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

  while (1) {
    unsigned dummy;

    if (read_unsigned(fp, &dummy) || read_unsigned(fp, &dummy) ||
        read_unsigned(fp, &dummy) || read_unsigned(fp, &dummy) ||
        read_unsigned(fp, &dummy))
      break;

    unsigned profile_type;
    flag = read_unsigned(fp, &profile_type);
    if (flag)
      error_exit("Unexpected end of file when reading profile type");

    if (profile_type != 5)
      error_exit("Unknown file format");

    unsigned num_functions;
    flag = read_unsigned(fp, &num_functions);
    if (flag)
      error_exit("Unexpected end of file when reading number of functions");

    printf("\nPath profile with %d function(s)\n", num_functions);

    for (unsigned i = 0; i < num_functions; ++i) {
      unsigned function_no, entries_num;

      flag = read_unsigned(fp, &function_no);
      if (flag)
        error_exit("Unexpected end of file when reading function number");

      flag = read_unsigned(fp, &entries_num);
      if (flag)
        error_exit("Unexpected end of file when reading number of entries");

      printf("Function no. (entries): %d (%d)\n", function_no, entries_num);

      for (unsigned j = 0; j < entries_num; ++j) {
        unsigned pathNumber, pathCounter;
        flag = read_unsigned(fp, &pathNumber);
        if (flag)
          error_exit("Unexpected end of file when reading path number");

        flag = read_unsigned(fp, &pathCounter);
        if (flag)
          error_exit("Unexpected end of file when reading path counter");

        printf("Path number (count): %d (%d)\n", pathNumber, pathCounter);
      }
    }
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
