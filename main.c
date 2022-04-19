#include "exercicios.h"

// Struct exclusiva para item em estoque
typedef struct{
    int cod;
    char nome_item[100];
    float valor;
    int item_estoque;
} estoque;
estoque produtos[5] = { // Array com itens do tipo estoque (struct)
    {1,"Pão de Forma  ", 7.50, 10},
    {2,"Pão de Centeio", 8.69, 20},
    {3,"Broa de Milho ", 5, 5},
    {4,"Sonho         ", 4.5, 30},
    {5,"Tubaína       ", 3.25, 50}
};

// Struct exclusiva pra item em lista de compras
typedef struct{
    float qntd;
    char nome_item[100];
    float valor;
    float subtotal;
} lista;

int main(){
    setlocale(LC_ALL, "Portuguese");

    int opc; // Variavel que é usada como condição no "do..while" abaixo
    do{
        lista lista_compra[25]; // Array de lista de compras que guarda 25 itens da struct lista
        printf(" =============== MENU INCIAL =============== \n");
        printf("\t 0 - SAIR DO SISTEMA \n");
        printf("\t 1 - REALIZAR UMA VENDA \n");
        printf("\t 2 - IMPRIMIR LISTA DE PRODUTOS \n");
        printf("============================================ \n");
        printf(" - Digite sua opção >> ");
        scanf("%d", &opc);
        limpa_tela(1000);
        switch(opc){ // Switch do menu principal (1- Venda / 2 - Print estoque / 0 - Sair)
            int cod; // Variavel que vai receber o codigo que o usuário digitar pra escolher um produto
            int qntd; // Variavel que vai receber a quantidade de produtos que o usuário digitar

            case 0: // Fechar programa
                printf(" - SAINDO DO SISTEMA...");
                break;

            case 1: //Sub-menu de venda
                for(int i = 0;i<=25;i++){ // i<=25 pq o exercicio pede uma lista de compras de ate 25 itens
                    printf("Código    Item    \tValor    \tEstoque \n");
                    for(int i=0; i<5; i++){ // Exibe apenas produtos em estoque
                        if(produtos[i].item_estoque > 0){ // Se o produto tiver estoque 0, nao vai exibir
                            printf(" %d", produtos[i].cod);
                            printf("\t%s ", produtos[i].nome_item);
                            printf("\tR$%.2f ", produtos[i].valor);
                            printf("\t\t%d", produtos[i].item_estoque);
                            printf("\n");
                        }
                    }
                    printf("\n - Digite o código do produto desejado >> ");
                    scanf("%d", &cod);

                     // O indice de um vetor começa em 0, entao subtrair o codigo do produto em 1 sincroniza certinho
                     // Esse index vai ser usado para achar o produto que o usuario solicitar
                    int index = cod-1;
                    if(cod==0){
                        break; // se for 0 para de vender
                    }else if(cod<1 || cod >5){ // se nao estiver entre 1 e 5 vai tentar novamente
                        limpa_tela(1000);
                        printf("Opção inválida! \n");
                    }else{
                        printf(" - Digite a quantidade >> ");
                        scanf("%d", &qntd);

                        if(qntd > produtos[index].item_estoque){ // se a quantidade for maior do que tem no estoque vai tentar novamente
                            printf("\n - Quantidade maior que o estoque!");
                        }else{ // joga na lista o produto desejado
                            strcpy(lista_compra[i].nome_item, produtos[index].nome_item); // Copia nome do produto pra jogar na lista de compra
                            lista_compra[i].valor = produtos[1].valor; // joga valor do produto na lista de compras
                            lista_compra[i].qntd = qntd; // Joga quantidade na lista de compras
                            lista_compra[i].subtotal = qntd*produtos[index].valor; // Calcula o subtotal do produto, multiplicando a quantidade pelo valor

                            // diminui estoque, LEIA-SE: |produtos[index].item_estoque = produtos[index].item_estoque - qntd;|
                            produtos[index].item_estoque -= qntd;
                        }
                    }
                    limpa_tela(1000);
                }
                limpa_tela(1000);
                float total=0; // Inicializa o total
                printf("\n  Item\t\tValor Unit.\tQuantidade\t\tSubtotal \n");
                for(int i=0; i<=25; i++){ // Imprime a lista de compras finalizada
                    if(lista_compra[i].subtotal !=0){ // Caso o array nao atinja 25 produtos, nao vai exibir os espaços em branco
                        printf("\n%s", lista_compra[i].nome_item);
                        printf("\tR$%.2f", lista_compra[i].valor);
                        printf("\t\t\t%.0f", lista_compra[i].qntd);
                        printf("\t\tR$%.2f", lista_compra[i].subtotal);

                        // Calcula o total, LEIA-SE(total = total + lista_compra[i].subtotal)
                        // Essa parte pega o total anterior e soma o subtotal em todos os loops.
                        total += lista_compra[i].subtotal;
                    }else{break;}
                }
                printf("\n\n\t\t\t\t\t\t TOTAL: R$%.2f", total);
                break;
            case 2: // Exibe estoque completo
                printf("Código    Item    \tValor    \tEstoque \n");
                for(int i=0; i<5; i++){
                    printf(" %d", produtos[i].cod);
                    printf("\t%s ", produtos[i].nome_item);
                    printf("\tR$%.2f ", produtos[i].valor);
                    printf("\t\t%d", produtos[i].item_estoque);
                    printf("\n");
                }
                break;
            default:
                printf("Opção Inválida!!");
                break;
        }
        printf("\n");
        system("pause");
        limpa_tela(100);
    }while(opc!=0); // Se a opção é zero, para o loop e fecha o programa.
    return 0;
}
