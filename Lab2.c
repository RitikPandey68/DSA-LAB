#include<stdio.h>
#include<stdlib.h>

int stringLen(char str[]);
void stringCat(char dest[], char src[]);

void main()
{
	int i=0,j,k=0,flag=0;
	char STR[50], PAT[15], REP[15], RESULT[50];
	printf("Enter String\n");
	gets(STR);
	printf("Enter Pattern\n");
	gets(PAT);
	printf("Enter Substitution Key\n");
	gets(REP);
	while(STR[i] != '\0')
	{
		j=0;
		while((STR[i+j] == PAT[j]) && (PAT[j] != '\0'))
		{
			j++;
		}
		
		if(PAT[j] == '\0')
		{
			flag = 1;
			RESULT[k] = '\0';
			stringCat(RESULT,REP);
			k = k + stringLen(REP);
			// Here j will always be equal to string length of pattern.
			i = i + (j -1);
		}
		else
		{
			RESULT[k++] = STR[i];
		}
		i++;
	}
	RESULT[k] = '\0';
	printf("The result is\n");
	if(flag)
		puts(RESULT);
	else
		printf("Pattern not found\n");
}

int stringLen(char str[])
{
	int len=0;
	while(str[len] != '\0')
	{
		len++;
	}
	return len;
}

void stringCat(char dest[], char src[])
{
	int i=0, j=0;
	while(dest[i] != '\0')
	{
		i++;
	}
	// i can be computed using strLength function also. Above while block can be replaced as " i = stringLen(dest); ".
	
	while(src[j] != '\0')
	{
		dest[i+j] = src[j];
		j++;
	}
	return;
}
