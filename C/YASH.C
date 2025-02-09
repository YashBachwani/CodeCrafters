
/*
	Author: Yash Bachwani
	Objective: Student Management
	Team:Code Crafters
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 100

// Structure to store student details
typedef struct {
    int id;
    char name[50];
    int maths, science, english;
    char department[50];
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function to add a student record
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students!\n");
        return;
    }
    printf("Enter Student ID: ");
    scanf("%d", &students[studentCount].id);
    printf("Enter Name: ");
    scanf("%s", students[studentCount].name);
    printf("Enter Maths Marks: ");
    scanf("%d", &students[studentCount].maths);
    printf("Enter Science Marks: ");
    scanf("%d", &students[studentCount].science);
    printf("Enter English Marks: ");
    scanf("%d", &students[studentCount].english);
    printf("Enter Department: ");
    scanf("%s", students[studentCount].department);
    studentCount++;
    printf("Student record added successfully!\n");
}

// Function to display all student records
void displayStudents() {
	int i;
    if (studentCount == 0) {
        printf("No records found!\n");
        return;
    }
    printf("\nStudent Records:\n");
    for (i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Maths: %d, Science: %d, English: %d, Department: %s\n",
               students[i].id, students[i].name, students[i].maths, students[i].science, students[i].english, students[i].department);
    }
}

// Function to search for a student by ID
void searchStudent() {
	int i;
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    for (i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("ID: %d, Name: %s, Maths: %d, Science: %d, English: %d, Department: %s\n",
                   students[i].id, students[i].name, students[i].maths, students[i].science, students[i].english, students[i].department);
            return;
        }
    }
    printf("Student not found!\n");
}

// Function to delete a student record
void deleteStudent() {
	int i, j;
    int id, found = 0;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    for (i = 0; i < studentCount; i++) {
	if (students[i].id == id) {
	    found = 1;
	    for (j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student record deleted successfully!\n");
            return;
        }
    }
    if (!found) printf("Student not found!\n");
}

// Function to update student details
void updateStudent() {
	int i;
    int id;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);
    for (i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Enter new Maths Marks: ");
            scanf("%d", &students[i].maths);
            printf("Enter new Science Marks: ");
            scanf("%d", &students[i].science);
            printf("Enter new English Marks: ");
            scanf("%d", &students[i].english);
            printf("Enter new Department: ");
            scanf("%s", students[i].department);
            printf("Student details updated successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

// Function to count total students
void countStudents() {
    printf("Total number of students: %d\n", studentCount);
}

// Function to find student with highest marks
void highestMarks() {
	int i;
    int highestIndex = 0;
    int highestMarks = students[0].maths + students[0].science + students[0].english;
    if (studentCount == 0) {
        printf("No records found!\n");
        return;
    }
    for (i = 1; i < studentCount; i++) {
        int total = students[i].maths + students[i].science + students[i].english;
        if (total > highestMarks) {
            highestMarks = total;
            highestIndex = i;
        }
    }
    printf("Topper: ID %d, Name %s, Total Marks %d\n", students[highestIndex].id, students[highestIndex].name, highestMarks);
}

// Function to calculate average marks
void averageMarks() {
	int sum = 0;
	int i;
    if (studentCount == 0) {
        printf("No records found!\n");
        return;
    }

    for (i = 0; i < studentCount; i++) {
        sum += students[i].maths + students[i].science + students[i].english;
    }
    printf("Average marks: %.2f\n", (float)sum / (studentCount * 3));
}

// Main function
int main() {
    int choice;
    do {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Delete Student Record\n");
        printf("5. Update Student Details\n");
        printf("6. Find Student with Highest Marks\n");
        printf("7. Count Total Students\n");
        printf("8. Find Average Marks\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: updateStudent(); break;
            case 6: highestMarks(); break;
            case 7: countStudents(); break;
            case 8: averageMarks(); break;
            case 9: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 9);
    return 0;
}