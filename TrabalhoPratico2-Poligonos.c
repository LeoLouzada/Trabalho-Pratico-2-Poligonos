#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float X;
    float Y;
} Ponto;

float AreaTriangulo(Ponto A, Ponto B, Ponto C);
float AreaPoligono(Ponto vertices[], int n);

int main(){
    FILE *file;
    int n;

    file = fopen("Vertices.txt", "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fscanf(file, "%d", &n);
    Ponto vertices[n];

    int i;
    for(i = 0; i < n; i++){
        fscanf(file, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    fclose(file);

    float area = AreaPoligono(vertices, n);
    printf("A area do poligono eh: %.2f\n", area);

    return 0;
}

float AreaTriangulo(Ponto A, Ponto B, Ponto C){
    return fabs((A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y)) / 2); // ESSA FUNCAO FAZ RETORNAR O VALOR ABSOLUTO
}

float AreaPoligono(Ponto vertices[], int n){
    float area = 0.0;
    int i;
    for(i = 1; i < n - 1; i++) {
        area += AreaTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }
    return area;
}

