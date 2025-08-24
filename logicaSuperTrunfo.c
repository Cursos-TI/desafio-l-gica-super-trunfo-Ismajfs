#include <stdio.h>
#include <string.h>

int main() {
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nome1[50], nome2[50];
    unsigned long int populacao1 = 0, populacao2 = 0;
    float area1 = 0, area2 = 0;
    float pib1 = 0, pib2 = 0;
    int pontos1 = 0, pontos2 = 0;

    int opcao;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Cadastrar cartas\n");
        printf("2. Comparar cartas\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite os dados da primeira carta:\n");

                printf("Estado (A-H): ");
                scanf(" %c", &estado1);

                printf("Código da carta (ex: A01): ");
                scanf("%3s", codigo1);

                printf("Nome da cidade: ");
                getchar();
                fgets(nome1, 50, stdin);
                nome1[strcspn(nome1, "\n")] = '\0'; // remove newline

                printf("População: ");
                scanf("%lu", &populacao1);

                printf("Área (km²): ");
                scanf("%f", &area1);

                printf("PIB: ");
                scanf("%f", &pib1);

                printf("Número de pontos turísticos: ");
                scanf("%d", &pontos1);

                printf("\nDigite os dados da segunda carta:\n");

                printf("Estado (A-H): ");
                scanf(" %c", &estado2);

                printf("Código da carta (ex: A01): ");
                scanf("%3s", codigo2);

                printf("Nome da cidade: ");
                getchar();
                fgets(nome2, 50, stdin);
                nome2[strcspn(nome2, "\n")] = '\0';

                printf("População: ");
                scanf("%lu", &populacao2);

                printf("Área (km²): ");
                scanf("%f", &area2);

                printf("PIB: ");
                scanf("%f", &pib2);

                printf("Número de pontos turísticos: ");
                scanf("%d", &pontos2);
                break;

            case 2:
                if (populacao1 == 0 || populacao2 == 0) {
                    printf("\n⚠️ Primeiro cadastre as cartas!\n");
                    break;
                }

                float densidade1 = populacao1 / area1;
                float pibPerCapita1 = pib1 / populacao1;

                float densidade2 = populacao2 / area2;
                float pibPerCapita2 = pib2 / populacao2;

                float superPoder1 = (float)populacao1 + area1 + pib1 + (float)pontos1 + pibPerCapita1 + (1.0f / densidade1);
                float superPoder2 = (float)populacao2 + area2 + pib2 + (float)pontos2 + pibPerCapita2 + (1.0f / densidade2);

                printf("\n🔍 Comparação de Cartas:\n\n");
                printf("População: Carta 1 venceu (%d)\n", populacao1 > populacao2);
                printf("Área: Carta 1 venceu (%d)\n", area1 > area2);
                printf("PIB: Carta 1 venceu (%d)\n", pib1 > pib2);
                printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontos1 > pontos2);
                printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidade1 < densidade2);
                printf("PIB per Capita: Carta 1 venceu (%d)\n", pibPerCapita1 > pibPerCapita2);
                printf("Super Poder: Carta 1 venceu (%d)\n", superPoder1 > superPoder2);
                break;

            case 3:
                printf("\nEncerrando o programa. Até mais!\n");
                break;

            default:
                printf("\n❌ Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}
