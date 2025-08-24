#include <stdio.h>

int main() {
  char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nome1[50], nome2[50];
    unsigned long int populacao1, populacao2; 
    float area1, area2;
    float pib1, pib2;
    int pontos1, pontos2;

    printf("Digite os dados da primeira carta:\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Código da carta (ex: A01): ");
    scanf("%3s", codigo1);

    printf("Nome da cidade: ");
    getchar();  
    fgets(nome1, 50, stdin);

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

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (km²): ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    printf("Número de pontos turísticos: ");
    scanf("%d", &pontos2);

    
    float densidade1 = populacao1 / area1;
    float pibPerCapita1 = pib1 / populacao1;

    
    float densidade2 = populacao2 / area2;
    float pibPerCapita2 = pib2 / populacao2;

    
    float superPoder1 = (float)populacao1 + area1 + pib1 + (float)pontos1 + pibPerCapita1 + (1.0f / densidade1);
    float superPoder2 = (float)populacao2 + area2 + pib2 + (float)pontos2 + pibPerCapita2 + (1.0f / densidade2);

    

    int popVence = (populacao1 > populacao2) ? 1 : 0;
    int areaVence = (area1 > area2) ? 1 : 0;
    int pibVence = (pib1 > pib2) ? 1 : 0;
    int pontosVence = (pontos1 > pontos2) ? 1 : 0;
    int densidadeVence = (densidade1 < densidade2) ? 1 : 0;
    int pibPerCapitaVence = (pibPerCapita1 > pibPerCapita2) ? 1 : 0;
    int superPoderVence = (superPoder1 > superPoder2) ? 1 : 0;

    printf("\nComparação de Cartas:\n\n");
    printf("População: Carta 1 venceu (%d)\n", popVence);
    printf("Área: Carta 1 venceu (%d)\n", areaVence);
    printf("PIB: Carta 1 venceu (%d)\n", pibVence);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontosVence);
    printf("Densidade Populacional: Carta 2 venceu (%d)\n", densidadeVence ? 0 : 1); 
   
    if (densidadeVence)
        printf("Densidade Populacional: Carta 1 venceu (1)\n");
    else
        printf("Densidade Populacional: Carta 2 venceu (0)\n");
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pibPerCapitaVence);
    printf("Super Poder: Carta 1 venceu (%d)\n", superPoderVence);

    return 0;
}

    
