/*
 * Copyright 2017 National University of Singapore
 */

#include <stdio.h>

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Exactly one command-line argument expected\n");
    return 1;
  }

  unsigned char c = argv[1][0];

  if (c < 128) {
    if (c < 64) {
      if (c < 32) {
	if (c < 16) {
	  printf("path1\n");
	} else {
	  printf("path2\n");
	}
      } else {
	if (c < 48) {
	  printf("path3\n");
	} else {
	  printf("path4\n");
	}
      }
    } else {
      if (c < 96) {
	if (c < 80) {
	  printf("path 5\n");
	} else {
	  printf("path 6\n");
	}
      } else {
	if (c < 112) {
	  printf("path 7\n");
	} else {
	  printf("path 8\n");
	}	
      }
    }
  } else {
    if (c < 192) {
      if (c < 160) {
	if (c < 144) {
	  printf("path 9\n");
	} else {
	  printf("path 10\n");
	}
      } else {
	if (c < 176) {
	  printf("path 11\n");
	} else {
	  printf("path 12\n");
	}
      }
    } else {
      if (c < 224) {
	if (c < 208) {
	  printf("path 13\n");
	} else {
	  printf("path 14\n");
	}
      } else {
	if (c < 240) {
	  printf("path 15\n");
	} else {
	  printf("path 16\n");
	}	
      }
    }
  }
  
  return 0;
}
