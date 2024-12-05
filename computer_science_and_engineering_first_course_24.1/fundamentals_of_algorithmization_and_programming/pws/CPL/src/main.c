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
infAboutEnterprise8PW* creatingAndFillingIAEs(int n) {
    infAboutEnterprise8PW* enterprises = calloc(n, sizeof(infAboutEnterprise8PW));
    if (enterprises == nullptr) {
        free(enterprises);
        return nullptr;
    }
    for (int i = 0; i < n; i++) {
        printf("Enterprise %d\n", i + 1);
        printf("name:");
        enterprises[i].name = calloc(20, sizeof(char));
        if (enterprises[i].name == nullptr) {
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
void printIAETableHeader() {
    printf("+-----+-----------+-------+-------+------+---------+-----+\n");
    printf("| Num |    Name   |  AE   |  IE   | NIE  | NIE (%) | PFE |\n");
    printf("+-----+-----------+-------+-------+------+---------+-----+\n");
}
void printIAE(const infAboutEnterprise8PW enterprise, const int i) {
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
/*
 * We print the structure if the planForEmployees is greater than or equal to the user input planForEmployees
 */
void printIAEFilteredByPlanForEmployees(int n, const infAboutEnterprise8PW* enterprises) {
    float planForEmployees = 0;
    printf("input planForEmployees (%):");
    scanf_s("%f", &planForEmployees);
    printIAETableHeader();
    for (int i = 0; i < n; i++) {
        if (enterprises[i].planForEmployees >= planForEmployees) printIAE(enterprises[i], i);
    }
}
/*
 * We print the structure if the planForEmployees is less than 50%
 */
void printLowerBoundOfPlanForEmployees(int n, const infAboutEnterprise8PW* enterprises) {
    printIAETableHeader();
    for (int i = 0; i < n; i++) {
        if (enterprises[i].planForEmployees < 50.0f) printIAE(enterprises[i], i);
    }
}
void seventhPWTasks(int n, infAboutEnterprise8PW* enterprises) {
    if (enterprises == nullptr) return;
    int choice = -1;
    char* enterpriseName = smallestNotIndustrialEmployeesPercentageEnterprise(n, enterprises);
    while (choice != 0) {
        printf("Menu for working with enterprises:\n0 - exit\n1 - lowerBoundOfPlanForEmployees\n2 - printIAEFilteredByPlanForEmployees\n3 - smallestNotIndustrialEmployeesPercentageEnterprise\n4 - print all\n0 - exit\ninput i:");
        scanf_s("%d", &choice);
        switch (choice) {
            case 1:
                printLowerBoundOfPlanForEmployees(n, enterprises);
                break;
            case 2:
                printIAEFilteredByPlanForEmployees(n, enterprises);
                break;
            case 3:
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
                printf("| total:\t|\n");
                printf("| %d ", totalEmployees);
                printf("| %d ", totalIndustrialEmployees);
                printf("| %d ", totalNotIndustrialEmployees);
                printf("| %.0f ", totalNotIndustrialEmployeesPercentage);
                printf("| %.0f |\n", totalPlanForEmployees);
                break;
            default:
                break;
        }
    }
    if (enterpriseName != nullptr) free(enterpriseName);
}
int eightPW3Task() {
    int n = 0;
    printf("input the number of enterprises:");
    scanf_s("%d", &n);
    if (n <= 0) return printf("error: n <= 0");
    int choice = -1;
    FILE* file = nullptr;
    infAboutEnterprise8PW* enterprises8PW = nullptr, *enterprises = nullptr;
    while (choice != 0) {
        printf("Menu for working with file:\n0 - exit\n1 - create new/(open existing) file and fill enterprises\n2 - print enterprises\n3 - open new menu\ninput i:");
        scanf_s("%d", &choice);
        switch (choice) {
            case 1:
                enterprises = creatingAndFillingIAEs(n);
                if (enterprises == nullptr) return printf("error: enterprises pointer is NULL");
                enterprises = sortedIAEsByAllEmployees(n, enterprises);
                file = fopen("C:\\Users\\fred\\Downloads\\8PW3Task.bin", "wb+");
                if (file == nullptr) return printf("error: file not found");
                for (int i = 0; i < n; i++) fwrite(&enterprises[i], sizeof(infAboutEnterprise8PW), 1, file);
                break;
            case 2:
                enterprises8PW = calloc(n, sizeof(infAboutEnterprise8PW));
                rewind(file);
                printIAETableHeader();
                for (int i = 0; i < n; i++) {
                    fread(&enterprises8PW[i], sizeof(infAboutEnterprise8PW), 1, file);
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
        if (enterprises != nullptr || enterprises[i].name != nullptr) free(enterprises[i].name);
        if (enterprises8PW != nullptr || enterprises8PW[i].name != nullptr) free(enterprises8PW[i].name);
    }
    if (enterprises != nullptr) free(enterprises);
    if (enterprises8PW != nullptr) free(enterprises8PW);
    if (file != nullptr) fclose(file);
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