#include <stdio.h>

//Franciszek Przeliorz
//Zad1 - Lista4 "Algorytm konwertujący datę z zapisu bin do formatu dzien_tyg/dzien_mies/miesiac/chiński_ rok"

typedef struct 
{
    int dzien_t;
    int dzien_m;
    int miesiac;
    int rok;

}TypDaty;

long BitShift(long x, int shift){
    
    if(shift > 0){
        for(int i = 0; i < shift; i++){
            x = x * 10;
        }

    }else if(shift < 0){
        shift = -shift;
        for(int i = 0; i < shift; i++){
            x = x / 10;
        }
    }
    return x;
}
int converter(long x){
    
    long decimal = 0, power = 1, rem;

    while (x!=0) {
        rem = x % 10;
        x /= 10;
        decimal += rem * power;
        power *= 2;
    }

  return decimal;
}

int testData(int dzien_t, int dzien_m, int miesiac, int rok){

        if(!(dzien_t >= 1 && dzien_t <= 7))  return 1;
        if(!(dzien_m >= 1 && dzien_m <= 31)) return 1;
        if(!(miesiac >= 1 && miesiac <= 12)) return 1;
        if(!(rok>= 1 && rok <= 12)) return 1;
        
        return 0;
}

void wypiszData(int dzien_t, int dzien_m, int miesiac, int rok){
    char *DniTyg[7] = {"pon", "wto", "sro", "czw", "pia", "sob", "nie"};
    char *Miesiace[12] = {"sty", "lut", "mar", "kwi", "maj", "cze", "lip", "sie", "wrz", "paz", "lis", "gru"};
    char *Lata[12] = {"malpy", "koguta", "swini", "szczura", "tygrysa", "krolika", "smoka", "weza", "konia", "owcy", "kozy", "psa"};

    printf("%s, %d %s, rok %s(%d)\n", DniTyg[dzien_t - 1], dzien_m, Miesiace[miesiac - 1], Lata[rok - 1], rok);
}

int main(){
    
    long input, pom;
    TypDaty data;

    while((scanf("%ld", &input)) != EOF && input != 0){

        pom = BitShift(input, -13);
        data.dzien_t = pom;

    
        input = input - BitShift(pom, 13);
        pom = BitShift(input, -8);
        data.dzien_m = pom;

        input = input - BitShift(pom, 8);
        pom = BitShift(input, -4);
        data.miesiac = pom;

        input = input - BitShift(pom, 4);
        data.rok = input;

        data.dzien_t = converter(data.dzien_t);
        data.dzien_m = converter(data.dzien_m);
        data.miesiac = converter(data.miesiac);
        data.rok = converter(data.rok);

        
        if(testData(data.dzien_t, data.dzien_m, data.miesiac, data.rok) != 0) break;

        wypiszData(data.dzien_t, data.dzien_m, data.miesiac, data.rok);
    }

    printf("BŁĘDNA REPREZENTACJA!");
    return 0;
}