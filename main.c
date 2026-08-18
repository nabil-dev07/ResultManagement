#include <stdio.h>
struct studentData
{
    int stid;
    char stname[50];
    float cse103_gp, mat101_gp, eng101_gp;
};
float calculate_CGPA(float cse103, float mat101, float eng101)
{
    return (((cse103 * 4.5) + (mat101 * 3) + (eng101 * 3)) / (4.5 + 3 + 3));
}
int main()
{
    FILE *file1, *file2;
    file1 = fopen("student_input.txt", "r");
    file2 = fopen("output.txt", "w");
    struct studentData stdlist[100];
    int i, n;
    float cgpa;
    if (file1 == NULL)
    {
        printf("Input file not found!");
        return 0;
    }
    if (file2 == NULL)
    {
        printf("Could not create output file!");
        return 0;
    }
    fscanf(file1, "%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(file1, "%d", &stdlist[i].stid);
        fgetc(file1);
        fscanf(file1, "%[^\n]s", stdlist[i].stname);
        fscanf(file1, "%f %f %f", &stdlist[i].cse103_gp, &stdlist[i].mat101_gp, &stdlist[i].eng101_gp);
        if (stdlist[i].cse103_gp > 4.00 || stdlist[i].eng101_gp > 4.00 || stdlist[i].mat101_gp > 4.00)
        {
            printf("Invalid Input found! GPA should be less or equal to 4.00");
        }
    }
    fprintf(file2, "---------------------------------------------------------------------------------------------------\n");
    fprintf(file2, "ID          Name                 CSE103     MAT101     ENG101     CGPA\n");
    fprintf(file2, "---------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        cgpa = calculate_CGPA(stdlist[i].cse103_gp, stdlist[i].mat101_gp, stdlist[i].eng101_gp);
        fprintf(file2, "%-10d  %-20s %-10.2f %-10.2f %-10.2f %-10.2f\n", 
            stdlist[i].stid, stdlist[i].stname, stdlist[i].cse103_gp, stdlist[i].mat101_gp, stdlist[i].eng101_gp, cgpa);
    }
    fprintf(file2, "---------------------------------------------------------------------------------------------------\n");
    printf("Result sheet successfully generated");
    fclose(file1);
    fclose(file2);
    return 0;
}