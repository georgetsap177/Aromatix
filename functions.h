#ifndef FUNCTIONS_H
#define FUNCTIONS_H



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

frag fragrance_input();
void fragrance_output(frag f);
void print_all_frags(frag *all_fragrances,int frag_number);
int menu();
void fragrances_by_year(frag *all_fragrances, int frag_number, int year_of_release);
void fragrances_by_brand(frag *all_fragrances, int frag_number, char *brand_fragrance);
void fragrances_by_notes(frag *all_fragrances, int frag_number, char *notes_fragrance);
void fragrance_perfumers(frag *all_fragrances, int frag_number, char *perfumer_of_fragrance);
void sort_fragrances_desc_year(frag *all_fragrances, int frag_number );
int compareIgnoreCase(const char *s1, const char *s2);
void capitalize_words(char *str);
void save_fragrances_to_file(frag arr[], int count);
frag* load_fragrances_from_file(frag *arr, int *count);


#endif

