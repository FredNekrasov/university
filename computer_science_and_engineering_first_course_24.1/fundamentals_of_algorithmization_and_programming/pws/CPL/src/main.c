#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define n 3
//
//struct InformationAboutEnterprises {
//    char* name;
//    int allEmployees;
//    int industrialEmployees;
//    int notIndustrialEmployees;
//    float notIndustrialEmployeesPercentage;
//    float planForEmployees;
//} typedef infAboutEnterprises;
//
//infAboutEnterprises* creatingAndFillingIAEs() {
//    infAboutEnterprises* enterprises = calloc(n, sizeof(infAboutEnterprises));
//    if (enterprises == NULL) {
//        free(enterprises);
//        return nullptr;
//    }
//    for (int i = 0; i < n; i++) {
//        printf("Enterprise %d\n", i + 1);
//        printf("name:");
//        enterprises[i].name = calloc(20, sizeof(char));
//        if (enterprises[i].name == NULL) {
//            for (int j = 0; j <= i; j++) free(enterprises[i].name);
//            free(enterprises);
//            return nullptr;
//        }
//        scanf_s("%s", enterprises[i].name, 20);
//        printf("allEmployees:");
//        scanf_s("%d", &enterprises[i].allEmployees);
//        printf("industrialEmployees:");
//        scanf_s("%d", &enterprises[i].industrialEmployees);
//        printf("notIndustrialEmployees:");
//        scanf_s("%d", &enterprises[i].notIndustrialEmployees);
//        enterprises[i].notIndustrialEmployeesPercentage = (float)enterprises[i].notIndustrialEmployees / (float)enterprises[i].allEmployees;
//        enterprises[i].planForEmployees = (float)(enterprises[i].industrialEmployees + enterprises[i].notIndustrialEmployees) / (float)enterprises[i].allEmployees;
//    }
//    return enterprises;
//}
//infAboutEnterprises* sortedIAEsByAllEmployees(infAboutEnterprises* enterprises) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (enterprises[i].allEmployees < enterprises[j].allEmployees) {
//                infAboutEnterprises temp = enterprises[i];
//                enterprises[i] = enterprises[j];
//                enterprises[j] = temp;
//            }
//        }
//    }
//    return enterprises;
//}
//void printIAE(const infAboutEnterprises enterprise, const int i) {
//    printf("| %d enterprise", i + 1);
//    printf(" name: %s\t\t|\n", enterprise.name);
//    printf("| allEmployees: %d\t\t\t|\n", enterprise.allEmployees);
//    printf("| industrialEmployees: %d\t\t|\n", enterprise.industrialEmployees);
//    printf("| notIndustrialEmployees: %d\t\t|\n", enterprise.notIndustrialEmployees);
//    printf("| notIndustrialEmployeesPercentage: %.2f|\n", enterprise.notIndustrialEmployeesPercentage);
//    printf("| planForEmployees: %.2f\t\t|\n", enterprise.planForEmployees);
//    printf("-----------------------------------------\n");
//}
//char* smallestEnterprise(const infAboutEnterprises* enterprises) {
//    infAboutEnterprises iae = enterprises[0];
//    int iaeIndex = 0;
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (enterprises[i].planForEmployees < enterprises[j].planForEmployees) {
//                iaeIndex = i;
//                iae = enterprises[i];
//            }
//        }
//    }
//    printIAE(iae, iaeIndex);
//    return iae.name;
//}
//void printIAEFilteredByPlanForEmployees(const infAboutEnterprises* enterprises) {
//    float planForEmployees = 0;
//    printf("input planForEmployees:");
//    scanf_s("%f", &planForEmployees);
//    for (int i = 0; i < n; i++) {
//        if (enterprises[i].planForEmployees >= planForEmployees) printIAE(enterprises[i], i);
//    }
//}
//void printLowerBoundOfPlanForEmployees(const infAboutEnterprises* enterprises) {
//    for (int i = 0; i < n; i++) {
//        if (enterprises[i].planForEmployees < 0.5f) printIAE(enterprises[i], i);
//    }
//}
//int seventhPW3Task() {
//    infAboutEnterprises* enterprises = creatingAndFillingIAEs();
//    if (enterprises == NULL) {
//        for (int i = 0; i < n; i++) free(enterprises[i].name);
//        free(enterprises);
//        return printf("error: enterprises pointer is NULL");
//    }
//    enterprises = sortedIAEsByAllEmployees(enterprises);
//    for (int i = 0; i < n; i++) printIAE(enterprises[i], i);
//    printf("\n");
//    int choice = -1;
//    char* enterpriseName = smallestEnterprise(enterprises);
//    while (choice != 0) {
//        printf("input i:");
//        scanf_s("%d", &choice);
//        switch (choice) {
//            case 1:// запрашивать нижнюю границу процента выполнения плана по персоналу;
//                printLowerBoundOfPlanForEmployees(enterprises);
//                break;
//            case 2:// копировать из исходной в рабочую таблицу строки с процентом выполнения плана по персоналу, большим заданного;
//                printIAEFilteredByPlanForEmployees(enterprises);
//                break;
//            case 3:// выявить предприятие с наименьшей долей непромышленного персонала и запоминать его наименование;
//                printf("%s\n", enterpriseName);
//                break;
//            case 4:
//                for (int i = 0; i < n; i++) printIAE(enterprises[i], i);
//                break;
//            default:
//                break;
//        }
//    }
//    free(enterpriseName);
//    for (int i = 0; i < n; i++) free(enterprises[i].name);
//    free(enterprises);
//    return 0;
//}
int main() {
    printf("Hello, World!\n");
    return 0;
}

void independentWork() {
    float y = 0;
    for (int a = 1; a <= 3; a += 1) {
        double maxY = -1 * exp(24);
        double maxX = 0;
        double minY = exp(24);
        double minX = 0;
        printf("a = %d\n", a);
        for (double x = 0.5; x < 3.5; x += 0.5) {
            y = sin(x) + fabs(x) + pow(2, x);
            printf("x = %.2f, y = %.2f\n", x, y);
            if (y > maxY) {
                maxY = y;
                maxX = x;
            }
            if (y < minY) {
                minY = y;
                minX = x;
            }
        }
        printf("maxX = %.2f, maxY = %.2f\nminX = %.2f, minY = %.2f\n", maxX, maxY, minX, minY);
    }
}