/*
 * Copyright 2017 National University of Singapore
 */

#include <stdio.h>

int generate_paths(unsigned char c);

int main(int argc, char **argv) {
  generate_paths('a');
  generate_paths('A');
  generate_paths('x');
  generate_paths('d');
  generate_paths('0');
  generate_paths('G');
  generate_paths('a');
  generate_paths('z');
  generate_paths('i');
  generate_paths('9');
}

int generate_paths(unsigned char c) {
  if (c < 128) {
    if (c < 64) {
      if (c < 32) {
	if (c < 16) {
	  printf("path 1\n");
	} else {
	  printf("path 2\n");
	}
      } else {
	if (c < 48) {
	  printf("path 3\n");
	} else {
	  printf("path 4\n");
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
