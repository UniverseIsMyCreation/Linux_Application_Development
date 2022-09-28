#include <ncurses.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define DX 3
#define LEN 10

int main(int argc, char ** argv){
    
    setlocale(__LC_ALL, "");
    initscr();
    WINDOW * win;
    int height_of_box = LINES-2*DX;
    
    if (argc < 2){
        initscr();
        move(LINES/2 - 1, COLS/2 - 4);
        printw("I don't get File!\n");
        getch();
        endwin();
        exit(1);
    }

    FILE * fin = fopen(argv[1],"r");
    if (fin == NULL){
        initscr();
        move(LINES/2 - 1, COLS/2 - 4);
        printw("Can't open file!\n");
        getch();
        endwin();
        exit(1);
    }

    char ** text =  (char **)malloc(sizeof(char *) * LEN);
    if (text == NULL){
        initscr();
        move(LINES/2 - 1, COLS/2 - 4);
        printw("Problem with allocation memory!\n");
        getch();
        endwin();
        fclose(fin);
        exit(1);
    }
    int read;
    char * text_line = NULL;
    size_t line_length = 0;
    size_t amount_of_lines = 0;
    size_t buf = LEN;
    while ((read = getline(&text_line,&line_length,fin)) != -1){
        amount_of_lines++;
        if (amount_of_lines > buf){
            buf += LEN;
            text = (char **)realloc(text,buf * sizeof(char*));
            if (text == NULL){
                initscr();
                move(LINES/2 - 1, COLS/2 - 4);
                printw("Problem with allocation memory!\n");
                getch();
                endwin();
                fclose(fin);
                exit(1);
            }
        }
        text_line[line_length-1] = '\0';
        text[amount_of_lines-1] = (char*)malloc(sizeof(char)*(line_length+1));
        if (text[amount_of_lines-1] == NULL){
            initscr();
            move(LINES/2 - 1, COLS/2 - 4);
            printw("Problem with allocation memory!\n");
            getch();
            endwin();
            fclose(fin);
            for (int i = 0; i < amount_of_lines-1; i++){
                free(text[i]);
            }
            free(text);
            exit(1);
        }
        strcpy(text[amount_of_lines-1],text_line);
    }
    fclose(fin);

    noecho();
    cbreak();
    printw("File: %s; Size: %ld bytes", argv[1],sizeof(text));
    refresh();

    win = newwin(LINES-2*DX, COLS-2*DX, DX, DX);
    keypad(win, TRUE);
    scrollok(win, TRUE);
    box(win, 0, 0);
    wmove(win, 1, 0);
    int symbol = 0;
    int start = 0;
    int end = amount_of_lines < height_of_box-1 ? amount_of_lines : height_of_box-1;
    int begin = 0;
    do{
        werase(win);
        for (int index = start; index < end; index++){
            if (begin < strlen(text[index])){
                mvwprintw(win, index-start, 1, "%d: %s", index,text[index] + begin);
            }
            else{
                mvwprintw(win, index-start, 1, "%d: \n", index);
            }
        }
        box(win, 0, 0);
        wmove(win, 1, 0);
        wrefresh(win);
        symbol = wgetch(win);
        if (symbol == 's' && end < amount_of_lines) {
            start++;
            end++;
        }
        else if (symbol == 'w' && start > 0){
            start--;
            end--;
        }
        else if (symbol == 'a' && begin > 0){
            begin--;
        }
        else if (symbol == 'd'){
            begin++;
        }
    } while(symbol != 27);
    endwin();
    free(text_line);
    for (int i = 0; i < amount_of_lines; i++)
        free(text[i]);
    free(text);
    return 0;
}
