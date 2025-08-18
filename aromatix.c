#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHAR_NOTES 50

#define MAX_FRAGRANCES 100

struct fragrance{
    char brand[50];
    char model[50];

    int year;
    int notes_counter;
    char notes[MAX_FRAGRANCES][MAX_CHAR_NOTES];

    float price;
    char season[50], perfumer[50];
    float quantity;
    char gender[50];    
};

typedef struct fragrance frag;

frag fragrance_input(){
  frag f;

  printf("Enter brand: ");
  scanf(" %[^\n]", f.brand);
  
  printf("Enter model: ");
  scanf(" %[^\n]", f.model);
  
  printf("Enter year: ");
  scanf("%d", &f.year);
  
  printf("Enter price: ");
  scanf("%f", &f.price);
  
  printf("Enter season: ");
  scanf(" %[^\n]", f.season);

  printf("Enter perfumer: ");
  scanf(" %[^\n]", f.perfumer);
  
  do{
    printf("Enter count of notes ");
    scanf("%d", &f.notes_counter);
  }while (f.notes_counter < 1 || f.notes_counter > MAX_FRAGRANCES);
  for(int i = 0; i < f.notes_counter; i++){
    printf("Enter note %d: ", i + 1);
    scanf(" %[^\n]", f.notes[i]);
  }

  printf("Enter quantity: ");
  scanf("%f", &f.quantity);

  printf("Enter gender: ");
  scanf(" %[^\n]", f.gender);

  return f;
}

void fragrance_output(frag f){
  
  printf("Brand: %s\n", f.brand);
  printf("Model: %s\n", f.model);
  printf("Year: %d\n", f.year);
  printf("Price: %.2f\n", f.price);
  printf("Season: %s\n", f.season);
  printf("Perfumer: %s\n", f.perfumer);
  
  printf("Notes: ");
  for(int i = 0; i < f.notes_counter; i++){
    printf("%s, ", f.notes[i]);
  }

  printf("\nQuantity: %.2f\n", f.quantity);
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

void fragrance_perfumers(frag *all_fragrances, int frag_number, char *perfumer_of_fragrance){
  for(int i = 0; i < frag_number; i++){
    if(strcmp(perfumer_of_fragrance, all_fragrances[i].perfumer ) == 0){
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

void capitalize_words(char *str) {
    int cap_next = 1; 
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace((unsigned char)str[i])) {
            cap_next = 1;
        } else if (cap_next && isalpha((unsigned char)str[i])) {
            str[i] = toupper((unsigned char)str[i]);
            cap_next = 0;
        } else {
            str[i] = tolower((unsigned char)str[i]);
        }
    }
}

void save_fragrances_to_file(frag arr[], int count) {
    FILE *fp = fopen("fragrances.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "%d\n", count);

    for (int i = 0; i < count; i++) {
        capitalize_words(arr[i].brand);
        capitalize_words(arr[i].model);
        capitalize_words(arr[i].season);
        capitalize_words(arr[i].gender);
        for (int j = 0; j < arr[i].notes_counter; j++) {
            capitalize_words(arr[i].notes[j]);
        }

        fprintf(fp, "%s\n", arr[i].brand);
        fprintf(fp, "%s\n", arr[i].model);
        fprintf(fp, "%d\n", arr[i].year);

        fprintf(fp, "%d\n", arr[i].notes_counter);
        for (int j = 0; j < arr[i].notes_counter; j++) {
            fprintf(fp, "%s", arr[i].notes[j]);
            if (j < arr[i].notes_counter - 1) {
                fprintf(fp, ", ");
            }
        }

        fprintf(fp, "\n%.2f\n", arr[i].price);
        fprintf(fp, "%s\n", arr[i].season);
        fprintf(fp, "%.2f\n", arr[i].quantity);
        fprintf(fp, "%s\n", arr[i].gender);
    }

    fclose(fp);
}


frag* load_fragrances_from_file(frag *arr, int *count) {    
    FILE *fp = fopen("fragrances.txt", "r");

    if (fp == NULL) {
        perror("Error opening file");
        *count = 0;
        return NULL;
    }

    if (fscanf(fp, "%d\n", count) != 1) {
        fclose(fp);
        *count = 0;
        return NULL;
    }

    
    for (int i = 0; i < *count; i++) {
        fgets(arr[i].brand, sizeof(arr[i].brand), fp);
        arr[i].brand[strcspn(arr[i].brand, "\n")] = '\0';

        fgets(arr[i].model, sizeof(arr[i].model), fp);
        arr[i].model[strcspn(arr[i].model, "\n")] = '\0';

        fscanf(fp, "%d\n", &arr[i].year);

        fscanf(fp, "%d\n", &arr[i].notes_counter);
        for (int j = 0; j < arr[i].notes_counter; j++) {
            fscanf(fp, "%99[^,\n], ", arr[i].notes[j]);
        }

        fscanf(fp, "%f\n", &arr[i].price);

        fgets(arr[i].season, sizeof(arr[i].season), fp);
        arr[i].season[strcspn(arr[i].season, "\n")] = '\0';

        fscanf(fp, "%f\n", &arr[i].quantity);

        fgets(arr[i].gender, sizeof(arr[i].gender), fp);
        arr[i].gender[strcspn(arr[i].gender, "\n")] = '\0';
    }

    fclose(fp);
    return arr;
}


int main(){
  int ch, frag_counter = 0, year;
  frag in, out, frag_structure[MAX_FRAGRANCES];
  char brand[50], perfumer[50];

  load_fragrances_from_file(frag_structure , &frag_counter);

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
      scanf(" %[^\n]", &brand);
      fragrances_by_brand(frag_structure, frag_counter, brand);

    }
    else if(ch == 5){


      printf("Type in the perfumer of the fragrance\n");
      scanf(" %[^\n]", &perfumer);
      fragrance_perfumers(frag_structure, frag_counter, perfumer);

    }
  }while(ch != 9);

  save_fragrances_to_file(frag_structure, frag_counter);

  
  return 0;
}




