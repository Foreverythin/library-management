#include <stdio.h>

int main(void){
	int a;
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		printf("1");
		break;
	
	default:
		printf("%d", a);
		break;
	}

	return 0;
}