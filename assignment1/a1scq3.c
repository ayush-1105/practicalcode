#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[100];
    float salary;
} Employee;

// Function to accept employee details
void acceptEmployeeDetails(Employee *employee) {
    printf("Enter Employee ID: ");
    scanf("%d", &employee->id);
    printf("Enter Employee Name: ");
    scanf(" %[^\n]", employee->name); // Read string with spaces
    printf("Enter Employee Salary: ");
    scanf("%f", &employee->salary);
}

// Function to search employee by name
void searchEmployeeByName(Employee *employees, int n, const char *name) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(employees[i].name, name) == 0) {
            printf("Employee found: ID=%d, Name=%s, Salary=%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with name '%s' not found.\n", name);
    }
}

// Function to search employee by ID
void searchEmployeeById(Employee *employees, int n, int id) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (employees[i].id == id) {
            printf("Employee found: ID=%d, Name=%s, Salary=%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee with ID '%d' not found.\n", id);
    }
}

// Function to display all employees
void displayAllEmployees(Employee *employees, int n) {
    printf("\nAll Employees:\n");
    printf("%-10s %-30s %-10s\n", "ID", "Name", "Salary");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-30s %-10.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}

// Function to display employees with salary greater than a specified amount
void displayEmployeesWithSalaryGreaterThan(Employee *employees, int n, float amount) {
    printf("\nEmployees with Salary greater than %.2f:\n", amount);
    printf("%-10s %-30s %-10s\n", "ID", "Name", "Salary");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (employees[i].salary > amount) {
            printf("%-10d %-30s %-10.2f\n", employees[i].id, employees[i].name, employees[i].salary);
            found = 1;
        }
    }
    if (!found) {
        printf("No employees found with salary greater than %.2f.\n", amount);
    }
}

// Function to display employee with maximum salary
void displayEmployeeWithMaximumSalary(Employee *employees, int n) {
    if (n == 0) {
        printf("No employees to display.\n");
        return;
    }
    
    Employee maxSalaryEmployee = employees[0];
    for (int i = 1; i < n; i++) {
        if (employees[i].salary > maxSalaryEmployee.salary) {
            maxSalaryEmployee = employees[i];
        }
    }
    printf("\nEmployee with Maximum Salary:\n");
    printf("ID=%d, Name=%s, Salary=%.2f\n", maxSalaryEmployee.id, maxSalaryEmployee.name, maxSalaryEmployee.salary);
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n employees
    Employee *employees = (Employee *)malloc(n * sizeof(Employee));
    if (employees == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Accepting details for n employees
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);
        acceptEmployeeDetails(&employees[i]);
    }

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Search employee by name\n");
        printf("2. Search employee by ID\n");
        printf("3. Display all employees\n");
        printf("4. Display employees having salary greater than a specific amount\n");
        printf("5. Display employee with maximum salary\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char name[100];
            printf("Enter employee name to search: ");
            scanf(" %[^\n]", name);
            searchEmployeeByName(employees, n, name);
        } else if (choice == 2) {
            int id;
            printf("Enter employee ID to search: ");
            scanf("%d", &id);
            searchEmployeeById(employees, n, id);
        } else if (choice == 3) {
            displayAllEmployees(employees, n);
        } else if (choice == 4) {
            float amount;
            printf("Enter salary amount: ");
            scanf("%f", &amount);
            displayEmployeesWithSalaryGreaterThan(employees, n, amount);
        } else if (choice == 5) {
            displayEmployeeWithMaximumSalary(employees, n);
        } else if (choice != 6) {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    // Free allocated memory
    free(employees);
    
    return 0;
}
