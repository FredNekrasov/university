#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * https://proproprogs.ru/c_base/c_faylovye-funkcii-fopen-fclose-fgetc-fputc
 * https://www.geeksforgeeks.org/c-fopen-function-with-examples/
 * https://www.geeksforgeeks.org/read-write-structure-from-to-a-file-in-c/
 */
struct InformationAboutEnterprise8PW {
    char* name;
    int allEmployees;
    int industrialEmployees;
    int notIndustrialEmployees;
    float notIndustrialEmployeesPercentage;
    float planForEmployees;
} typedef infAboutEnterprise8PW;

infAboutEnterprise8PW* creatingAndFillingIAEs(int n) {
    infAboutEnterprise8PW* enterprises = calloc(n, sizeof(infAboutEnterprise8PW));
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
infAboutEnterprise8PW* sortedIAEsByAllEmployees(int n, infAboutEnterprise8PW* enterprises) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (enterprises[i].allEmployees < enterprises[j].allEmployees) {
                infAboutEnterprise8PW temp = enterprises[i];
                enterprises[i] = enterprises[j];
                enterprises[j] = temp;
            }
        }
    }
    return enterprises;
}
void printIAE(const infAboutEnterprise8PW enterprise, const int i) {
    printf("| %d enterprise name: %s\t\t|\n", i + 1, enterprise.name);
    printf("| allEmployees: %d\t\t\t|\n", enterprise.allEmployees);
    printf("| industrialEmployees: %d\t\t|\n", enterprise.industrialEmployees);
    printf("| notIndustrialEmployees: %d\t\t|\n", enterprise.notIndustrialEmployees);
    printf("| notIndustrialEmployeesPercentage: %.2f|\n", enterprise.notIndustrialEmployeesPercentage);
    printf("| planForEmployees: %.2f\t\t|\n", enterprise.planForEmployees);
    printf("-----------------------------------------\n");
}
char* smallestNotIndustrialEmployeesPercentageEnterprise(const int n, const infAboutEnterprise8PW* enterprises) {
    infAboutEnterprise8PW iae = enterprises[0];
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
void printIAEFilteredByPlanForEmployees(int n, const infAboutEnterprise8PW* enterprises) {
    float planForEmployees = 0;
    printf("input planForEmployees:");
    scanf_s("%f", &planForEmployees);
    for (int i = 0; i < n; i++) {
        if (enterprises[i].planForEmployees >= planForEmployees) printIAE(enterprises[i], i);
    }
}
void printLowerBoundOfPlanForEmployees(int n, const infAboutEnterprise8PW* enterprises) {
    for (int i = 0; i < n; i++) {
        if (enterprises[i].planForEmployees < 0.5f) printIAE(enterprises[i], i);
    }
}
void seventhPWTasks(int n, infAboutEnterprise8PW* enterprises) {
    int choice = -1;
    char* enterpriseName = smallestNotIndustrialEmployeesPercentageEnterprise(n, enterprises);
    while (choice != 0) {
        printf("Menu for working with enterprises:\n0 - exit\n1 - lowerBoundOfPlanForEmployees\n2 - printIAEFilteredByPlanForEmployees\n3 - smallestNotIndustrialEmployeesPercentageEnterprise\n4 - print all\n0 - exit\ninput i:");
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
}
int eightPW3Task() {
    int n = 0;
    printf("input the number of enterprises:");
    scanf_s("%d", &n);
    if (n <= 0) return printf("error: n <= 0");
    int choice = -1;
    FILE* file = nullptr;
    infAboutEnterprise8PW* enterprises8PW, *enterprises = nullptr;
    while (choice != 0) {
        printf("Menu for working with file:\n0 - exit\n1 - create new/(open existing) file and fill enterprises\n2 - print enterprises\n3 - open new menu\ninput i:");
        scanf_s("%d", &choice);
        switch (choice) {
            case 1:
                enterprises = creatingAndFillingIAEs(n);
                if (enterprises == NULL) return printf("error: enterprises pointer is NULL");
                enterprises = sortedIAEsByAllEmployees(n, enterprises);
                file = fopen("C:\\Users\\fred\\Downloads\\8PW3Task.dat", "ab+");
                if (file == NULL) return printf("error: file not found");
                for (int i = 0; i < n; i++) fwrite(&enterprises[i], sizeof(enterprises[i]), 1, file);
                break;
            case 2:
                enterprises8PW = calloc(n, sizeof(infAboutEnterprise8PW));
                rewind(file);
                for (int i = 0; i < n; i++) {
                    fread(&enterprises8PW[i], sizeof(enterprises8PW[i]), 1, file);
                    printIAE(enterprises8PW[i], i);
                }
                break;
            case 3:
                seventhPWTasks(n, enterprises8PW);
                break;
            default:
                printf("Bye Bye!\n");
                break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (enterprises[i].name != NULL) free(enterprises[i].name);
        if (enterprises8PW[i].name != NULL) free(enterprises8PW[i].name);
    }
    if (enterprises != NULL) free(enterprises);
    if (enterprises8PW != NULL) free(enterprises8PW);
    if (file != NULL) fclose(file);
    if (file != NULL) free(file);
    return 0;
}

int main() {
    printf("Hello, World!\n");
    eightPW3Task();
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