//
// Created by fred on 20.10.2024.
//
#include <stdio.h>
#include <stdlib.h>

struct InformationAboutEnterprise {
    char* name;
    int allEmployees;
    int industrialEmployees;
    int notIndustrialEmployees;
    float notIndustrialEmployeesPercentage;
    float planForEmployees;
} typedef infAboutEnterprise;

infAboutEnterprise* creatingAndFillingIAEs(int n) {
    infAboutEnterprise* enterprises = calloc(n, sizeof(infAboutEnterprise));
    if (enterprises == NULL) {
        free(enterprises);
        return nullptr;
    }
    for (int i = 0; i < n; i++) {
        printf("Enterprise %d\n", i + 1);
        printf("name:");
        enterprises[i].name = calloc(20, sizeof(char));
        if (enterprises[i].name == NULL) {
            for (int j = 0; j <= i; j++) free(enterprises[i].name);
            free(enterprises);
            return nullptr;
        }
        scanf_s("%s", enterprises[i].name, 20);
        printf("allEmployees:");
        scanf_s("%d", &enterprises[i].allEmployees);
        printf("industrialEmployees:");
        scanf_s("%d", &enterprises[i].industrialEmployees);
        printf("notIndustrialEmployees:");
        scanf_s("%d", &enterprises[i].notIndustrialEmployees);
        enterprises[i].notIndustrialEmployeesPercentage = (float)enterprises[i].notIndustrialEmployees / (float)enterprises[i].allEmployees;
        enterprises[i].planForEmployees = (float)(enterprises[i].industrialEmployees + enterprises[i].notIndustrialEmployees) / (float)enterprises[i].allEmployees;
    }
    return enterprises;
}
infAboutEnterprise* sortedIAEsByAllEmployees(int n, infAboutEnterprise* enterprises) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (enterprises[i].allEmployees < enterprises[j].allEmployees) {
                infAboutEnterprise temp = enterprises[i];
                enterprises[i] = enterprises[j];
                enterprises[j] = temp;
            }
        }
    }
    return enterprises;
}
void printIAE(const infAboutEnterprise enterprise, const int i) {
    printf("| %d enterprise", i + 1);
    printf(" name: %s\t\t|\n", enterprise.name);
    printf("| allEmployees: %d\t\t\t|\n", enterprise.allEmployees);
    printf("| industrialEmployees: %d\t\t|\n", enterprise.industrialEmployees);
    printf("| notIndustrialEmployees: %d\t\t|\n", enterprise.notIndustrialEmployees);
    printf("| notIndustrialEmployeesPercentage: %.2f|\n", enterprise.notIndustrialEmployeesPercentage);
    printf("| planForEmployees: %.2f\t\t|\n", enterprise.planForEmployees);
    printf("-----------------------------------------\n");
}
char* smallestNotIndustrialEmployeesPercentageEnterprise(const int n, const infAboutEnterprise* enterprises) {
    infAboutEnterprise iae = enterprises[0];
    int iaeIndex = 0;
    for (int i = 1; i < n; i++) {
        if (enterprises[i].notIndustrialEmployeesPercentage < iae.notIndustrialEmployeesPercentage) {
            iae = enterprises[i];
            iaeIndex = i;
        }
    }
    printIAE(iae, iaeIndex);
    return iae.name;
}
void printIAEFilteredByPlanForEmployees(int n, const infAboutEnterprise* enterprises) {
    float planForEmployees = 0;
    printf("input planForEmployees:");
    scanf_s("%f", &planForEmployees);
    for (int i = 0; i < n; i++) {
        if (enterprises[i].planForEmployees >= planForEmployees) printIAE(enterprises[i], i);
    }
}
void printLowerBoundOfPlanForEmployees(int n, const infAboutEnterprise* enterprises) {
    for (int i = 0; i < n; i++) {
        if (enterprises[i].planForEmployees < 0.5f) printIAE(enterprises[i], i);
    }
}
int seventhPW3Task() {
    int n;
    printf("input the number of enterprises:");
    scanf_s("%d", &n);
    if (n <= 0) return printf("error: n <= 0");
    infAboutEnterprise* enterprises = creatingAndFillingIAEs(n);
    if (enterprises == NULL) return printf("error: enterprises pointer is NULL");
    enterprises = sortedIAEsByAllEmployees(n, enterprises);
    for (int i = 0; i < n; i++) printIAE(enterprises[i], i);
    printf("\n");
    int choice = -1;
    char* enterpriseName = smallestNotIndustrialEmployeesPercentageEnterprise(n, enterprises);
    while (choice != 0) {
        printf("1 - lowerBoundOfPlanForEmployees\n2 - printIAEFilteredByPlanForEmployees\n3 - smallestNotIndustrialEmployeesPercentageEnterprise\n4 - print all\n0 - exit\ninput i:");
        scanf_s("%d", &choice);
        switch (choice) {
            case 1:// запрашивать нижнюю границу процента выполнения плана по персоналу;
                printLowerBoundOfPlanForEmployees(n, enterprises);
                break;
            case 2:// копировать из исходной в рабочую таблицу строки с процентом выполнения плана по персоналу, большим заданного;
                printIAEFilteredByPlanForEmployees(n, enterprises);
                break;
            case 3:// выявить предприятие с наименьшей долей непромышленного персонала и запоминать его наименование;
                printf("%s\n", enterpriseName);
                break;
            case 4:
                for (int i = 0; i < n; i++) printIAE(enterprises[i], i);
                break;
            default:
                break;
        }
    }
    free(enterpriseName);
    for (int i = 0; i < n; i++) free(enterprises[i].name);
    free(enterprises);
    return 0;
}