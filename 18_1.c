#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>



typedef struct {
    char brand[50];        // Марка автомобиля
    char manufacturer[50]; // Производитель
    char type[50];         // Тип
    int year_of_manufacture; // Год выпуска
    int registration_year;   // Год регистрации
} Car;

int main() {
    setlocale(LC_CTYPE, "RUS");
    Car cars[10];
    int num_cars;


    do {
        printf("Введите количество автомобилей (5-10): ");
        scanf("%d", &num_cars);
        if (num_cars < 5 || num_cars > 10) {
            printf("Некорректный ввод! Введите число от 5 до 10.\n");
        }
    } while (num_cars < 5 || num_cars > 10);


    printf("\n=== ВВОД ДАННЫХ ОБ АВТОМОБИЛЯХ ===\n");
    for (int i = 0; i < num_cars; i++) {
        printf("\n--- Автомобиль №%d ---\n", i + 1);

        printf("Марка автомобиля: ");
        scanf("%49s", cars[i].brand);

        printf("Производитель: ");
        scanf("%49s", cars[i].manufacturer);

        printf("Тип (седан, внедорожник, купе и т.д.): ");
        scanf("%49s", cars[i].type);

        printf("Год выпуска: ");
        scanf("%d", &cars[i].year_of_manufacture);

        printf("Год регистрации: ");
        scanf("%d", &cars[i].registration_year);
    }


    printf("\n\n\n=== РЕЗУЛЬТАТЫ ПОИСКА ===\n");
    printf("Автомобили марки 'Toyota', зарегистрированные до 2007 года:\n");
    printf("-------------------------------------------------------------\n");

    int found = 0;

    for (int i = 0; i < num_cars; i++) {
        if (strcmp(cars[i].brand, "Toyota") == 0 && cars[i].registration_year < 2007) {
            printf("\n--- Автомобиль №%d ---\n", i + 1);
            printf("Марка: %s\n", cars[i].brand);
            printf("Производитель: %s\n", cars[i].manufacturer);
            printf("Тип: %s\n", cars[i].type);
            printf("Год выпуска: %d\n", cars[i].year_of_manufacture);
            printf("Год регистрации: %d\n", cars[i].registration_year);
            found++;
        }
    }

    if (found == 0) {
        printf("Автомобили по заданным критериям не найдены.\n");
    }
    else {
        printf("\nНайдено автомобилей: %d\n\n\n", found);
    }

    return 0;
}