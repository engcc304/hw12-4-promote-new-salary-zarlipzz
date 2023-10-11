/*
    ผู้บริหารต้องการวิเคราะห์พัฒนาการของพนักงานในบริษัทและศักยภาพของพนักงานจากทักษะที่พัฒนาขึ้นของแต่ละคน ซึ่งแปลงค่าความสามารถของแต่ละคนออกมาเป็นค่า EXP โดยแบ่งอัตราการขึ้นเงินเดือนของแต่ละคนดังนี้
    EXP อยู่ในช่วง 0-1,000 		จะได้รับเงินเดือน x1
	EXP อยู่ในช่วง 1,000-2,000 	จะได้รับเงินเดือน x1.2
	EXP อยู่ในช่วง 2,000-3,000 	จะได้รับเงินเดือน x1.4
	EXP อยู่ในช่วง 3,000-4,000 	จะได้รับเงินเดือน x1.6
	EXP อยู่ในช่วง 4,000-5,000 	จะได้รับเงินเดือน x1.8
	EXP อยู่ในช่วง 5,000 ขึ้นไป	จะได้รับเงินเดือน x2
    โดยผู้บริหารมอบหมายให้ HR เป็นคนกรอกข้อมูลพนักงานในบริษัทและประเมินค่า EXP ของพนักงานแต่ละคน พร้อมสรุปจำนวนคนที่ได้รับเงินเดือนในแต่ละขั้น และระบุคนชื่อคนที่ได้เงินเดือนเยอะที่สุด และคนที่เงินเดือนน้อยที่สุด (หากกรอกเลข -1 ในช่อง Name จะถือเป็นการหยุดโปรแกรมและเตรียมแสดงผล)
    
    Test case:
        Employee 1 Name : 
            Atom
        EXP : 
            2500
        Employee 2 Name : 
            Aom
        EXP : 
            3230
        Employee 3 Name : 
            Aim
        EXP : 
            4560
        Employee 4 Name : 
            Jom
        EXP : 
            5505
        Employee 5 Name : 
            On
        EXP : 
            950
        Employee 6 Name : 
            Oom
        EXP : 
            3500
        Employee 7 Name : 
            Ky
        EXP : 
            2600
        Employee  Name : 
            -1
    Output:
        **** Salary Result ****
        x1.0 count 1
        x1.2 count 0
        x1.4 count 2
        x1.6 count 2
        x1.8 count 1
        x2.0 count 1
        The Employee get x2.0 is Jom
        The Employee get x1.0 is On

    Test case:
        Employee 1 Name : 
            Aey
        EXP : 
            9956
        Employee 2 Name : 
            J
        EXP : 
            4900
        Employee 3 Name : 
            A
        EXP : 
            4560
        Employee 4 Name : 
            Orio
        EXP : 
            200
        Employee 5 Name : 
            Vistra
        EXP : 
            1656
        Employee 6 Name : 
            Oh
        EXP : 
            2300
        Employee  Name : 
            -1
    Output:
        **** Salary Result ****
        x1.0 count 1
        x1.2 count 1
        x1.4 count 1
        x1.6 count 0
        x1.8 count 2
        x2.0 count 1
        The Employee get x2.0 is Aey
        The Employee get x1.0 is Orio
*/

#include <stdio.h>
#include <string.h>

int main() {
    int x1_0_count = 0;
    int x1_2_count = 0;
    int x1_4_count = 0;
    int x1_6_count = 0;
    int x1_8_count = 0;
    int x2_0_count = 0;

    char max_salary_name[50];
    char min_salary_name[50];

    float max_salary = 0;
    float min_salary = 1e9;  // Set to a high initial value

    while (1) {
        char employee_name[50];
        int employee_exp;

        printf("Employee Name (or -1 to exit): ");
        scanf("%s", employee_name);

        if (strcmp(employee_name, "-1") == 0) {
            break;
        }

        printf("EXP: ");
        scanf("%d", &employee_exp);

        float salary;
        if (employee_exp >= 0 && employee_exp < 1000) {
            salary = employee_exp * 1.0;
            x1_0_count++;
        } else if (employee_exp >= 1000 && employee_exp < 2000) {
            salary = employee_exp * 1.2;
            x1_2_count++;
        } else if (employee_exp >= 2000 && employee_exp < 3000) {
            salary = employee_exp * 1.4;
            x1_4_count++;
        } else if (employee_exp >= 3000 && employee_exp < 4000) {
            salary = employee_exp * 1.6;
            x1_6_count++;
        } else if (employee_exp >= 4000 && employee_exp < 5000) {
            salary = employee_exp * 1.8;
            x1_8_count++;
        } else {
            salary = employee_exp * 2.0;
            x2_0_count++;
        }

        if (salary > max_salary) {
            max_salary = salary;
            strcpy(max_salary_name, employee_name);
        }
        if (salary < min_salary) {
            min_salary = salary;
            strcpy(min_salary_name, employee_name);
        }
    }

    printf("**** Salary Result ****\n");
    printf("x1.0 count %d\n", x1_0_count);
    printf("x1.2 count %d\n", x1_2_count);
    printf("x1.4 count %d\n", x1_4_count);
    printf("x1.6 count %d\n", x1_6_count);
    printf("x1.8 count %d\n", x1_8_count);
    printf("x2.0 count %d\n", x2_0_count);
    printf("The Employee get x2.0 is %s\n", max_salary_name);
    printf("The Employee get x1.0 is %s\n", min_salary_name);

    return 0;
}
