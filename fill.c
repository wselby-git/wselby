// Author: William Selby
// A rudimentary program to print or create a file containing entries with all ascii characters up to eight spaces.
// Warning this program uses a ton of resources and crease gigantic unstable files.

#include <stdio.h>

int main() {

    for (int a = 0; a < 256; a++) {
	printf("%c\n", a);
    }

    for (int a = 0; a < 256; a++) {
        for (int b = 0; b < 256; b++) {
            printf("%c%c\n", a,b);
        }
    }

    for (int a = 0; a < 256; a++) {
        for (int b = 0; b < 256; b++) {
            for (int c = 0; c < 256; c++) {
                printf("%c%c%c\n", a,b,c);
            }
        }
    }

    for (int a = 0; a < 256; a++) {
        for (int b = 0; b < 256; b++) {
            for (int c = 0; c < 256; c++) {
		for (int d = 0; d < 256; d++) {
                    printf("%c%c%c%c\n", a,b,c,d);
		}
            }
        }
    }

    for (int a = 0; a < 256; a++) {
        for (int b = 0; b < 256; b++) {
            for (int c = 0; c < 256; c++) {
                for (int d = 0; d < 256; d++) {
		    for (int e = 0; e < 256; e++) {
                        printf("%c%c%c%c%c\n", a,b,c,d,e);
		    }
                }
            }
        }
    }

    for (int a = 0; a < 256; a++) {
        for (int b = 0; b < 256; b++) {
            for (int c = 0; c < 256; c++) {
                for (int d = 0; d < 256; d++) {
                    for (int e = 0; e < 256; e++) {
			for (int f = 0; f < 256; f++) {
                            printf("%c%c%c%c%c%c\n", a,b,c,d,e,f);
			}
                    }
                }
            }
        }
    }

    for (int a = 0; a < 256; a++) {
        for (int b = 0; b < 256; b++) {
            for (int c = 0; c < 256; c++) {
                for (int d = 0; d < 256; d++) {
                    for (int e = 0; e < 256; e++) {
                        for (int f = 0; f < 256; f++) {
			    for (int g = 0; g < 256; g++) {
                                printf("%c%c%c%c%c%c%c\n", a,b,c,d,e,f,g);
			    }
                        }
                    }
                }
            }
        }
    }

    for (int a = 0; a < 256; a++) {
        for (int b = 0; b < 256; b++) {
            for (int c = 0; c < 256; c++) {
                for (int d = 0; d < 256; d++) {
                    for (int e = 0; e < 256; e++) {
                        for (int f = 0; f < 256; f++) {
                            for (int g = 0; g < 256; g++) {
				for (int h = 0; < 256; h++) {
                                    printf("%c%c%c%c%c%c%c5c\n", a,b,c,d,e,f,g,h);
				}
                            }
                        }
                    }
                }
            }
        }
    }
      
    return 0;
}
