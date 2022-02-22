#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NMAX 1000

/* verifica daca sirurile de caractere s1 si s2 sunt anagrame */
int is_anagram(char *s1, char *s2)
{
    if(strlen(s1)!=strlen(s2)) return 0;

    int i;
    int fr1[26],fr2[26];
    /* initializam frecventele */
    for(i=0;i<26;i++){
        fr1[i]=0;
        fr2[i]=0;
    }

    /* vectorii de frecventa vor memora de cate ori a aparut fiecare litera in
    cele doua cuvinte*/
    for(i=0;i<strlen(s1);i++){
        fr1[s1[i]-'a']++;
        fr2[s2[i]-'a']++;
    }

    /* verificare daca cuvintele contin exact aceleasi caractere, cu acelasi
    numar de aparitii */
    for(i=0;i<26;i++)
        if(fr1[i]!=fr2[i])
            return 0;
    return 1;
}

/* returneaza gradul a doua siruri de caractere s1 si s2 */
double compute_grade(char *s1, char *s2)
{
    /// daca s1 si s2 nu sunt anagrame, atunci gradul este -1
    if(is_anagram(s1,s2)==0) return -1;

    int i, nr_leters=0;
    /* variabila nr_leters va retine numarul de litere de pe acelas indice
    care nu coincid */
    for(i = 0; i < strlen(s1); i++)
        if(s1[i] != s2[i])
            nr_leters++;
    return (double)(nr_leters)/strlen(s1); /// calculare grad
}

/* interschimba sirurile de caractere s1 si s2 */
void swap(char *s1, char *s2)
{
    /// regula celor 3 pahare
    char aux[50];
    strcpy(aux,s1);
    strcpy(s1,s2);
    strcpy(s2,aux);
}

/* ordoneaza perechile descrescator dupa gradul lor si descrescator lexicografic
daca exista perechi cu acelas grad */
void sort(char v1[][50], char v2[][50], int N)
{
    int ok, i;
    do{
        ok=1; /// presupunem ca perechile sunt ordonate
        for(i = 0; i < N-1; i++){
            /* daca 2 perechi au acelas grad, verificam daca sunt ordonate
            descrescator lexicografic */
            if(compute_grade(v1[i],v2[i]) == compute_grade(v1[i+1],v2[i+1]))
                if(strcmp(v1[i],v1[i+1]) < 0){
                    swap(v1[i],v1[i+1]);
                    swap(v2[i],v2[i+1]);
                    ok=0;
                }
            /* daca gradele difera, ordonam descrescator dupa grad */
            if(compute_grade(v1[i],v2[i]) < compute_grade(v1[i+1],v2[i+1])){
                swap(v1[i],v1[i+1]);
                swap(v2[i],v2[i+1]);
                ok=0;
            }
        }
    }while(ok == 0);
}

int main()
{
    int N, i;
    char word1[NMAX][50], word2[NMAX][50];

    /* citeste numarul de perechi N si cele N perechi de siruri */
    scanf("%d",&N);
    for(i = 0; i < N; i++)
        scanf("%s%s",word1[i],word2[i]);

    sort(word1, word2, N);

    /* afiseaza cele N perechi dupa ordonare */
    for(i = 0; i < N; i++)
        printf("%s %s\n", word1[i], word2[i]);
    return 0;
}
