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

int menu(){
  int e;
  do{ 
    printf("Welcome to the Aromatix Fragrance Management System\n");
    printf("1. Add a new fragrance\n");
    printf("2. Edit a fragrance\n");
    printf("3. Search a fragrance by brand\n");
    printf("4. Search by notes\n");
    printf("5. Search perfumers\n");
    printf("6. Search award winning fragrances\n");
    printf("7. Display all fragrances\n");
    printf("8. Display fragrances by year\n");


    printf("Dvse thn epilogh:");
    scanf("%d", &e);
  }while (e < 1 || e > 8);

  return e;
}    


int main(){
  int ep;
  
  ep = menu();
  return 0;
}

