#include <stdio.h>
#include <string.h>


#define MAX_CHAR_NOTES 50

#define MAX_FRAGRANCES 2

struct fragrance{
    char brand[50];
    char model[50];

    int year;
    int notes_counter;
    char notes[MAX_FRAGRANCES][MAX_CHAR_NOTES];

    float price;
    char season[50];
    float quantity;
    char gender[50];    
};

typedef struct fragrance frag;

frag fragrance_input(){
  frag f;

  printf("Enter brand: ");
  scanf("%s", f.brand);
  
  printf("Enter model: ");
  scanf("%s", f.model);
  
  printf("Enter year: ");
  scanf("%d", &f.year);
  
  printf("Enter price: ");
  scanf("%f", &f.price);
  
  printf("Enter season: ");
  scanf("%s", f.season);
  
  do{
    printf("Enter count of notes ");
    scanf("%d", &f.notes_counter);
  }while (f.notes_counter < 1 || f.notes_counter > MAX_FRAGRANCES);
  for(int i = 0; i < f.notes_counter; i++){
    printf("Enter note %d: ", i + 1);
    scanf("%s", f.notes[i]);
  }

  printf("Enter quantity: ");
  scanf("%f", &f.quantity);

  printf("Enter gender: ");
  scanf("%s", f.gender);

  return f;
}

void fragrance_output(frag f){
  
  printf("Brand: %s\n", f.brand);
  printf("Model: %s\n", f.model);
  printf("Year: %d\n", f.year);
  printf("Price: %.2f\n", f.price);
  printf("Season: %s\n", f.season);
  
  printf("Notes:\n");
  for(int i = 0; i < f.notes_counter; i++){
    printf("%s\n", f.notes[i]);
  }

  printf("Quantity: %2f\n", f.quantity);
  printf("Gender: %s\n\n", f.gender);
}


int menu(){
  int choice;
  do{ 
    printf("Welcome to the Aromatix Fragrance Management System\n");
    printf("1. Add a new fragrance\n");
    printf("2. Edit a fragrance\n");
    printf("3. Search a fragrance by brand\n");
    printf("4. Search by notes\n");
    printf("5. Search perfumers\n");
    printf("6. Search fragrances from a specific year\n");    
    printf("7. Display all fragrances\n");
    printf("8. Sort fragrances by year descending\n");
    printf("9. Exit\n");


    printf("Give your choice: ");
    scanf("%d", &choice);
  }while (choice < 1 || choice > 9);

  return choice;
}

;
void print_all_frags(frag *all_fragrances,int frag_number){
  for (int i = 0; i < frag_number; i++){       
    fragrance_output( all_fragrances[i] );
  }
  
}

void fragrances_by_year(frag *all_fragrances, int frag_number, int year_of_release){
  for(int i = 0; i < frag_number; i++){
    if(year_of_release == all_fragrances[i].year ){
      fragrance_output( all_fragrances[i] );
    }
  }

}

void fragrances_by_brand(frag *all_fragrances, int frag_number, char *brand_fragrance){
  for(int i = 0; i < frag_number; i++){
    if(strcmp(brand_fragrance, all_fragrances[i].brand ) == 0){
      fragrance_output( all_fragrances[i] );
    }
  }
}

void sort_fragrances_desc_year(frag *all_fragrances, int frag_number ){
  frag temp1;
  int i, j;
  for(i = 1; i <= frag_number-1; i++){
    for(j = frag_number-1; j >= i; j-- ){
      if(all_fragrances[j].year > all_fragrances[j-1].year ){
        temp1 = all_fragrances[j];
        all_fragrances[j] = all_fragrances[j-1];
        all_fragrances[j-1] = temp1; 
      }
    
    }  
  }
}  



int main(){
  int ch, frag_counter = 0, year;
  frag in, out, frag_structure[MAX_FRAGRANCES];
  char brand[50];

  for (int i = 0; i < frag_counter; i++){        
    fragrance_output( frag_structure[i] );
  }
  do{
    
  
    ch = menu();
    if(ch == 1){
      if( frag_counter < MAX_FRAGRANCES ){
        in = fragrance_input();
        frag_structure[frag_counter] = in;
        frag_counter++;
      }
      else{
        printf("You have reached the maximum limit of fragrances\n");
      }
      
        
    }
    else if(ch == 7){

      print_all_frags(frag_structure, frag_counter );

    }
    else if(ch == 6){
      printf("Type in the year of release\n");
      scanf("%d", &year);

      fragrances_by_year(frag_structure, frag_counter, year);
    }
    else if(ch == 8){
      
      sort_fragrances_desc_year(frag_structure, frag_counter);
    }
    else if(ch == 3){
    
      printf("Type in the brand of fragrance\n");
      scanf("%s", &brand);
      fragrances_by_brand(frag_structure, frag_counter, brand);

    }
  }while(ch != 9);
  
  return 0;
}


