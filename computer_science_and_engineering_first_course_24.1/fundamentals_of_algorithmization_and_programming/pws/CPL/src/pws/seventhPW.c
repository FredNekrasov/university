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
/*
 * First, we allocate memory for n elements of the structure, then we check if the allocation was successful.
 * If it was not successful, we free the memory and return NULL.
 * Then, we fill the structure with user input.
 * if the input of the name is not successful, we free the memory and return NULL.
 *
 * notIndustrialEmployeesPercentage and planForEmployees are calculated using allEmployees, industrialEmployees and notIndustrialEmployees.
 * notIndustrialEmployeesPercentage is a percentage of notIndustrialEmployees to allEmployees, and planForEmployees is a percentage of industrialEmployees and notIndustrialEmployees to allEmployees.
 *
 * After that, we return the pointer to the structure.
 */
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
        enterprises[i].notIndustrialEmployeesPercentage = ((float)enterprises[i].notIndustrialEmployees / (float)enterprises[i].allEmployees) * 100;
        enterprises[i].planForEmployees = ((float)(enterprises[i].industrialEmployees + enterprises[i].notIndustrialEmployees) / (float)enterprises[i].allEmployees) * 100;
    }
    return enterprises;
}
/*
 * We sort the structure by allEmployees in descending order using bubble sort.
 * After that, we return the pointer to the structure.
 */
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
void printIAETableHeader() {
    printf("+-----+-----------+-------+-------+------+---------+-----+\n");
    printf("| Num |    Name   |  AE   |  IE   | NIE  | NIE (%) | PFE |\n");
    printf("+-----+-----------+-------+-------+------+---------+-----+\n");
}
void printIAE(const infAboutEnterprise enterprise, const int i) {
    printf("| %-3d | %s ", i + 1, enterprise.name);
    printf("| %d ", enterprise.allEmployees);
    printf("| %d ", enterprise.industrialEmployees);
    printf("| %d ", enterprise.notIndustrialEmployees);
    printf("|    %.0f   ", enterprise.notIndustrialEmployeesPercentage);
    printf("|  %.0f |\n", enterprise.planForEmployees);
    printf("+-----+-----------+-------+-------+------+---------+-----+\n");
}
/*
 * We return the name of the enterprise with the smallest notIndustrialEmployeesPercentage
 * After that, we print the structure
 */
char* smallestNotIndustrialEmployeesPercentageEnterprise(const int n, const infAboutEnterprise* enterprises) {
    infAboutEnterprise iae = enterprises[0];
    for (int i = 1; i < n; i++) {
        if (enterprises[i].notIndustrialEmployeesPercentage < iae.notIndustrialEmployeesPercentage) iae = enterprises[i];
    }
    return iae.name;
}
/*
 * We print the structure if the planForEmployees is greater than or equal to the user input planForEmployees
 */
void printIAEFilteredByPlanForEmployees(int n, const infAboutEnterprise* enterprises) {
    float planForEmployees = 0;
    printf("input planForEmployees:");
    scanf_s("%f", &planForEmployees);
    printIAETableHeader();
    for (int i = 0; i < n; i++) {
        if (enterprises[i].planForEmployees >= planForEmployees) printIAE(enterprises[i], i);
    }
}
/*
 * We print the structure if the planForEmployees is less than 50%
 */
void printLowerBoundOfPlanForEmployees(int n, const infAboutEnterprise* enterprises) {
    for (int i = 0; i < n; i++) {
        if (enterprises[i].planForEmployees < 50.0f) printIAE(enterprises[i], i);
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
    printIAETableHeader();
    for (int i = 0; i < n; i++) printIAE(enterprises[i], i);
    printf("\n");
    int choice = -1;
    char* enterpriseName = smallestNotIndustrialEmployeesPercentageEnterprise(n, enterprises);
    while (choice != 0) {
        printf("1 - lowerBoundOfPlanForEmployees\n2 - printIAEFilteredByPlanForEmployees\n3 - smallestNotIndustrialEmployeesPercentageEnterprise\n4 - print all\n0 - exit\ninput i:");
        scanf_s("%d", &choice);
        switch (choice) {
            case 1:// запрашивать нижнюю границу процента выполнения плана по персоналу;
                printIAETableHeader();
                printLowerBoundOfPlanForEmployees(n, enterprises);
                break;
            case 2:// копировать из исходной в рабочую таблицу строки с процентом выполнения плана по персоналу, большим заданного;
                printIAEFilteredByPlanForEmployees(n, enterprises);
                break;
            case 3:// выявить предприятие с наименьшей долей непромышленного персонала и запоминать его наименование;
                printf("%s\n", enterpriseName);
                break;
            case 4:
                printIAETableHeader();
                int totalEmployees = 0, totalIndustrialEmployees = 0, totalNotIndustrialEmployees = 0;
                for (int i = 0; i < n; i++) {
                    printIAE(enterprises[i], i);
                    totalEmployees += enterprises[i].allEmployees;
                    totalIndustrialEmployees += enterprises[i].industrialEmployees;
                    totalNotIndustrialEmployees += enterprises[i].notIndustrialEmployees;
                }
                float totalNotIndustrialEmployeesPercentage = ((float)totalNotIndustrialEmployees / (float)totalEmployees) * 100;
                float totalPlanForEmployees = ((float)(totalIndustrialEmployees + totalNotIndustrialEmployees) / (float)totalEmployees) * 100;
                printf("\n\n");
                printf("| total:\t\t|\n");
                printf("| %d ", totalEmployees);
                printf("| %d ", totalIndustrialEmployees);
                printf("| %d ", totalNotIndustrialEmployees);
                printf("| %.0f ", totalNotIndustrialEmployeesPercentage);
                printf("| %.0f |\n", totalPlanForEmployees);
                break;
            default:
                printf("bye bye!");
                break;
        }
    }
    if (enterpriseName != NULL) free(enterpriseName);
    for (int i = 0; i < n; i++) {
        if (enterprises[i].name != NULL) free(enterprises[i].name);
    }
    free(enterprises);
    return 0;
}