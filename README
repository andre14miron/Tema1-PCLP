// Copyright 314CC Miron Andreea Cristiana

Programarea calculatoarelor si limbaje de programare

Problema #1 Anagrame

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Timpul de implementare pentru acest program a fost de maxim o ora.
	
	Se citeste variabila N, ce reprezinta numarul de perechi, si cele N 
perechi, astfel incat primul cuvant al perechii se regaseste pe o linie a 
tabloului cuv1, iar al doilea cuvant al perechii este memorat pe linia cu 
acelas indice cu primul cuvant in tabloul cuv2. 
	
	Pentru a realiza ordonarea perechilor descrescator dupa gradul lor si
lexicografic descrescator in cazul in care gradele sunt egale, se apeleaza 
functia sort. In cadrul acestia se vor apela alte doua functii: 
	- compute_grade, ce returneaza gradul perechii;
	- swap pentru interschimbarea a doua siruri de caractere; 
	
	Functia compute_grad apeleaza la o alta functie: is_anagram, care 
returneaza 1, daca doua siruri de caractere sunt anagrame si 0, in caz contrar.
Daca perechea nu verifica conditia de a fi anagrame, atunci gradul perechii 
este -1. In caz afirmativ, se declara variabila nr_litere ce va retine numarul
de litere de pe aceeasi pozitie care nu coincid in cele doua cuvinte ale 
perechii. Dupa parcurgerea tuturor literelor se calculeaza gradul perechii.
	Functia mentionata anterior, is_anagram, verifica intai de toate daca
cele doua cuvinte au acelas numar de litere, astfel functia returneaza 0. 
Daca respecta conditia anterioara, se doreste a verifica daca cuvintele au
acelasi litere cu acelas numar de aparitii. Pentru realizarea acesteia, se 
copiaza al doilea cuvant in variabila aux pentru a nu pierde continutul 
acesteia, si se parcurg caracterele primului cuvant. Daca un caracter se 
regaseste in aux, se elimina din aux si se trece la cautarea urmatorului 
caracter. La final, daca aux ramane gol, atunci toate literele s-au regasit si
au fost eliminate, deci functia va returna 1, altfel 0.
	Functia swap interschimba doua siruri de caractere intre ele si este
implementat cu ajutorul metodei celor 3 pahare.

	Functia sort care va ordona perechile se implementeaza pe modelul lui 
Bubble Sort. La fiecare parcurgere a perechilor verifica daca doua perechi 
adiacente au acelas grad pentru a fi ordonate lexicografic descrescator, si
daca gradul primei perechi comparate este mai mica decat cea de-a doua pentru
a fi ordonate descresctor, pentru a fi ordonate descrescator cu ajutorul 
interschimbarii.

	Dupa realizarea ordonarii vectorilor se vor afisa perechile ordonate. 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Problema #2 Sah

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	Timpul de implementare pentru acest program a fost de 3 ore.	

	Se citesc M (dimensiunea tablei) si N (numarul de nebuni). La citirea 
coordonatelor celor N nebuni, se va marca in matricea table prezenta unui nebun 
prin marcarea cu 1.
	Calcularea perechilor de nebuni, care se ataca, va fi returnata de
functia attack_bishops. In aceasta functie este declarata variabila nr care 
memoreaza numarul de perechi, care se ataca. Se verifica toate diagonalele 
tablei, se numara cati nebuni sunt pe o diagonala cu ajutorul functiilor 
diag_prin si diag_sec, si se adauga la nr numarul de perechi, care se ataca,
calculat cu ajutorul functiei comb_2.  
	Functiile mentionate anterior au fost:
	-diag_prin, care calculeaza numarul de nebuni aflati pe diagonala 
paralela cu diagonala principala care contine pozitia de coordonatele x si y, 
prin parcurgerea acesteia;
	-diag_sec, care calculeaza numarul de nebuni aflati pe diagonala 
paralela cu diagonala secundara care contine pozitia de coordonatele x si y, 
prin parcurgerea acesteia; 
	-comb_2, care calculeaza combinari de n luate cate 2. Scopul acestei 
functii este de a calcula numarul de perechi, care se ataca, daca sunt n nebuni
care se afla pe aceiasi diagonala;

	Pentru rezolvarea a doua cerinte a probleme se vor folosi functiile
found_bishops si free_bishop. Functia found_bishops cauta nebunii care se 
ataca, iar functia free_bishop verifica daca un nebun poate sa fie mutat astfel 
incat sa nu mai fie atacat.
	Daca numarul de nebuni, care se ataca, nu este 1 se va printa mesajul 
"NU". In caz afirmativ, se va verifica daca un nebun poate sa fie mutat. Se 
cauta nebunii care se ataca si pentru fiecare se va verifica daca poate sa fie 
mutat. Daca niciunul nu a putut fi mutat, se afiseaza mesajul "NU", altfel 
"DA".

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Problema #3 Rubik's Cube

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	Timpul de implementare pentru acest program a fost de 4 ore.	

	Se citesc cele 6 culori si sunt memorate in tabloul de caractere 
'color'. Fetele cubului sunt citite cu ajutorul functiei read_face, apelata de
6 ori pentru fiecare fata a cubului, in care fiecare patrat al fetei este 
asociat cu numarul culorii respective. 
	De asemenea se citeste m (numarul de mutari) si cele m mutari. La
citirea fiecarei mutari se realizeaza efectuarea mutarii respective cu ajutorul
unei functii asociate mutarii. Fiind 12 mutari exista 12 functii (F, F_prim, B,
B_prim, U, U_prim, D, D_prim, R, R_prim, L, L_prim)  dedicate fiecarei mutari.
Structura unei astfel de functii este urmatoarea: interschimba patratele 
cubului care sunt afectate de acea mutare si roteste fata respectiva cu
ajutorul uneia dintre functiile rotate_left si rotate_right. Functia 
rotate_left roteste o fata cu 90 de grade in sens opus acelor de ceasornic, iar
functia rotate_right roteste o fata cu 90 de grade in sensul acelor de 
ceasornic. 
	Dupa realizarea tuturor mutarilor se afiseaza fetele cubului prin
apelarea functiei print_face pentru fiecare fata in parte, care afiseaza
culoarea asociat fiecarui patrat al fetei. 

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Problema #4 X si 0

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	Timpul de implementare pentru acest program a fost de 3 ore.	

	In rezolvarea acestei probleme a fost nevoie de declararea a patru
tablouri de caractere:
	- array, ce memoreaza matricea A;
	- transpose, ce memoreaza transpusa matricei A;
	- product, ce memoreaza produsul dintre A si A transpus;
	- square, ce memoreaza patratul matricei A;

	Inainte de citire se initializeaza toate matricile prin apelarea 
succesiva a functiei initialization.  
	Se citesc numerele care sunt prelucrate prin apelarea functiei 
dec_to_bin, care transforma un numar din baza 10 in baza 2 si il intoarce ca 
sir de caractere de '1' si '0'. Rezultatul functiei este memorat pe fiecare
linie a matricei array. 
	Intai de toate pentru a face produsul dintre A si A transpus se 
apeleaza functia trans care calculeaza transpusa matricei array si este 
memorata in matricea transpose. 
	Pentru obtinerea celorlalte matrici necesare se apeleaza functia 
multiply, care inmulteste doua matrici. Functia este folosita o data pentru
obtinerea produsului dintre A si A transpus, si o data pentru obtinerea 
patratului matricii A, prin inmultirea dintre A si A. In cadrul acestei 
functii de multiply au fost folosite doua functii pentru calcularea produsului:
sum_boo si multiplication_boo. Aceste doua functii returneaza suma, respectiv
produsul in logica booleana dintre doua caractere de forma '0' sau '1'.
	In urma obtinerii celor trei matrici necesare se compara punctajele lor
in urma jocului de X si 0, calculat de functia sum_X_0, iar cine are scorul cel
mai mare este afisat cu ajutorul functiei de bin_to_dec, care primeste un numar 
in baza 2 ca sir de caractere si intoarce valoarea in baza 10. 
	
