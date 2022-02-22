#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* transforma numarul n din baza 10 in baza 2 si il intoarce ca sir de
caractere de '0' sau '1' */
void dec_to_bin(int n, char *s)
{
    int rest, i=0;
    for(i = 0; i < 8;i++){
        rest=n%2;
        if(rest == 1)
            s[7-i]='1';
        else
            s[7-i]='0';
        n=n/2;
    }
    s[8]='\0';
}

/* primeste un numar in baza 2 ca sir de caractere si intoarce valoarea
in baza 10 */
int bin_to_dec(char *s)
{
    /* number reprezinta numarul format, iar p reprezinta puterile lui 2 */
    int number=0, i, p=1;
    for(i = 0; i < 8; i++){
        number = number + p*(s[7-i]-'0');
        p=p*2;
    }
    return number;
}

/* returneaza suma a doua caracete in logica booleana */
char sum_boo(char s1, char s2)
{
    if(s1 == '0' && s2 == '0') return '0';
    if(s1 == '0' && s2 == '1') return '1';
    if(s1 == '1' && s2 == '0') return '1';
    return '1'; /// singurul caz ramas: s1='1' si s2='1'
}

/* returneaza inmultirea a doua caracete in logica booleana */
char multiplication_boo(char s1, char s2)
{
    if(s1 == '0' && s2 == '0') return '0';
    if(s1 == '0' && s2 == '1') return '0';
    if(s1 == '1' && s2 == '0') return '0';
    return '1'; /// singurul caz ramas: s1='1' si s2='1'
}

/* formeaza transpusa matricei "m" si este memorata in matricea
"transpose" */
void trans(char m[][8], char transpose[][8])
{
    int i,j;
    for(i = 0;i < 8; i++){
        for(j = 0; j < i; j++){
            transpose[i][j] = m[j][i];
            transpose[j][i] = m[i][j];
        }
    transpose[i][i] = m[i][i];
    }
}

/* inmulteste matricile "m1" si "m2", iar produsul lor este memorat in
matricea "s" */
void multiply(char m1[][8],char m2[][8],char s[][8])
{
    int i,j,r;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            for(r = 0; r < 8; r++){
                char p = multiplication_boo(m1[i][r], m2[r][j]);
                s[i][j] = sum_boo(s[i][j], p);
            }
        }
    }
}

/* initializeaza matricea m peste tot cu '0' */
void initialization(char m[][8])
{
    int i;
    for(i = 0; i < 8; i++){
        strcpy(m[i],"00000000");
        m[i][8]='\0';
    }
}

/* calculeaza scorul X si 0 pentru o matricea "m" */
int sum_X_0(char m[][8])
{
    int i,j,s=0; /// s va retine scorul X si 0
    int p,q;
    for(p = 0; p < 8; p=p+4)
        for(q = 0; q < 8; q=q+4){ /// imparte matricea in 4 parti egale
            int nr_lines=0,nr_columns=4;
            int nr_dp=1,nr_ds=1;
            for(i=0; i<4; i++){
                /* daca linia i a partii respective din matrice este 1111,
                atunci se mareste nr_lines */
                if(strcmp(m[p+i]+q,"1111")>=0)
                    nr_lines++;

                /* daca pe coloana i a partii respective din matrice se
                gaseste un 0, atunci se micsoreaza nr_coloane*/
                for(j=0; j<4; j++)
                    if(m[p+j][i+q]=='0'){
                        nr_columns--;
                        break;
                    }

                /* daca pe linia i unde intersecteaza diagonala principala
                a partii respective din matrice se gaseste un 0, atunci nu se
                va da scor  */
                if(m[p+i][q+i]=='0') nr_dp=0;

                /* daca pe linia i unde intersecteaza diagonala secundara
                a partii respective din matrice se gaseste un 0, atunci nu se
                va da scor  */
                if(m[p+i][q+3-i]=='0') nr_ds=0;
            }
            s=s+nr_lines+nr_columns+nr_dp+nr_ds;
        }
    return s;
}

int main()
{
    int i,x;
    char array[8][8], product[8][8], square[8][8], transpose[8][8];

    /* initializarea matricelor */
    initialization(array);
    initialization(transpose);
    initialization(product);
    initialization(square);

    /* citeste matricea "array" ce reprezinta matricea A */
    for(i = 0; i < 8; i++){
        scanf("%d",&x);
        dec_to_bin(x,array[i]);
    }

    trans(array,transpose); /// 'transpose' memoreaza transpusa lui A
    multiply(array,transpose,product); /// 'product' memoreaza produsul A*At
    multiply(array,array,square); /// 'square' memoreaza A^2

    /* afisarea matricei castigatoare*/
    if(sum_X_0(array)>=sum_X_0(product) && sum_X_0(array)>=sum_X_0(square)){
        for(i=0;i<8;i++)
            printf("%d\n",bin_to_dec(array[i]));
    }
    else if(sum_X_0(product)>=sum_X_0(square))
        for(i=0;i<8;i++)
            printf("%d\n",bin_to_dec(product[i]));
    else
        for(i=0;i<8;i++)
            printf("%d\n",bin_to_dec(square[i]));

    return 0;
}
