#include <stdio.h>
#include <locale.h>
#include <math.h>

//programa imprime o número que você digitar//

int main(){
    setlocale (LC_ALL, "Portuguese");
    int x;
    printf("Digite um número: \n");
    scanf("%d", &x);
    printf("Você digitou: %d \n", x);
    return 0;
}

