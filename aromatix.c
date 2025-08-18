#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "functions.h"


int main(){
  int ch, frag_counter = 0, year;
  frag in, out, frag_structure[MAX_FRAGRANCES];
  char brand[50], perfumer[50], notes[50];

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


      printf("Type in the perfumer of the fragrance: ");
      scanf(" %[^\n]", &perfumer);
      fragrance_perfumers(frag_structure, frag_counter, perfumer);

    }
    else if(ch == 4){
      
      
      printf("Type in the note of the fragrance: ");
      scanf(" %[^\n]", &notes);
      fragrances_by_notes(frag_structure, frag_counter, notes);


    }
  }while(ch != 9);

  save_fragrances_to_file(frag_structure, frag_counter);

  
  return 0;
}




