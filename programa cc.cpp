#include <stdio.h>
#include <locale.h>
#include <math.h>

//programa imprime o n�mero que voc� digitar//

int main(){
    setlocale (LC_ALL, "Portuguese");
    int x;
    printf("Digite um n�mero: \n");
    scanf("%d", &x);
    printf("Voc� digitou: %d \n", x);
    return 0;
}

