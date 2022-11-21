#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <libintl.h>
#include <locale.h>
#include <string.h>
#include "config.h"

#define _(STRING) gettext(STRING)
#define LOCALE_PATH "po"
#define LEN 100

int main(int argc, char **argv){

    setlocale(LC_ALL, "");
    bindtextdomain(PACKAGE, LOCALE_PATH);
    textdomain(PACKAGE);

    printf(_("Please, enter any number from 1 to 100 included\n"));
    int pred_number = 0;
    int res;
    res = scanf("%d", &pred_number);
    int low_bound = 1;
    int up_bound = 100;
    int mid_bound = (low_bound+up_bound)/2;
    char *yes = _("yes");
    char *not = _("not");
    char *nothing = _("nothing");
    char user_ans[LEN];
    while (low_bound < up_bound){
        printf(_("Can I ask if your number greater than %d (write yes or not or nothing)?\n"), mid_bound);
        res = scanf("%s", user_ans);
        if (!strcmp(user_ans, not)){
            up_bound = mid_bound;
            mid_bound = (low_bound+up_bound)/2;
        }
        else if (!strcmp(user_ans, yes)){
            low_bound = mid_bound+1;
            mid_bound = (low_bound+up_bound)/2;
        }
        else if (!strcmp(user_ans, nothing)){
            up_bound = mid_bound;
            break;
        }
        else{
            printf(_("Error input, try again\n"));
            continue;
        }
    }
    printf(_("Your desired number was: %d\n"), up_bound);

    return 0;

}
