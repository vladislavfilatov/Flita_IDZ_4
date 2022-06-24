#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VERTEX_COUNT 10000

int main(int argc, char *argv[])
{
    int maxlen = VERTEX_COUNT*10;
    char line[maxlen];
    int **matrix;

    int w = 0, h = 0, cc = 0, len;
    char input[VERTEX_COUNT];

    int removal_edge[2];
 
    clock_t start_time;
	clock_t end_time;

    FILE * matrixFile;


    /*   ------------------             СОЗДАЕМ ДВУМЕРНЫЙ МАССИВ ДЛЯ ГРАФА               --------------    */
    matrix = (int**) malloc(VERTEX_COUNT * sizeof(int*));
    for(int i = 0; i < VERTEX_COUNT; i++){
        matrix[i] = (int*) malloc(VERTEX_COUNT * sizeof(int));
    }
     start_time = clock();

    /*   ------------------             СЧИТЫВАЕТ ФАЙЛИК С МАТРИЦЕЙ               --------------    */
    matrixFile = fopen("matrix1.txt", "r");
        if (matrixFile == NULL)
        {
            printf("Can't open file for reading.\n");
		    return 1;
        }

    /*   ------------------             ЗАПИСЫВАЕТ МАТРИЦУ В МАССИВ               --------------    */
    while(fgets(line, maxlen, matrixFile))
    {
        w = 0;

        for(int i = 0; line[i]; i++)
        {
            if(line[i] != ' ' && line[i] != '\n')
            {
                if(line[i] == '0')
                    matrix[h][w] = 0;
                else
                    matrix[h][w] = 1;

                //if(matrix[h][w]) printf("%d-%d\n", h+1, w+1);       //Выводит, если есть грань

                w++;
            }
        }
        h++;
    }
    len = h;
  end_time = clock();
    /*   ------------------             УДАЛЯЕМ ГРАНЬ                --------------    */
    printf("What edge to delete? Enter like 'x y': ");
    scanf("%d %d", &removal_edge[0], &removal_edge[1]);

    if(!matrix[removal_edge[0] - 1][removal_edge[1] - 1]){
        printf("You pick couple of vertex that haven't edge or oversize.\n");
		return 1;
    }
    matrix[removal_edge[0] - 1][removal_edge[1] - 1] = 0;
    matrix[removal_edge[1] - 1][removal_edge[0] - 1] = 0;

   
    /*   --------------------            ВЫВОД              ----------------------   */
   
 
    fclose(matrixFile);
    printf("\nspent time: %.1lf ms\n", (double) (end_time - start_time) / 1000*CLOCKS_PER_SEC);

    return 0;
}