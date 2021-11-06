#include <stdio.h>
#include <locale.h>

//programa imprime o "Hello word"//

int main(){
    setlocale (LC_ALL, "Portuguese");
    printf("Hello word!");
    return 0;
}

