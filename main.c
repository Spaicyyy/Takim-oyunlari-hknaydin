#include <stdio.h>

int main()
{
    
    FILE *file = fopen("takimlar.txt" , "r") ;
    if(file == NULL) {
        printf("File acilmadi"); 
        return 1 ;
    }
    char takimlar[19][50] ; 
    for(int i=0 ; i< 19 ; i++) {
        fgets(takimlar[i], 50, file);
        takimlar[i][strcspn(takimlar[i], "\n")] = 0 ;
    }
    
    FILE *file1 = fopen("oyunlar.txt" , "w") ;
    if(file1== NULL ) {
        printf("File acilmadi") ;
        return 1 ;
    }
    
    for(int i=1 ; i<38 ; i++) {
        fprintf(file1 , "%d.Hafta\n", i) ;
        
        int bosTakim = i % 19 ;
        for(int j=0 ; j <19 ; j++){
            int Ev = (i + j) % (18);
            int Misafir = (18 - j) % (18) ;
            if(j == 0) 
            Misafir = 18 ;
            
            if(Ev != bosTakim && Misafir != bosTakim) {
                fprintf(file1 , "||| %s vs %s ||| " , takimlar[Ev] , takimlar[Misafir]);
            }
        }
        fprintf(file1 ,"Bu hafta bos olan takim:%s \n ",takimlar[bosTakim]) ;
    }

    
    fclose(file1) ; 
   fclose(file); 
    return 0;
}
