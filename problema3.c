#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CMAX 10

/* interschimba valorile a si b */
void swap(int *a, int *b)
{
    /// regula celor 3 pahare
    int aux=*a;
    *a=*b;
    *b=aux;
}

/* citeste o fata a cubului si fiecarui patratel de pe fata i se asociaza
un numar asociat culorii lui*/
void read_face(int face[][3], char color[][CMAX])
{
    int i,j,k;
    char line[33];
    for(i = 0; i < 3; i++){
        scanf("%s",line);
        char  *square; /// square reprezinta un patrat al fetei
        square=strtok(line,"."); /// citeste cate o linie a fetei
        j=0;
        while(square != NULL){
            for(k = 0; k < 6; k++)
                if(strcmp(color[k],square)==0)
                    face[i][j]=k; /// asociem culorii o valoare
            square=strtok(NULL,".");
            j++;
        }
    }
}

/* afiseaza o fata cubului */
void print_face(int v[][3], char color[][10])
{
    int i;
    for(i = 0; i < 3; i++){
        printf("%s.%s.%s", color[v[i][0]], color[v[i][1]], color[v[i][2]]);
        printf("\n");
    }
}

/* rotirea fetei in sens opus acelor de ceasornic */
void rotate_left(int face[][3])
{
    swap(&face[0][0],&face[0][2]);
    swap(&face[0][2],&face[2][2]);
    swap(&face[2][2],&face[2][0]);

    swap(&face[0][1],&face[1][2]);
    swap(&face[1][2],&face[2][1]);
    swap(&face[2][1],&face[1][0]);
}

/* rotirea fetei in sensul acelor de ceasornic */
void rotate_right(int face[][3]){
    swap(&face[0][2],&face[0][0]);
    swap(&face[0][0],&face[2][0]);
    swap(&face[2][0],&face[2][2]);

    swap(&face[1][0],&face[0][1]);
    swap(&face[2][1],&face[1][0]);
    swap(&face[1][2],&face[2][1]);
}

/* realizeaza mutarea F */
void F(int Fr[][3], int Up[][3], int Dw[][3], int Lf[][3], int Rg[][3])
{
    int i;
    for(i = 0; i < 3; i++){
        swap(&Up[2][i],&Lf[2-i][2]);
        swap(&Lf[2-i][2],&Dw[0][2-i]);
        swap(&Dw[0][2-i],&Rg[i][0]);
    }
    rotate_right(Fr);
}

/* realizeaza mutarea F' */
void F_prim(int Fr[][3], int Up[][3], int Dw[][3], int Lf[][3], int Rg[][3])
{
    int i;
    for(i = 0; i < 3; i++){
        swap(&Up[2][i],&Lf[2-i][2]);
        swap(&Rg[i][0],&Up[2][i]);
        swap(&Dw[0][2-i],&Rg[i][0]);
    }
    rotate_left(Fr);
}

/* realizeaza mutarea B */
void B(int Bc[][3], int Up[][3], int Dw[][3], int Lf[][3], int Rg[][3])
{
    int i;
    for(i = 0; i < 3; i++){
        swap(&Up[0][i],&Lf[2-i][0]);
        swap(&Rg[i][2],&Up[0][i]);
        swap(&Dw[2][2-i],&Rg[i][2]);
    }
    rotate_right(Bc);
}

/* realizeaza mutarea B' */
void B_prim(int Bc[][3], int Up[][3], int Dw[][3], int Lf[][3], int Rg[][3])
{
    int i;
    for(i = 0; i < 3; i++){
        swap(&Up[0][i],&Lf[2-i][0]);
        swap(&Lf[2-i][0],&Dw[2][2-i]);
        swap(&Dw[2][2-i],&Rg[i][2]);
    }
    rotate_left(Bc);
}

/* realizeaza mutarea U */
void U(int Fr[][3], int Bc[][3], int Up[][3], int Lf[][3], int Rg[][3])
{
    int i;
    for(i = 0; i < 3; i++){
        swap(&Fr[0][i],&Lf[0][i]);
        swap(&Rg[0][i],&Fr[0][i]);
        swap(&Bc[0][i],&Rg[0][i]);
    }
    rotate_right(Up);
}

/* realizeaza mutarea U' */
void U_prim(int Fr[][3], int Bc[][3], int Up[][3], int Lf[][3], int Rg[][3])
{
    int i;
    for(i = 0; i < 3; i++){
        swap(&Fr[0][i],&Lf[0][i]);
        swap(&Lf[0][i],&Bc[0][i]);
        swap(&Bc[0][i],&Rg[0][i]);
    }
    rotate_left(Up);
}

/* realizeaza mutarea D */
void D(int Fr[][3], int Bc[][3], int Dw[][3], int Lf[][3], int Rg[][3])
{
    int i;
    for(i = 0; i < 3; i++){
        swap(&Fr[2][i],&Lf[2][i]);
        swap(&Lf[2][i],&Bc[2][i]);
        swap(&Bc[2][i],&Rg[2][i]);
    }
    rotate_right(Dw);
}

/* realizeaza mutarea D' */
void D_prim(int Fr[][3], int Bc[][3], int Dw[][3], int Lf[][3], int Rg[][3])
{
    int i;
    for(i = 0; i < 3; i++){
        swap(&Fr[2][i],&Lf[2][i]);
        swap(&Rg[2][i],&Fr[2][i]);
        swap(&Bc[2][i],&Rg[2][i]);
    }
    rotate_left(Dw);
}

/* realizeaza mutarea R */
void R(int Fr[][3], int Bc[][3], int Up[][3], int Dw[][3], int Rg[][3])
{
    int i;
    for(i = 0; i < 3; i++){
        swap(&Fr[i][2],&Up[i][2]);
        swap(&Dw[i][2],&Fr[i][2]);
        swap(&Bc[2-i][0],&Dw[i][2]);
    }
    rotate_right(Rg);
}

/* realizeaza mutarea R' */
void R_prim(int Fr[][3], int Bc[][3], int Up[][3], int Dw[][3], int Rg[][3])
{
    int i;
    for(i = 0; i < 3; i++){
        swap(&Fr[i][2],&Up[i][2]);
        swap(&Up[i][2],&Bc[2-i][0]);
        swap(&Bc[2-i][0],&Dw[i][2]);
    }
    rotate_left(Rg);
}

/* realizeaza mutarea L */
void L(int Fr[][3], int Bc[][3], int Up[][3], int Dw[][3], int Lf[][3])
{
    int i;
    for(i = 0; i < 3; i++){
        swap(&Fr[i][0],&Up[i][0]);
        swap(&Up[i][0],&Bc[2-i][2]);
        swap(&Bc[2-i][2],&Dw[i][0]);
    }
    rotate_right(Lf);
}

/* realizeaza mutarea L' */
void L_prim(int Fr[][3], int Bc[][3], int Up[][3], int Dw[][3], int Lf[][3])
{
    int i;
    for(i = 0; i < 3; i++){
        swap(&Fr[i][0],&Up[i][0]);
        swap(&Dw[i][0],&Fr[i][0]);
        swap(&Bc[2-i][2],&Dw[i][0]);
    }
    rotate_left(Lf);
}

int main()
{
    char color[6][CMAX];
    int Fr[3][3], Bc[3][3], Up[3][3], Dw[3][3], Lf[3][3], Rg[3][3];
    int i;

    /// citirea celor 6 culori
    for(i=0; i<6; i++)
        scanf("%s",color[i]);

    /// citirea fetelor cubului
    read_face(Fr,color);
    read_face(Bc,color);
    read_face(Up,color);
    read_face(Dw,color);
    read_face(Lf,color);
    read_face(Rg,color);

    /// citirea celor m mutari si efectuarea lor
    int m;
    char move[2];
    scanf("%d",&m);
    for(i=0; i<m; i++){

        scanf("%s",move);
        if(strcmp(move,"F")==0) F(Fr,Up,Dw,Lf,Rg);
        if(strcmp(move,"F'")==0) F_prim(Fr,Up,Dw,Lf,Rg);
        if(strcmp(move,"B")==0) B(Bc,Up,Dw,Lf,Rg);
        if(strcmp(move,"B'")==0) B_prim(Bc,Up,Dw,Lf,Rg);
        if(strcmp(move,"U")==0) U(Fr,Bc,Up,Lf,Rg);
        if(strcmp(move,"U'")==0) U_prim(Fr,Bc,Up,Lf,Rg);
        if(strcmp(move,"D")==0) D(Fr,Bc,Dw,Lf,Rg);
        if(strcmp(move,"D'")==0) D_prim(Fr,Bc,Dw,Lf,Rg);
        if(strcmp(move,"R")==0) R(Fr,Bc,Up,Dw,Rg);
        if(strcmp(move,"R'")==0) R_prim(Fr,Bc,Up,Dw,Rg);
        if(strcmp(move,"L")==0) L(Fr,Bc,Up,Dw,Lf);
        if(strcmp(move,"L'")==0) L_prim(Fr,Bc,Up,Dw,Lf);

    }

    /// afisarea fetelor cubului
    print_face(Fr,color);
    print_face(Bc,color);
    print_face(Up,color);
    print_face(Dw,color);
    print_face(Lf,color);
    print_face(Rg,color);
    return 0;
}
