#include <stdio.h>

int main(void)
{
	int nAge = 0;
	float fHeight = 0.0f;
	char cGender = 'M';
	char strName[50] = "Temporary";

	// getting variable information
	printf("Enter your age, height, grade, and name:\n");
	scanf_s("%d %f %c %s", &nAge, &fHeight, &cGender),
	    sizeof(cGender), strName, sizeof(strName);

		//printing variable information
		printf("\n");
		printf("Your height is: %.2f\n", fHeight);
		printf("Your gender is: %c\n", cGender);
		printf("Your name is: %s\n", strName);
		return 0;
}