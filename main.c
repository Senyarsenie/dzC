#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 100
struct student {
    char z_book[N];
    char s_name[N];
    char name[N];
    char m_name[N];
    char kaf[N];
    char spec[N];
};
struct book {
    long long ISBN;
    char author[N];
    char b_name[N];
    unsigned all_amount;
    unsigned amount;
};
struct user {
    char login[N];
    char pass[N];
    char b_access[N];
    char s_access[N];
};
void  students_menu() {
    printf("\n");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); //руссификатор для записи данных в файл
    setlocale(LC_ALL, "Rus"); //руссификатор для консоли
    FILE* file;

    char str[N];
    int j = 0;
    int i = 0;
    int c = 0;
    char sim[N] = ";";
    char* istr;

    file = fopen("students.csv", "r");                               // подсчет строк
    if (file == NULL) {
        printf("No such file");
        exit(-333);
    }
    while (!feof(file)) {                                         // пока не кончится файл
        if (fgetc(file) == '\n')
            c++;
    }
    c++;

    struct student* st;
    st = (struct student*)malloc(c * sizeof(struct student));
    fclose(file);
    file = fopen("students.csv", "r");
    for (int k = 0; k < (c - 1); k++) {                              //обычно в конце файл заканчивается пустой строкой, если нет, то убрать -1
        fgets(str, N, file);
        istr = strtok(str, sim);
        strncpy(st[k].z_book, istr, N);
        istr = strtok(NULL, sim);
        strncpy(st[k].s_name, istr, N);
        istr = strtok(NULL, sim);
        strncpy(st[k].name, istr, N);
        istr = strtok(NULL, sim);
        strncpy(st[k].m_name, istr, N);
        istr = strtok(NULL, sim);
        strncpy(st[k].kaf, istr, N);
        istr = strtok(NULL, sim);
        strncpy(st[k].spec, istr, N);
        printf("%10s%20s%20s%20s%6s%40s\n", st[k].z_book, st[k].s_name, st[k].name, st[k].m_name, st[k].kaf, st[k].spec);
    }
    fclose(file);
    while (1) {
        printf("\nВыберите операцию:\n1) Добавить студента\n2) Удалить студента по номеру зачетной книжки\n3) Редактировать информацию по студенту\n4) Просмотреть информацию по студенту\n5) Закончить работу\n");
        int choice;
        scanf ("%d", &choice);                 //!!!!!!!
        if (choice == 1) {
            struct student n_str;
            FILE* file2 = fopen("students.csv", "a+");
            char n_z_book[N];
            int req_line = 0;
            int i = 0;
            int k = 0;
            int j = 0;
            if (file2 == NULL) {
                printf("No such file");
                exit(-333);
            }
            printf("\nВведите номер зачетной книжки: ");
            str[0] = getchar();
            str[j] = getchar();
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(n_z_book, str, N);
            j = 0;
            for (k = 0; k < c; k++) {
                if (strcmp(n_z_book, st[k].z_book) == 0) {                // сравнение строк
                    req_line = k + 1;
                }
            }
            if (req_line == 0) {
                strncpy(n_str.z_book, n_z_book, N);
            }
            else {
                printf("Ошибка: Такой номер уже существует.");
                exit(-3);
            }
            printf("\nВведите фамилию студента: ");
            str[j] = getchar();
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(n_str.s_name, str, N);
            j = 0;

            //printf("\n%s", lib[i].author);
            printf("\nВведите имя студента: ");

            str[j] = getchar();
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(n_str.name, str, N);
            j = 0;
            printf("\nВведите отчество студента: ");

            str[j] = getchar();
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(n_str.m_name, str, N);
            j = 0;
            printf("\nВведите факультет: ");

            str[j] = getchar();
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(n_str.kaf, str, N);
            j = 0;
            printf("\nВведите специальность: ");

            str[j] = getchar();
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(n_str.spec, str, N);
            j = 0;

            fprintf(file2, "%s;%s;%s;%s;%s;%s\n", n_str.z_book, n_str.s_name, n_str.name, n_str.m_name, n_str.kaf, n_str.spec);
            fclose(file2);
            c++;
            st = (struct student*)calloc(c, sizeof(struct student));
            fclose(file);
            file = fopen("students.csv", "r");
            for (int k = 0; k < (c - 1); k++) {                              //обычно в конце файл заканчивается пустой строкой, если нет, то убрать -1
                fgets(str, N, file);
                istr = strtok(str, sim);
                strncpy(st[k].z_book, istr, N);
                istr = strtok(NULL, sim);
                strncpy(st[k].s_name, istr, N);
                istr = strtok(NULL, sim);
                strncpy(st[k].name, istr, N);
                istr = strtok(NULL, sim);
                strncpy(st[k].m_name, istr, N);
                istr = strtok(NULL, sim);
                strncpy(st[k].kaf, istr, N);
                istr = strtok(NULL, sim);
                strncpy(st[k].spec, istr, N);
                printf("%10s%20s%20s%20s%6s%40s\n", st[k].z_book, st[k].s_name, st[k].name, st[k].m_name, st[k].kaf, st[k].spec);
            }
            fclose(file);

        }
        else if (choice == 2) {
            file = fopen("students.csv", "w");
            char del_z_book[N];
            int flag = 0;
            i = 0;
            j = 0;
            printf("\nВведите номер зачетной книжки: ");
            str[0] = getchar();
            str[j] = getchar();
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(del_z_book, str, N);
            j = 0;

                for (int k = 0; k < (c - 1); k++) {                       //обычно в конце файл заканчивается пустой строкой, если нет, то убрать -1
                    if (strcmp(del_z_book, st[k].z_book) == 0) {

                        flag = 1;
                    }
                    if (flag == 0)
                        fprintf(file, "%s;%s;%s;%s;%s;%s", st[k].z_book, st[k].s_name, st[k].name, st[k].m_name, st[k].kaf, st[k].spec);
                    flag = 0;
                }
                printf("\nОперация окончена");

        }
        else if (choice == 3) {
file = fopen("students.csv", "w");
            char del_z_book[N];
            int flag = 0;
            i = 0;
            j = 0;
            printf("\nВведите номер зачетной книжки: ");
            str[0] = getchar();
            str[j] = getchar();
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(del_z_book, str, N);
            j = 0;

                for (int k = 0; k < (c - 1); k++) {                       //обычно в конце файл заканчивается пустой строкой, если нет, то убрать -1
                    if (strcmp(del_z_book, st[k].z_book) == 0) {

                        flag = 1;
                    }
                    if (flag == 0)
                        fprintf(file, "%s;%s;%s;%s;%s;%s", st[k].z_book, st[k].s_name, st[k].name, st[k].m_name, st[k].kaf, st[k].spec);
                    flag = 0;
                }
                struct student n_str;
            FILE* file2 = fopen("students.csv", "a+");
            char n_z_book[N];
            int req_line = 0;
            int i = 0;
            int k = 0;
            int j = 0;
            if (file2 == NULL) {
                printf("No such file");
                exit(-333);
            }
            printf("\nВведите номер зачетной книжки: ");
            str[0] = getchar();
            str[j] = getchar();
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(n_z_book, str, N);
            j = 0;
            for (k = 0; k < c; k++) {
                if (strcmp(n_z_book, st[k].z_book) == 0) {                // сравнение строк
                    req_line = k + 1;
                }
            }
            if (req_line == 0) {
                strncpy(n_str.z_book, n_z_book, N);
            }
            else {
                printf("Ошибка: Такой номер уже существует.");
                exit(-3);
            }
            printf("\nВведите фамилию студента: ");
            str[j] = getchar();
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(n_str.s_name, str, N);
            j = 0;

            //printf("\n%s", lib[i].author);
            printf("\nВведите имя студента: ");

            str[j] = getchar();
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(n_str.name, str, N);
            j = 0;
            printf("\nВведите отчество студента: ");

            str[j] = getchar();
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(n_str.m_name, str, N);
            j = 0;
            printf("\nВведите факультет: ");

            str[j] = getchar();
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(n_str.kaf, str, N);
            j = 0;
            printf("\nВведите специальность: ");

            str[j] = getchar();
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(n_str.spec, str, N);
            j = 0;

            fprintf(file2, "%s;%s;%s;%s;%s;%s\n", n_str.z_book, n_str.s_name, n_str.name, n_str.m_name, n_str.kaf, n_str.spec);
            fclose(file2);
            c++;
            st = (struct student*)calloc(c, sizeof(struct student));
            fclose(file);
            file = fopen("students.csv", "r");
            for (int k = 0; k < (c - 1); k++) {                              //обычно в конце файл заканчивается пустой строкой, если нет, то убрать -1
                fgets(str, N, file);
                istr = strtok(str, sim);
                strncpy(st[k].z_book, istr, N);
                istr = strtok(NULL, sim);
                strncpy(st[k].s_name, istr, N);
                istr = strtok(NULL, sim);
                strncpy(st[k].name, istr, N);
                istr = strtok(NULL, sim);
                strncpy(st[k].m_name, istr, N);
                istr = strtok(NULL, sim);
                strncpy(st[k].kaf, istr, N);
                istr = strtok(NULL, sim);
                strncpy(st[k].spec, istr, N);
                printf("%10s%20s%20s%20s%6s%40s\n", st[k].z_book, st[k].s_name, st[k].name, st[k].m_name, st[k].kaf, st[k].spec);
            }
            fclose(file);


        }

        else if (choice == 4) {
printf("\n");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); //руссификатор для записи данных в файл
    setlocale(LC_ALL, "Rus"); //руссификатор для консоли
    FILE* file;

    char str[N];
    int j = 0;
    int i = 0;
    int c = 0;
    char sim[N] = ";";
    char* istr;

    file = fopen("students.csv", "r");                               // подсчет строк
    if (file == NULL) {
        printf("No such file");
        exit(-333);
    }
    while (!feof(file)) {                                         // пока не кончится файл
        if (fgetc(file) == '\n')
            c++;
    }
    c++;

    struct student* st;
    st = (struct student*)malloc(c * sizeof(struct student));
    fclose(file);
    file = fopen("students.csv", "r");
    for (int k = 0; k < (c - 1); k++) {                              //обычно в конце файл заканчивается пустой строкой, если нет, то убрать -1
        fgets(str, N, file);
        istr = strtok(str, sim);
        strncpy(st[k].z_book, istr, N);
        istr = strtok(NULL, sim);
        strncpy(st[k].s_name, istr, N);
        istr = strtok(NULL, sim);
        strncpy(st[k].name, istr, N);
        istr = strtok(NULL, sim);
        strncpy(st[k].m_name, istr, N);
        istr = strtok(NULL, sim);
        strncpy(st[k].kaf, istr, N);
        istr = strtok(NULL, sim);
        strncpy(st[k].spec, istr, N);
        printf("%10s%20s%20s%20s%6s%40s\n", st[k].z_book, st[k].s_name, st[k].name, st[k].m_name, st[k].kaf, st[k].spec);
    }
    fclose(file);
        }
        else if (choice == 5) {
            printf("Завершение работы...\n");
            fclose(file);
            return;
        }
    }
}
void books_menu() {

    while (1) {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251); //руссификатор для записи данных в файл
        setlocale(LC_ALL, "Rus"); //руссификатор для консоли
        FILE* file;

        char str[N];
        int j = 0;
        int i = 0;

        file = fopen("books.csv", "r");                               // подсчет строк
        int c = 0;
        while (!feof(file)) {                                         // пока не кончится файл
            if (fgetc(file) == '\n')
                c++;
        }
        c++;

        struct book* lib;
        lib = (struct book*)malloc(c * sizeof(struct book));
        fclose(file);
        file = fopen("books.csv", "r");

        fscanf(file, "%lld;", &lib[i].ISBN);
        while (lib[i].ISBN > 0) {                                    // изначально записано огромное отрицательное число
            while ((str[j] = fgetc(file)) != '\n') {                 // из-за того, что пробел ломает прогу, пришлось сделать копированием
                if (str[j] == ';') {
                    str[j] = '\0';
                    strncpy(lib[i].author, str, N);                 // копируем содержимое массива
                    j = 0;
                    break; // для fgetc
                }
                else j++;
            }
            while ((str[j] = fgetc(file)) != '\n') { // не EOF потому что на руссколой раскладке "я" на машинном языке = -1 (как и EOF)
                if (str[j] == ';') {
                    str[j] = '\0';
                    strncpy(lib[i].b_name, str, N);
                    j = 0;
                    break;
                }
                else j++;
            }
            fscanf(file, "%u;%u", &lib[i].all_amount, &lib[i].amount);

            printf("%10lld%30s%35s%6u%4u\n", lib[i].ISBN, lib[i].author, lib[i].b_name, lib[i].all_amount, lib[i].amount);

            i++;
            fscanf(file, "%lld;", &lib[i].ISBN); //для перехода на следующую строку. если следующая строка пустая, то цикл прекратится и ничего не выведется
        }

        printf("\nВыберите операцию:\n1) Добавить книгу\n2) Удалить книгу\n3) Просмотр всей информации по книге \n4) Вывести информацию по всем книгам\n5) Завершить программу\n");

        int operation;
        scanf("%d", &operation);
        if (operation == 1) {
            file = fopen("books.csv", "a");
            long long new_ISBN;
            i = 0;
            j = 0;
            printf("\nВведите ISBN: ");
            scanf("%lld", &new_ISBN);
            while (lib[i].ISBN > 0) {
                if (lib[i].ISBN == new_ISBN) {
                    printf("\nТакая книга уже существует");
                    exit(-1);
                }
                else
                    ++i;
                // }
            }
            lib[i].ISBN = new_ISBN;
            printf("\nВведите имя автора: ");
            str[0] = getchar();
            str[j] = getchar();
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(lib[i].author, str, N);
            j = 0;
            printf("\nВведите название книги: ");

            str[j] = getchar();                       // во 2 раз где-то лишний символ
            while (str[j] != '\n') {
                j++;
                str[j] = getchar();
            }
            str[j] = '\0';
            strncpy(lib[i].b_name, str, N);
            j = 0;

            printf("\nВсего книг: ");
            scanf("%u", &lib[i].all_amount);
            printf("\nДоступно книг: ");
            scanf("%u", &lib[i].amount);
                fprintf(file, "%lld;%s;%s;%u;%u\n", lib[i].ISBN, lib[i].author, lib[i].b_name, lib[i].all_amount, lib[i].amount);
                fclose(file);
        }
        else if (operation == 2) {
            file = fopen("books.csv", "w");
            fscanf(file, "%lld;", &lib[i].ISBN);
            long long del_ISBN;
            i = 0;
            j = 0;
            printf("\nВведите ISBN: ");
            scanf("%lld", &del_ISBN);
            printf("\n");
            while (lib[i].ISBN > 0)
                i++;

                for (int k = 0; k < i; k++) {
                    if (lib[k].ISBN != del_ISBN) {
                        fprintf(file, "%lld;%s;%s;%u;%u\n", lib[k].ISBN, lib[k].author, lib[k].b_name, lib[k].all_amount, lib[k].amount);
                    }
                }
                fclose(file);
        }
        else if (operation == 3) {
            file = fopen("books.csv", "r");
            fscanf(file, "%lld;", &lib[i].ISBN);
            long long del_ISBN;
            i = 0;
            j = 0;
            printf("\nВведите ISBN: ");
            scanf("%lld", &del_ISBN);
            printf("\n");
            file = fopen("books.csv", "r");
            fscanf(file, "%lld;", &lib[i].ISBN);
            while (lib[i].ISBN > 0)
                i++;

                for (int k = 0; k < i; k++) {

                    if (lib[k].ISBN == del_ISBN) {
                        printf(file, "%lld;%s;%s;%u;%u\n", lib[k].ISBN, lib[k].author, lib[k].b_name, lib[k].all_amount, lib[k].amount);
                    }
                }
                fclose(file);
        }
        else if (operation == 4) {
                while (lib[i].ISBN > 0) {                                    // изначально записано огромное отрицательное число
            while ((str[j] = fgetc(file)) != '\n') {                 // из-за того, что пробел ломает прогу, пришлось сделать копированием
                if (str[j] == ';') {
                    str[j] = '\0';
                    strncpy(lib[i].author, str, N);                 // копируем содержимое массива
                    j = 0;
                    break; // для fgetc
                }
                else j++;
            }
            while ((str[j] = fgetc(file)) != '\n') { // не EOF потому что на руссколой раскладке "я" на машинном языке = -1 (как и EOF)
                if (str[j] == ';') {
                    str[j] = '\0';
                    strncpy(lib[i].b_name, str, N);
                    j = 0;
                    break;
                }
                else j++;
            }
            fscanf(file, "%u;%u", &lib[i].all_amount, &lib[i].amount);

            printf("%10lld%30s%35s%6u%4u\n", lib[i].ISBN, lib[i].author, lib[i].b_name, lib[i].all_amount, lib[i].amount);

            i++;
            fscanf(file, "%lld;", &lib[i].ISBN); //для перехода на следующую строку. если следующая строка пустая, то цикл прекратится и ничего не выведется
        }
        }
        else if (operation == 5) {

            fclose(file);

            return;
        }
    }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); //руссификатор для записи данных в файл
    setlocale(LC_ALL, "Rus"); //руссификатор для консоли
    FILE* file;

    char str[N];
    int j = 0;
    int i = 0;
    char sim[N] = ";";
    char* istr;

    file = fopen("users.csv", "r");                               // подсчет строк
    int c = 0;
    if (file == NULL) {
        printf("\nNo such file");
        exit(-333);
    }
    while (!feof(file)) {                                         // пока не кончится файл
        if (fgetc(file) == '\n')
            c++;
    }
    c++;

    struct user* usr;
    usr = (struct user*)malloc(c * sizeof(struct user));
    fclose(file);
    file = fopen("users.csv", "r");
    for (int k = 0; k < (c - 1); k++) {                              //обычно в конце файл заканчивается пустой строкой, если нет, то убрать -1
        fgets(str, N, file);
        istr = strtok(str, sim);
        strncpy(usr[k].login, istr, N);
        istr = strtok(NULL, sim);
        strncpy(usr[k].pass, istr, N);
        istr = strtok(NULL, sim);
        strncpy(usr[k].b_access, istr, N);
        istr = strtok(NULL, sim);
        strncpy(usr[k].s_access, istr, N);
        istr = strtok(NULL, sim);
        // fscanf(file, "%d;%d", &usr[k].b_access, &usr[k].s_access);

        printf("%25s%25s%15s%15s\n", usr[k].login, usr[k].pass, usr[k].b_access, usr[k].s_access);
    }
    fclose(file);
    char n_login[N];
    char n_pass[N];
    char b_acc[N];
    char s_acc[N];
    int req_line = 0;
    int k = 0;
    int c1 = c;
    int flag = 0;
    printf("Введите логин: ");
    str[j] = getchar();
    while (str[j] != '\n') {
        j++;
        str[j] = getchar();
    }
    str[j] = '\0';
    strncpy(n_login, str, N);
    j = 0;
    for (int k = 0; k < (c - 1); k++) {
        if (strcmp(n_login, usr[k].login) == 0) {
            req_line = k + 1;
            break;
        }
    }
    if (req_line == 0) {
        printf("\nЛогин введен неверно.");
        exit(-1);
    }
    else {
        req_line--;
        printf("\nВведите пароль: ");
        str[j] = getchar();
        while (str[j] != '\n') {
            j++;
            str[j] = getchar();
        }
        str[j] = '\0';
        strncpy(n_pass, str, N);
        j = 0;
        for (int k = 0; k < (c1 - 1); k++) {
            if (strcmp(n_pass, usr[k].pass) == 0) {
                printf("\nПользователь найден");
                flag = 1;
                strncpy(b_acc, usr[k].b_access, N);
                strncpy(s_acc, usr[k].s_access, N);
            }
        }
        if (flag == 0)
            printf("\nПароль введен неверно");

        if (b_acc[0] == 49 && s_acc[0] == 49) {
            while (1) {
                int n;
                printf("\nВыберите меню:\n1) Книги\n2) Студенты\n3) Выход\n");
                scanf("%d", &n);
                if (n == 1) {
                    books_menu();
                }
                else if (n == 2) {
                    students_menu();
                }
                else if (n == 3) {
                    return 0;
                }
                else if (n != 1 && n != 2 && n != 3) {
                    printf("\nНеверный ввод");
                }
            }
        }
        else if (b_acc[0] == 49) {
            books_menu();
        }
        else if (s_acc[0] == 49) {
            students_menu();
        }
    }

    fclose(file);
}
