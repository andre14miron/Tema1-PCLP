#include <stdio.h>
#include <stdlib.h>
#define MMAX 100

/* returneaza combinari de n luate cate 2 */
int comb_2(int n)
{
    int i, n_factorial=1, dif_factorial=1;

    if(n == 0 || n == 1) return 0; /// cazuri speciale

    for(i = 2; i <= n; i++)
        n_factorial=n_factorial*i; /// calculeaza n!
    for(i = 2; i <= n-2; i++)
        dif_factorial=dif_factorial*i; /// calculeaza (n-2)!

    return n_factorial/(2*dif_factorial);
}

/* parcurge diagonala paralela cu diagonala principala pe care se afla piesa
de coordonate x si y */
int diag_prin(int table[MMAX][MMAX], int x, int y, int M)
{
    int nr=0,i,j;

    /// parcurgere spre linia 0
    i=x;
    j=y;
    while(i < M && j < M){
        if(table[i][j] == 1)
            nr++;
        i++;
        j++;
    }

    /// parcurgere spre ultima linie
    i=x-1;
    j=y-1;
    while(i >= 0 && j >= 0){
        if(table[i][j] == 1)
            nr++;
        i--;
        j--;
    }
    return nr;
}

/* parcurge diagonala paralela cu diagonala secundara pe care se afla piesa
de coordonate x si y */
int diag_sec(int table[MMAX][MMAX], int x, int y, int M)
{
    int nr=0, i, j;

    /// parcurgere spre linia 0
    i=x;
    j=y;
    while(i < M && j >= 0){
        if(table[i][j] == 1)
            nr++;
        i++;
        j--;
    }

    /// parcurgere spre ultima linie
    i=x-1;
    j=y+1;
    while(i >= 0 && j < M){
        if(table[i][j] == 1)
            nr++;
        i--;
        j++;
    }
    return nr;
}

/* returneaza numarul de perechi de nebuni care se ataca */
int attack_bishops(int table[MMAX][MMAX], int M)
{
    int i, nr=0; /// variabila nr va retine numarul de perechi care se ataca
    /* daca pe o diagonala sunt n nebuni, atunci numarul de perechi este
    combinari de n luate cate 2 */
    nr = nr + comb_2(diag_prin(table,0,0,M)); /// diagonala principala
    nr = nr + comb_2(diag_sec(table,0,M-1,M)); /// diagonala secundara
    for( i = 1; i < M; i++)
    {
       nr = nr + comb_2(diag_prin(table,i,0,M)); /// sub diag. princ.
       nr = nr + comb_2(diag_prin(table,0,i,M)); /// deasupra diag. princ.
       nr = nr + comb_2(diag_sec(table,0,M-i-1,M)); /// sub diag. sec.
       nr = nr + comb_2(diag_sec(table,i,M-1,M)); /// deasupra diag. sec.
    }
    return nr;
}

/* gaseste nebunii de coordonate (x1,y1) si (x2,y2) care se ataca */
void found_bishops(int table[MMAX][MMAX], int *x1, int *y1, int *x2, int *y2, int M)
{
    int i,j;
    for(i = 0; i < M; i++)
        for(j = 0; j < M; j++)
            if(table[i][j] == 1)
                if(diag_prin(table,i,j,M) == 2 || diag_sec(table,i,j,M) == 2)
                    if(*x1==-1){
                        /// gasire primul nebun
                        *x1=i;
                        *y1=j;
                    }
                    else{
                    /// gasire al doilea nebun
                    *x2=i;
                    *y2=j;
                    }
}

/* returneaza 1 daca se poate muta nebunul de coordonate (x,y) astfel incat
sa nu mai fie atacat de un alt nebun, si 0 in caz contrar */
int free_bishop(int table[MMAX][MMAX], int M, int x, int y)
{
    int i,j;
    table[x][y]=0; /// elibereaza locul nebunului pe care vrem sa il mutam
    for(i = 0; i < M; i++)
        for(j = 0; j < M; j++)
            if(diag_prin(table,i,j,M) == 0 && diag_sec(table,i,j,M) == 0){
                /// a fost gasit un loc unde nu sunt nebuni pe diagonale
                table[x][y]=1; /// reocuparea locului initial
                return 1;
            }
    table[x][y]=1; /// reocuparea locului initial
    return 0;
}

int main()
{
    int M, N, table[MMAX][MMAX];
    int i, x, y;

    /// citeste dimensiunea tablei M, numarul de nebuni N si cei N nebuni
    scanf("%d%d",&M,&N);
    for(i = 0; i < N; i++){
        scanf("%d%d",&x,&y);
        table[x][y]=1; /// marcare cu 1 prezenta unui nebun
    }

    /// afiseaza numarul de perechi de nebuni care se ataca
    printf("%d\n", attack_bishops(table,M));

    /*  Daca numarul de perechi de nebuni care se ataca este 1 si exista
    posibilitatea de mutare a unui nebun astfel incat sa nu fie nicio pereche
    de nebuni care se ataca, se afiseaza "DA". Altfel, se afiseaza "NU". */
    if(attack_bishops(table,M) != 1)
        printf("NU\n");
    else{
        /// cauta pozitiile nebunului 1(x1,y1) si nebunului 2(x2,y2)
        int x1=-1, y1=-1, x2=-1, y2=-1;
        found_bishops(table,&x1,&y1,&x2,&y2,M);

        /// verificare daca s-a putut muta un nebun
        if(free_bishop(table,M,x1,y1) == 1)
            printf("DA\n");
        else if(free_bishop(table,M,x2,y2) == 1)
                printf("DA\n");
        else printf("NU\n");
    }
    return 0;
}
