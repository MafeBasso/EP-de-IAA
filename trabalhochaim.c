#include <stdio.h>

/* Definicao de constantes */

#define MAX 15
#define FALSE 0
#define TRUE 1

/* Programa 1a */
extern int remover1(int k, int n, int * v){
    if (n <= 0 || n > MAX || k < 0 || k > n-1) return -1;
    for (int m = k; m <= n-2; m++) {
        v[m] = v[m+1];
    }
    n--;
    return n;
}

/* Programa 1b */
extern int inserir1(int x, int k, int n, int * v){
    if (k == 0 && n == 0) {
        v[k] = x;
        n++;
        return n;
    }
    if (n < 0 || n >= MAX || k < 0 || k > n-1) return -1;
    for (int m = n; m >= k+1; m--) {
        v[m] = v[m-1];
    }
    v[k] = x;
    n++;
    return n;
}

/* Programa 2 */
extern int remover2(int k, int n, int ini, int fim, int * v){
    if (n <= 0 || n > MAX || ini < 0 || fim > n || ini > fim-1 || k < ini || k > fim-1) return -1;
    if (fim-1 == ini) {
        fim--;
    } else if (k-ini <= fim-1-k) {
        for (int m = k; m > ini; m--) {
            v[m] = v[m-1];
        }
        ini++;
    } else if (k-ini > fim-1-k) {
        for (int m = k; m < fim-1; m++) {
            v[m] = v[m+1];
        }
        fim--;
    }
    return (fim-ini);
}

/* Programa 3 */
extern void inserir3(int x, int k, int n, int * v){
    if (k == 0 && n == 0) {
        v[k] = x;
        n++;
        return;
    }
    if (n < 0 || n >= MAX || k < 0 || k > n-2) return;
    for (int m = n; m > k+1; m--) {
        v[m] = v[m-1];
    }
    v[k+1] = x;
    n++;
    return;
}

/* Programa 4 */
extern int tamanhoSegmentoHorizontal(int n, int * v){
    if(n < 0 || n > MAX) return -1;
    int tamanhofinal = 0, contador = 0;
    for (int m = 0; m < n-1; m++) {
        if (v[m] == v[m+1]) {
            contador++;
            if (contador > tamanhofinal) tamanhofinal = contador;
        } else {
            contador = 0;
        }
    }
    if (tamanhofinal == 0) return tamanhofinal;
    return (tamanhofinal+1);
}

/* Programa 5 */
extern int ehSubsequencia(int tamX, int * x, int n, int * v){
    if (tamX < 0 || n < 0 || n > MAX) return FALSE;
    if (tamX == 0) return TRUE;
    int indice = 0;
    for (int m = 0; m < n; m++) {
        if (x[indice] == v[m]) {
            indice++;
        }
    }
    if (indice == tamX) return TRUE;
    return FALSE;
}

/* Programa 6 */
extern void remover6(int y, int n, int ini, int fim, int * v){
    if (n <= 0 || n > MAX || ini < 0 || ini > fim-1 || fim > n) return;
    int g = 0;
    for (int m = ini; m <= fim-1; m++) {
        if (v[m] == y) {
            g++;
        }
        if ((g>0) && (v[m] =! y)){
            v[m] = v[m+g];
        }
        if (m == fim-1) {
            if (g == fim) {
                for (int d = ini; d < n; d++) v[d] = v[d+fim];
                ini = fim = 0;
            } else {
                fim = fim - g;
            }
        }
    }
    return;
}

/* Programa 7 */
extern int onde(int x, int n, int * v) {
    if (n <= 0 || n > MAX) return -1;
    static int pos = 0;
    if (v[pos] == x) {
        return pos;
    }
    pos++;
    return onde(x, n, v);
}

/* Programa 8 */
extern int localiza(int x, int n, int ini, int fim, int * v){
    if (n <= 0 || n > MAX || ini < 0 || fim > n) return -1;
    if (ini >= fim) return -1;
    if (v[ini] == x) return ini;
    return localiza(x, n, ini+1, fim, v);
}

/* Programa 9 */
extern int * subSequenciaMaxima(int n, int * v, int * tamret){
    if (n < 0 || n > MAX) {
        int* erro = NULL;
        *tamret = -1;
        return erro;
    }
    int globalmax = 0, sufixmax = 0, globalprim = 0, globalult = 0, sufixult = 0, cont = 0;
    for (int i = 0; i < n; i++) {
        if (v[i]+sufixmax > globalmax) {
            sufixmax = sufixmax + v[i];
            globalmax = sufixmax;
            sufixult++;
            if (cont != 0) globalprim = globalult + cont - 1;
            globalult = sufixult;
        } else {
            if (v[i]+sufixmax > 0) {
                sufixmax = sufixmax + v[i];
                sufixult++;
            }else {
                sufixmax = 0;
                cont = sufixult - globalult;
                sufixult++;
            }
        }
    }
    *tamret = globalult - globalprim;
    int* p = &v[globalprim];
    return p;
}

int main(void)
{

int i, n,  res, acertos = 0;

/* Preparacao dos vetores para testes */
/* vetor de entrada: v???[] */
/* vetor de saida: b???[] */

/* Vetores programa 1a */
int v1a [] = {1,2,3,4,5,6,7,8,9,10,-1,-1,-1,-1,-1};
int b1a [] = {1,2,3,5,6,7,8,9,10};

/* Vetores programa 1b */
int v1b [] = {1,2,3,5,6,7,8,9,10,-1,-1,-1,-1,-1,-1};
int b1b [] = {1,2,3,5,6,3,7,8,9,10};

/* Vetores programa 2 */
int v2 [] = {1,2,3,5,6,3,7,8,9,10,-1,-1,-1,-1,-1};
int b2 [] = {1,2,2,3,6,3,7,8,9,10};

/* Vetores programa 3 */
int v3 [] = {1,2,3,6,3,7,8,9,10,-1,-1,-1,-1,-1,-1};
int b3 [] = {1,2,3,6,3,3,7,8,9,10};

/* Vetor programa 4 */

int v4 [] = {1,1,1,2,3,6,6,7,8,9,10,-1,-1,-1,-1};

/* Vetores programa 5 */

int v5a [] = {11,12,13,11,10,9,7,3,3,-1,-1,-1,-1,-1,-1};

int v5b [] = {12,13,10,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int v5c [] = {11,12,10,11,13,9,7,3,3,-1,-1,-1,-1,-1,-1};

/* Vetores programa 6 */

int v6 [] = {1,1,1,2,3,6,6,7,8,9,10,-1,-1,-1,-1};
int b6 [] = {1,2,3,6,6,7,8,9,10};

/* Vetor programa 7 */

 int v7 [] = {1,1,1,2,3,6,6,7,8,9,10,-1,-1,-1,-1};

/* Vetor programa 8 */

 int v8 [] = {1,1,1,2,3,6,6,7,7,9,10,-1,-1,-1,-1};

/* Vetores programa 9 */

int v9 [] = {11,12,10,11,13,9,7,3,3,-1,-1,-1,-1,-1,-1};
int b9 [] = {11,12,10,11,13,9,7,3,3};
int *pb9;
int tamb9;


/* Teste programa 1a */

n = 10;
res=FALSE;

n=remover1(3,n,v1a);
if(n == 9)
	{
	res = TRUE;
	for(i=0; i < n;++i)
		{
		if(v1a[i] != b1a[i])
			{
			res=FALSE;
			break;
			}
		}
	if(res)
		++acertos;
        printf("\n");
	}

/* Teste programa 1b */


res=FALSE;

n = 9;
n = inserir1(3,5,n,v1b);
if(n == 10)
	{
	res = TRUE;
	for(i=0; i < n;++i)
		{
		if(v1b[i] != b1b[i])
			{
			res=FALSE;
			break;
			}
		}
	if(res)
		++acertos;
	}

/* Teste programa 2 */

res=FALSE;
n = 10;
n=remover2(3,n,1,9,v2);
if(n == 7)
	{
	res = TRUE;
	for(i=0; i < 9;++i)
		{
		if(v2[i] != b2[i])
			{
			res=FALSE;
			break;
			}
		}
	if(res)
		++acertos;
	}



/* Teste programa 3 */

inserir3(3,4,9,v3);

if(v3[5] == 3) acertos++;

/* Teste programa 4 */

if(tamanhoSegmentoHorizontal(11, v4) == 3) acertos++;

/* teste programa 5 */

if(ehSubsequencia(4, v5b, 9,  v5a))
	acertos++;

if(!ehSubsequencia(4, v5b, 9,  v5c))
	acertos++;

/* teste programa 6 */

remover6(1,11,1,6,v6);

if(v6[0]==b6[0] && v6[1] != 1 && v6[2] != 1)
	acertos++;

/* Teste programa 7 */

if(onde(6,11,v7) == 6) acertos++;

/* Teste programa 8 */

if(localiza(6,11,7,11,v8) == -1) acertos++;

/* Teste programa 9 */

pb9 = (int *) subSequenciaMaxima(9,v9,&tamb9);

res=FALSE;
if(tamb9 == 9)
	{
	res=TRUE;
	for(i=0; i < tamb9 ; ++i)
		if(pb9[i] != b9[i]){
			res=FALSE;
			break;
		}
}

if(res) acertos++;

printf("Acertos: %d\n",acertos);
}
