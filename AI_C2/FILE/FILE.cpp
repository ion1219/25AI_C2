#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    char* name;
    int atk;
    int def;
    int hp;
};

int main()
{
    const char* filename = "students.csv";
    
    FILE* fp = NULL;
    FILE* txt = NULL;

    fopen_s(&fp, filename, "r");
    fopen_s(&txt, "text.txt", "w");

    if (fp == NULL)
    {
        printf("error_1");

        return 1;
    }

    char buffer[256];
    char* tokken;
    char* tokken_ = NULL;
    student studentInfo[11];

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        int i = 0;
        tokken = strtok_s(buffer, ",", &tokken_);
        studentInfo[i].name = tokken;
        tokken = strtok_s(NULL, ",", &tokken_);
        studentInfo[i].atk = atoi(tokken);
        tokken = strtok_s(NULL, ",", &tokken_);
        studentInfo[i].def = atoi(tokken);
        tokken = strtok_s(NULL, ",", &tokken_);
        studentInfo[i].hp = atoi(tokken);
    }

    int studentNumber;
    char* studentName = {};

    scanf_s("%d %s", &studentNumber, studentName);

    fclose(fp);
    fclose(txt);

}
