#include <stdio.h>


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
  printf("Gender: %s\n", f.gender);
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
    printf("6. Search award winning fragrances\n");
    printf("7. Display all fragrances\n");
    printf("8. Display fragrances by year\n");
    printf("9. Exit\n");


    printf("Give your choice: ");
    scanf("%d", &choice);
  }while (choice < 1 || choice > 9);

  return choice;
}


void print_all_frags(frag *all_fragrances,int frag_number){
  for (int i = 0; i < frag_number; i++){       
    fragrance_output( all_fragrances[i] );
  }
  
}


int main(){
  int ch, frag_counter = 0;
  frag in, out, frag_structure[MAX_FRAGRANCES], disp;
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
    if(ch == 7){

      print_all_frags(frag_structure, frag_counter );

    }
  }while(ch != 9);
  
  return 0;
}