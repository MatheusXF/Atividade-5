#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
int count = 0;
int num = 0;


void *soma(void *arg)
{
	int (*array)[num] = (int *) arg;
	int soma = 0;
	for (int y = 0; y < num; y++) {
		soma += (*array)[y];
	}
	
	pthread_mutex_lock(&lock);
	count += soma;
	pthread_mutex_unlock(&lock);

	return arg;
}

void *principal(void *arg)
{
  	int i,j,n;
        scanf("%d", &n);
        int (*array1)[n] = malloc(n * sizeof *array1);
        num = n;
        
        for (i = 0; i < n; i++) {
            	for (j = 0; j < n; j++)
                	scanf("%d", &array1[i][j]);
        }
 	pthread_t t[n];

 	for (i = 0; i < n; i++)
  		pthread_create((&t[i]), NULL, soma, (void*)array1[i]);

  	for (i = 0; i < n; i++)
  		pthread_join(t[i], NULL);
  
	printf("%d", count);
  	return arg;
}
int main()
{
	pthread_t t1;

	pthread_create(&t1, NULL, principal, NULL);
	pthread_join(t1, NULL);

	return 0;
}
