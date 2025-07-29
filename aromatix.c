#include <stdio.h>

#define MAX_NOTES 100
#define MAX_CHAR_NOTES 50

struct fragrance{
    char brand[50];
    char model[50];

    int year;
    char notes[MAX_NOTES][MAX_CHAR_NOTES];

    float price;
    char season[50];
    float quantity[50];
    char gender[50];    
};


int main(){
    return 0;
}