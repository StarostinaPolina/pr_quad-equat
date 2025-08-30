#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 

#define MY_ASSERT(E) \
if (! (E)) {\
printf("Error: in file  %s  line %d", __FILE__, __LINE__);\
exit(EXIT_FAILURE);}

#include "color.h"
#include "mode_solver.h"
#include "mode_tester.h"


int main(const int argc, const char* argv[]) {
  
   if (! (argc == 3) || (argc == 2)) {
      printf("Command must be like this: \"file.exe  mode  file_test.txt (for tester mode)\"");
      return 1;
   } 

   //MY_ASSERT((argc == 3) || (argc == 2)); //TODO: убрать ассерт, нужна обработка ввода пользоватлея

    int ret = 5;

      enum Modes mode = cmd_select_mode(argv[1]);

      switch (mode) {

        case SOLVER:
           printf("\n" YELLOW "Solver mode selected:\n\n");
           ret = mode_solver();
           break;

        case TESTER:
           printf("\n" BLUE "Tester mode selected:\n\n");
           ret = mode_tester(argv[2]);
           break;

        case MAIN_QUIT:
           printf("\n" PURPLE "Final");
           ret = 0;
           break;

        case INC_INPUT:
           printf("\n" ORANGE "Incorrect mode. Try again");
           break;

       }
    
    printf("\n\n" RED "COMMIT GITHUB" WHITE "\n\n");

    return ret;
}
