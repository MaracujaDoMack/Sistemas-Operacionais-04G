#include <stdio.h>
#include <stdbool.h>

#define TRAVEL_TIME 10

int main()
{

    int n;
    scanf("%d", &n);

    if(n < 0) return 0;

    struct Escalator{
        int t, d;
        bool hasBeenCounted;
    } e[n];

    int i;
    for(i = 0; i < n; i++){
        scanf("%d%d",&e[i].t, & e[i].d);
        e[i].hasBeenCounted = false;
    }

    int acm = e[0].t, total = 0, nextIndex = 0;
    bool hasFoundNextIndex = 0;

    int j;
    for(i = nextIndex; i < n; i++){
        if(e[i].hasBeenCounted == true) break;
        acm += TRAVEL_TIME;
        e[i].hasBeenCounted = true;
        for(j = i+1; j < n; j++){
            if(e[j].d != e[i].d && !hasFoundNextIndex){
                nextIndex = j;
                hasFoundNextIndex = true;
            }
            else if(e[j].t <= acm && e[j].d == e[i].d && !e[j].hasBeenCounted){
                acm = e[j].t + TRAVEL_TIME;
                e[j].hasBeenCounted = true;
            }
        }
        total+=acm;
        if(!hasFoundNextIndex) break;
        acm = 0;
        hasFoundNextIndex = false;
    }

    printf("\nTempo gasto: %d segundos\n", total);

}
