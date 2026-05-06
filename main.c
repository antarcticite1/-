/*Создать текстовый файл с записями следующего вида:
Иванов Петр Сергеевич 1975
Сидоров Николай Андреевич 1981
….
Воробьянинов Ипполит Матвеевич 1978

	Прочитать данные из этого файла и записать в другой только те строки, которые относятся к родившимся позднее 1980 год*/

#include <stdio.h>
#include <string.h>


int main() {
    FILE *input, *output;
    char line[256];
    char lastname[50], name[50], middlename[50];
    int year;
    
    input = fopen("input.txt", "r");
    output = fopen("result.txt", "w");

    while (fgets(line, sizeof(line), input) != NULL) {
        sscanf(line, "%s %s %s %d", lastname, name, middlename, &year);
        if (year > 1980 && (strcmp(name, "Nikolay") == 0 || strcmp(name, "Alexander") == 0)) {
            fprintf(output, "%s %s %s %d\n", lastname, name, middlename, year);
        }
    }

    fclose(input);
    fclose(output);
    
    return 0;
}
