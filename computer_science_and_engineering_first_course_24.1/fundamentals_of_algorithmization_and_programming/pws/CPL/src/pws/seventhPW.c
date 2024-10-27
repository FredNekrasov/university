//
// Created by fred on 20.10.2024.
//
#include <stdio.h>
#include <stdlib.h>
#define n 30

struct InformationAboutEnterprises {
    char* name;
    int allEmployees;
    int industrialEmployees;
    int notIndustrialEmployees;
    float notIndustrialEmployeesPercentage;
    float planForEmployees;
} typedef infAboutEnterprises;

infAboutEnterprises* creatingAndFillingIAEs() {
    infAboutEnterprises* enterprises = calloc(n, sizeof(infAboutEnterprises));
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
        enterprises[i].notIndustrialEmployees = enterprises[i].allEmployees - enterprises[i].industrialEmployees;
        enterprises[i].notIndustrialEmployeesPercentage = (float)enterprises[i].notIndustrialEmployees / (float)enterprises[i].allEmployees;
        enterprises[i].planForEmployees = (float)enterprises[i].industrialEmployees / (float)enterprises[i].allEmployees;
    }
    return enterprises;
}
void outputIAE(const infAboutEnterprises enterprise, const int i) {
    printf("| Enterprise %d |", i + 1);
    printf(" name: %s |", enterprise.name);
    printf(" allEmployees: %d |", enterprise.allEmployees);
    printf(" industrialEmployees: %d |\n", enterprise.industrialEmployees);
    printf("| Enterprise %d |", i + 1);
    printf(" notIndustrialEmployees: %d |", enterprise.notIndustrialEmployees);
    printf(" notIndustrialEmployeesPercentage: %.2f |", enterprise.notIndustrialEmployeesPercentage);
    printf(" planForEmployees: %.2f |\n", enterprise.planForEmployees);
    printf("------------------------\n");
}
char* smallestEnterprise(const infAboutEnterprises* enterprises) {
    infAboutEnterprises iae = enterprises[0];
    int iaeIndex = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (enterprises[i].planForEmployees < enterprises[j].planForEmployees) {
                iaeIndex = i;
                iae = enterprises[i];
            }
        }
    }
    outputIAE(iae, iaeIndex);
    return iae.name;
}
int seventhPW3Task() {
    infAboutEnterprises* enterprises = creatingAndFillingIAEs();
    if (enterprises == NULL) {
        free(enterprises);
        return printf("error: enterprises pointer is NULL");
    }
    for (int i = 0; i < n; i++) outputIAE(enterprises[i], i);
    printf("\n");
    int choice = -1;
    char* enterpriseName = enterprises[0].name;
    while (choice != 0) {
        printf("input i: ");
        scanf_s("%d", &choice);
        switch (choice) {
            case 0:// запрашивать нижнюю границу процента выполнения плана по персоналу;
                for (int i = 0; i < n; i++) if (enterprises[i].planForEmployees < 0.5f) outputIAE(enterprises[i], i);
                break;
            case 1:// копировать из исходной в рабочую таблицу строки с процентом выполнения плана по персоналу, большим заданного;
                printf("input i: ");
                scanf_s("%d", &choice);
                break;
            case 2:// выявить предприятие с наименьшей долей непромышленного персонала и запоминать его наименование;
                enterpriseName = smallestEnterprise(enterprises);
                printf("%s\n", enterpriseName);
                break;
            case 3:
                for (int i = 0; i < n; i++) outputIAE(enterprises[i], i);
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
