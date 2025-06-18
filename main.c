#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char linha[256];
char buffer[20];
char nome[50], senha[50], senhaVerify[50];
int id, idVerify;

typedef struct
{
    char nome[50];
    int id;
    char senha[50];
} UsuarioNovo;

int verificador() {
    if (strcmp(senhaVerify, senha) == 0) {
        //printf("Logado com sucesso\n");
        return 1;
    } else {
        printf("Senha incorreta\n");
        return 0;
    }
    
    return 0;
}
int registrador() {
    UsuarioNovo a;
    FILE *arq = fopen("Usuarios.txt", "a");
        if (!arq)
        {
            printf("Erro ao abrir arquivo");
            return 1;
        }
        
    printf("Nome: ");
    fgets(a.nome, sizeof(a.nome), stdin);
    a.nome[strcspn(a.nome, "\n")] = '\0';

    printf("Id: ");
    scanf("%d", &a.id);
    getchar();

    printf("Senha: ");
    fgets(a.senha, sizeof(a.senha), stdin);
    a.senha[strcspn(a.senha, "\n")] = '\0';
    

    
    fprintf(arq, "%s;%d;%s", a.nome, a.id, a.senha);
    fclose(arq);
    return 0;
}

int menuAdm() {
    int opcao;
    printf("---MENU ADM---\n");

    do
    {
    printf("1. Registrar usuario\n");
    printf("2. Voltar\n");

    switch (opcao)
    {
    case 1:
        registrador();
        break;
    case 2:
        printf("Voltando...");
        return 0;
        break;
    default:
        break;
    }
    } while (opcao != 2);

    return 0;
}



int entrar() {

    FILE *arq = fopen("Usuarios.txt", "r");
    if (arq == NULL) {
        return 1; 
    }

    while(fgets(linha, sizeof(linha), arq) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
        //int id = atoi(linha);

        if(sscanf(linha, "%49[^;];%d;%49[^\n]", nome, &id, senha) == 3) {
            //printf("%s", linha);
            printf("Id: ");
            scanf("%d", &idVerify);
            if (idVerify == id) 
            {
                printf("Senha: ");
                scanf("%s", &senhaVerify);
                verificador();
            } else
            {
                printf("Id invalido.");
                return 0;
            }
        
        
        }   
    } 
    fclose(arq);
    return 0;
}

int main() {
    printf("|---MENU---|\n");
    printf("|1. Login  |\n");
    printf("|2. Sair   |\n");
    int escolha;
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        entrar();
        menuAdm();
        break;
    case 2:
        printf("Saindo...");
    return 0;
    break;
    }

    return 0;
}

