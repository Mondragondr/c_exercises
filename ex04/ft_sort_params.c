#include <unistd.h>
#include <stdlib.h>

// #define DEBUG //////////////////////////////////////// DEBUG INFO
#ifdef DEBUG ///////////////////////////////////////// DEBUG INFO
#include <stdio.h> /////////////////////////////////// DEBUG INFO
#endif /////////////////////////////////////////////// DEBUG INFO

#define WORD2 (plus_one(word1))
#define WORD1 (word1)
#define WRITE_CHAR(A) printf("%c %d\n", A, A)
#define WRITE_STRING(A) printf("%s\n", A)

void ft_putchar(char c);

int plus_one (int i){
    i += 1;
    return i;
}

char** ft_sort_params(int argc, char* argv[]){
    int word1; //WORD2 = WORD1 + 1
    int position_of_char;
    int long1;
    int long2;
    int tmp_int;
    char* str_tmp;

    int transport = 0;
    char stop;

    for(int loops = 0; loops < ((argc*argc) / 2); loops++)
    {
        for(word1 = 1; WORD2 < argc; word1++) //WORD2 = WORD1 + 1
        {
#ifdef DEBUG ///////////////////////////////////////// DEBUG INFO
WRITE_STRING(argv[WORD1]); /////////////////////////// DEBUG INFO
#endif /////////////////////////////////////////////// DEBUG INFO
            for(long1 = 0; argv[WORD1][long1] != 0; long1++); //LONG WORD1
            for(long2 = 0; argv[WORD2][long2] != 0; long2++); //LONG WORD2
            stop = 0;
            for(position_of_char = 0; (argv[WORD1][position_of_char] != 0 || argv[WORD2][position_of_char] != 0) && (stop == 0); position_of_char++)
            {
#ifdef DEBUG ///////////////////////////////////////// DEBUG INFO
WRITE_CHAR(argv[WORD1][position_of_char]); /////////// DEBUG INFO
WRITE_CHAR(argv[WORD2][position_of_char]); /////////// DEBUG INFO
printf("position_of_char = %d\n",position_of_char); // DEBUG INFO
#endif /////////////////////////////////////////////// DEBUG INFO
                if(argv[WORD1][position_of_char] == 0 || argv[WORD2][position_of_char] == 0) stop = 1;
                if(argv[WORD1][position_of_char] < argv[WORD2][position_of_char]) stop = 1;
                else if((argv[WORD1][position_of_char] > argv[WORD2][position_of_char]))
                {
                    str_tmp = (char*)malloc(long1);
                    for(tmp_int = 0; tmp_int < long1; tmp_int++) str_tmp[tmp_int] = argv[WORD1][tmp_int]; // WORD1 >> TMP
                    argv[WORD1] = (char*)free;
                    argv[WORD1] = (char*)malloc(long2);
                    for(tmp_int = 0; tmp_int < long2; tmp_int++) argv[WORD1][tmp_int] = argv[WORD2][tmp_int]; // WORD2 >> WORD1
                    argv[WORD1][long2] = 0;
                    argv[WORD2] = (char*)free;
                    argv[WORD2] = (char*)malloc(long1);
                    for(tmp_int = 0; tmp_int < long1; tmp_int++) argv[WORD2][tmp_int] = str_tmp[tmp_int]; // TMP >> WORD2
                    argv[WORD2][long1] = 0;
                    str_tmp = (char*)free;
                    transport += 1;
                    stop = 1;
#ifdef DEBUG ///////////////////////////////////////// DEBUG INFO
printf("DONE\n"); //////////////////////////////////// DEBUG INFO
// printf("stop = %d\n",stop); /////////////////////// DEBUG INFO
#endif /////////////////////////////////////////////// DEBUG INFO
                }
            }
        }
    }
#ifdef DEBUG ///////////////////////////////////////// DEBUG INFO
printf("transport %d\n",transport); ////////////////// DEBUG INFO
#endif /////////////////////////////////////////////// DEBUG INFO

return argv;
}