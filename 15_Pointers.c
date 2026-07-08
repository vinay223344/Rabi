/*
 ============================================================================
 Name        : 15_Pointers.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* 1. Write a C program to check whether a pair of numbers is amicable or not, using pointers.
Example: 220 & 284 are amicable numbers then the factors of 220:1, 2, 4, 5, 10, 11, 20, 22, 44, 55, 110
then 1+ 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110 = 284 and Now, 284: 1, 2, 4, 71, 142 1 + 2 + 4 + 71 + 142 = 220.
*/
void sumOfDivisors(int *num, int *sum)
{
    *sum = 0;
    for (int i=1; i<=(*num/2); i++)
    {
        if (*num%i == 0)
        {
            *sum += i;
        }
    }
}
void amicable_numbers()
{
    int a, b;
    int sumA = 0, sumB = 0;
    int *A = &a;
    int *B = &b;
    printf("Enter two numbers: ");
    scanf("%d %d", A, B);
    sumOfDivisors(A, &sumA);
    sumOfDivisors(B, &sumB);
    printf("Sum of divisors of %d = %d\n", *A, sumA);
    printf("Sum of divisors of %d = %d\n", *B, sumB);
    if (sumA == *B && sumB == *A)
    {
        printf("The numbers %d and %d are AMICABLE.\n", *A, *B);
    }
    else
    {
        printf("The numbers %d and %d are NOT amicable.\n", *A, *B);
    }
}
/* Output:  Enter two numbers: 12 24
			Sum of divisors of 12 = 16
			Sum of divisors of 24 = 36
			The numbers 12 and 24 are NOT amicable.
			Enter two numbers: 220 284
			Sum of divisors of 220 = 284
			Sum of divisors of 284 = 220
			The numbers 220 and 284 are AMICABLE.
*/

/* 2. Write a C program to perform basic arithmetic operations (addition, subtraction, multiplication, division) using an array of function pointers. */
float add(float a, float b) { return a + b; }
float sub(float a, float b) { return a - b; }
float mul(float a, float b) { return a * b; }
float divide(float a, float b)
{
    if (b != 0) return a / b;
    else
    {
        printf("Error: Division by zero!\n");
        return 0;
    }
}

void arithmetic_operations()
{
    float a, b;
    int choice;
    float (*op[4])(float, float) = {add, sub, mul, divide};
    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);
    printf("Select Operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    while(1)
    {
		printf("Enter choice: ");
		scanf("%d", &choice);
		if (choice >= 1 && choice < 5)
		{
			float result = op[choice-1](a, b);
			printf("Result = %.2f\n", result);
		}
		else
		{
			printf("Invalid choice!\n");
		}
    }
}
/* Output:  Enter two numbers: 5 2
			Select Operation:
			1. Addition
			2. Subtraction
			3. Multiplication
			4. Division
			Enter choice: 1
			Result = 7.00
			Enter choice: 2
			Result = 3.00
			Enter choice: 3
			Result = 10.00
			Enter choice: 4
			Result = 2.50
*/

/* 3. Write a C program to calculate the volume of the following shapes:
	• Cube
	• Cuboid
	• Sphere
	• Cylinder
	• Cone.
	Let the user select a shape, input dimensions in main(), and call shape-specific
	functions (using appropriate parameters) to compute the volume by using pointers.
*/
#define PI 3.1415
void cube(float *side, float *vol)
{
    *vol = (*side) * (*side) * (*side);
}
void cuboid(float *l, float *b, float *h, float *vol)
{
    *vol = (*l) * (*b) * (*h);
}
void sphere(float *r, float *vol)
{
    *vol = (4.0/3) * PI * (*r) * (*r) * (*r);
}
void cylinder(float *r, float *h, float *vol)
{
    *vol = PI * (*r) * (*r) * (*h);
}
void cone(float *r, float *h, float *vol)
{
    *vol = (1.0/3) * PI * (*r) * (*r) * (*h);
}
void volume_calculator()
{
    int choice;
    float side, l, b, h, r;
    float volume;
    printf("Volume Calculator Using Pointers\n");
    printf("1. Cube\n");
    printf("2. Cuboid\n");
    printf("3. Sphere\n");
    printf("4. Cylinder\n");
    printf("5. Cone\n");
    while(1)
    {
    	printf("Enter your choice: ");
    	scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				printf("Enter side: ");
				scanf("%f", &side);
				cube(&side, &volume);
				break;
			case 2:
				printf("Enter length, breadth, height: ");
				scanf("%f %f %f", &l, &b, &h);
				cuboid(&l, &b, &h, &volume);
				break;
			case 3:
				printf("Enter radius: ");
				scanf("%f", &r);
				sphere(&r, &volume);
				break;
			case 4:
				printf("Enter radius and height: ");
				scanf("%f %f", &r, &h);
				cylinder(&r, &h, &volume);
				break;
			case 5:
				printf("Enter radius and height: ");
				scanf("%f %f", &r, &h);
				cone(&r, &h, &volume);
				break;
			default: printf("Invalid choice!\n");
		}
		printf("Volume = %.2f\n", volume);
    }
}
/* Output:  Volume Calculator Using Pointers
			1. Cube
			2. Cuboid
			3. Sphere
			4. Cylinder
			5. Cone
			Enter your choice: 1
			Enter side: 5
			Volume = 125.00
			Enter your choice: 2
			Enter length, breadth, height: 5 6 3
			Volume = 90.00
			Enter your choice: 3
			Enter radius: 5
			Volume = 523.58
			Enter your choice: 4
			Enter radius and height: 5 6
			Volume = 471.23
			Enter your choice: 5
			Enter radius and height: 5 6
			Volume = 157.07
*/

/* 4. Write a program in C to print all permutations of a given string using pointers.
   Expected Output:
   The permutations of the string are:
   abcd abdc acbd acdb adbc adcb bacd badc bcad bcda bdac bdca cdad cbda cabd cadb cdba dbca dbac dcba dcab dacb dabc
*/
void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void permutate(char *str, int left, int right)
{
    int i;
    if (left == right)
    {
        printf("%s  ", str);
    }
    else
    {
        for (i = left; i <= right; i++)
        {
            swap(str + left, str + i);
            permutate(str, left + 1, right);
            swap(str + left, str + i);
        }
    }
}
void permutations()
{
	char str[10];
	printf("Enter a string: ");
	scanf("%s", str);
	printf("The permutations of the string are :\n");
	permutate(str, 0, strlen(str) - 1);
}
/* Output: Enter a string: abcd
The permutations of the string are :
abcd  abdc  acbd  acdb  adcb  adbc  bacd  badc  bcad  bcda  bdca  bdac  cbad  cbda  cabd  cadb  cdab  cdba  dbca  dbac  dcba  dcab  dacb  dabc
*/

/* 5. Write a C program to input n numbers using dynamic memory allocation and find the largest element using a pointer. */
void largest_element()
{
    int n, max, *arr, *i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for (i = arr; i < arr + n; i++)
    {
        scanf("%d", i);
    }
    max = *arr;
    for (i=arr; i<arr+n; i++)
    {
        if (*i > max)
        {
            max = *i;
        }
    }
    printf("Largest element = %d\n", max);
    free(arr);
}
/* Output:  Enter the number of elements: 5
			Enter the elements: 1 8 5 3 19
			Largest element = 19
*/

/* 6. Write a C program to calculate the length of a string using a pointer? */
void string_length()
{
	char str[50];
	char *ptr;
	int length = 0;
	printf("Enter a string: ");
	scanf("%s", str);
	ptr = str;
	while(*ptr != '\0')
	{
		length++;
		ptr++;
	}
	printf("Length of the string '%s' is %d\n", str, length);
}
/* Output: Enter a string: Mokshagna
		   Length of the string 'Mokshagna' is 9
*/

/* 7. Write a C program to count and print the number of vowels and consonants in a string using a pointer? */
void vowel_consonant()
{
	char str[50], *ptr;
	printf("Enter a string: ");
	scanf("%s", str);
	ptr=str;
	int vowels = 0, consonants = 0;
	while(*ptr != '\0')
	{
		char ch = *ptr;
		if(ch == 'a' || ch == 'A' ||
		   ch == 'e' || ch == 'E' ||
		   ch == 'i' || ch == 'I' ||
		   ch == 'o' || ch == 'O' ||
		   ch == 'u' || ch == 'U')
		{
			vowels++;
		}
		else
		{
			consonants++;
		}
		ptr++;
	}
	printf("No. of vowels: %d\n", vowels);
	printf("No. of consonants: %d\n", consonants);
}
/* Output:  Enter a string: Mokshagna
			No. of vowels: 3
			No. of consonants: 6
*/

/* 8. Write a C program to print all the alphabets (both upper and lower case) using a pointer? */
void alphabets()
{
	char ch;
	int *ptr;
	printf("Uppercase Alphabets:\n");
	for (ch = 'A'; ch <= 'Z'; ch++)
	{
	    ptr = &ch;
	    printf("%c ", *ptr);
	}
	printf("\nLowercase Alphabets:\n");
	for (ch = 'a'; ch <= 'z'; ch++)
	{
	    ptr = &ch;
	    printf("%c ", *ptr);
	}
	printf("\n");
}

/* 9. Write a C program to accept a string and check whether it is a palindrome or not using pointers. */
void palindrome()
{
	 char str[100];
	 char *start, *end;
	 int flag = 1;
	 printf("Enter a string: ");
	 scanf("%s", str);
	 start = str;
	 end = str + strlen(str) - 1;
	 while (start < end)
	 {
	     if (*start != *end)
	     {
	         flag = 0;
	         break;
	     }
	     start++;
	     end--;
	 }
     if (flag)
	     printf("The string is a palindrome.\n");
	 else
	     printf("The string is not a palindrome.\n");
}

/* 10. Write a C program to dynamically allocate a 2D array using an array of pointers. */
void twod_array()
{
	int rows, cols, i, j;
   	int **arr;
	printf("Enter number of rows and columns: ");
	scanf("%d %d", &rows, &cols);
	arr = (int **)malloc(rows * sizeof(int *));
	for (i = 0; i < rows; i++)
	{
	    arr[i] = (int *)malloc(cols * sizeof(int));
	}
    printf("Enter the elements:\n");
	for (i = 0; i < rows; i++)
	{
	    for (j = 0; j < cols; j++)
	    {
	        scanf("%d", &arr[i][j]);
	    }
	}
    printf("\nThe 2D array is:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
	for (i = 0; i < rows; i++)
	{
	    free(arr[i]);
	}
	free(arr);
}
/* Output: Enter number of rows and columns: 4 3
Enter the elements:
4
5
6
1
2
3
7
8
9
1
4
5

The 2D array is:
4 5 6
1 2 3
7 8 9
1 4 5
*/

/* 11. Write a C program using pointer to strings that accepts the name of and animal and a bird and returns the names in plural. */
void plural()
{
	char animal[50], bird[50];
	char *a, *b;
	printf("Enter the name of an animal: ");
	scanf("%s", animal);
	printf("Enter the name of a bird: ");
	scanf("%s", bird);
	a = animal;
	b = bird;
	strcat(a, "s");
	strcat(b, "s");
	printf("Plural forms:\n");
	printf("Animal: %s\n", a);
	printf("Bird   : %s\n", b);
}
/* Output:  Enter the name of an animal: monkey
			Enter the name of a bird: parrot
			Plural forms:
			Animal: monkeys
			Bird   : parrots
*/

/* 12. Write a C program to demonstrate how to perform arithmetic on void pointers (if supported by compiler). */
void void_arithmetic()
{
	int arr[] = {10, 20, 30, 40, 50};
	void *ptr;
	ptr = arr;
	printf("Array elements using void pointer arithmetic:\n");
	for (int i = 0; i < 5; i++)
	{
	    printf("%d ", *(int *)ptr);
	    ptr = (char *)ptr + sizeof(int);
	}
	printf("\n");
}
/* Output: Array elements using void pointer arithmetic:
		   10 20 30 40 50
*/

/* 13. Write a C program to read multiple lines of text until EOF, storing each line using malloc, and then print them in reverse order.
   • Use getline() or fgets() to read each line.
   • Use malloc() to save each line, and realloc() to manage the array of line pointers.
*/


/* 14. Write a C program to implement a stack using pointers with the following
operations:
• push
• pop
• display
*/

/* 15. Write a C program to allocate and free a 2D matrix using double pointers (int **matrix). */
void double_two2()
{
    int rows, cols, i, j;
   	int **matrix;
	printf("Enter number of rows and columns: ");
	scanf("%d %d", &rows, &cols);
	matrix = (int **)malloc(rows * sizeof(int *));
	for (i = 0; i < rows; i++)
	{
		matrix[i] = (int *)malloc(cols * sizeof(int));
	}
    printf("Enter the elements:\n");
	for (i = 0; i < rows; i++)
	{
	    for (j = 0; j < cols; j++)
	    {
	        scanf("%d", &matrix[i][j]);
	    }
	}
    printf("\nThe 2D array is:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
	for (i = 0; i < rows; i++)
	{
	    free(matrix[i]);
	}
	free(matrix);
}
/* Output: */

/* 16. */
void q16()
{
	int arr[6]={11,22,33,44,55,66};
	int *ptr=arr;
	printf("%d\n",*ptr++);  // *(ptr++) 11, then ptr -> 22
	printf("%d\n",++*ptr);  // ++(*ptr) 23, now ptr -> 22
	printf("%d\n",*++ptr);  // *(++ptr) 33, now ptr -> 33
	ptr[1]++; // ptr[i] = *(ptr+i) => *(ptr+1) = 44 => 44+1 = 45
	ptr++; // now ptr->44
	ptr[-1]++; // *(ptr-1)++ = 33 => 33+1 = 34
	ptr[0]++; // *(ptr+0) = 45 => 45+1 = 46
	printf("%d %d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5]);
}
/* Output: 11
		   23
		   33
		   11 23 34 46 55 66
*/

/* 17_1. */
void q17()
{
	int arr[6]={11,22,33,44,55,66};
	printf("%d\n",++*arr); // ++(*arr) = 11+1 = 12
	//printf("%d\n",*arr++); // *(arr++) -> array name incrementing - error
}
/* Output: 12
           Error
*/

/* 18. */
void q18()
{
	char arr[10]={'0','1', '2', '3', '4', '5', '6','7', '8', '9'};
	char *cp;
	int *ip;
	cp=ip=arr;
	printf("%x %x\n", *cp,*ip);
	cp++;
	ip++;
	printf("%x %x\n",*cp,*ip);
}
/* Output: 30 33323130
		   31 37363534
*/
/* Explanation: 0 -> 48 -> 30
 				char = 30
 				int = 4 Bytes = 33323130
*/

/* 19. */
void print(char *ptr, int n)
{
	if(n)
	print(ptr+1, n-1); // print(b,4) -> print(c,3) -> print(d,2) -> print(e,1)
	printf("%c",*ptr);
}
void q19()
{
	char arr[]={'a', 'b', 'c', 'd', 'e'};
	print(arr,sizeof(arr)-1); // print(a,5)
}
/* Output: edcba */

/* 20. */
void q20()
{
	int a[]={2,3,4,5,6};
	int i=0;
	printf("%d",a[i++]+i[a+1]); // *(i+(a+1)) = *(a+2) = 4; a[i] = 2  ; 4+2 = 6
}
/* Output: 6 */

/* 21. */
void q21()
{
	int a[3],i;
	for(i=0;i<3;i++)
	a[i]=i++; // a = [0,...,2]
	for(i=0;i<3;i++)
	printf("%d",a[i]);
}
/* Output: *** stack smashing detected ***: terminated */

/* 22. */
void q22()
{
	int a[ 5]={11,22,33,44,55};
	int b[5];
	//b=a;
	printf("%d %d\n",*a,*b);
}
/* Output: Error: Array assigning not possible */

/* 23. */
void fun(int *ptr, int n)
{
	if(n)
	{
		fun(ptr+1,n-1);
		++*ptr;
	}
}
void q23()
{
	int arr[ ]={11,22,33,44,55},i;
	fun(arr,sizeof(arr)/sizeof(*arr));
	for(i=0;i<5;i++)
	printf("%d,",arr[i]);
}
/* Output: 12,23,34,45,56, */

int main(void)
{
	int n;
	while(1)
    {
		printf("Enter the question number (1-20): ");
		scanf("%d", &n);
		switch(n)
		{
		case 1: amicable_numbers(); break;
		case 2: arithmetic_operations(); break;
		case 3: volume_calculator(); break;
		case 4: permutations(); break;
		case 5: largest_element(); break;
		case 6: string_length(); break;
		case 7: vowel_consonant(); break;
		case 8: alphabets(); break;
		case 9: palindrome(); break;
		case 10: twod_array(); break;
		case 11: plural(); break;
		case 12: void_arithmetic(); break;
		//case 13: text_read(); break;
		//case 14: calculator(); break;
		case 15: double_two2(); break;
		case 16: q16(); break;
		case 17: q17(); break;
		case 18: q18(); break;
		case 19: q19(); break;
     	case 20: q20(); break;
     	case 21: q21(); break;
     	case 22: q22(); break;
     	case 23: q23(); break;
		}
	}
	return 0;
}
