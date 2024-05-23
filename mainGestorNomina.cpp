#include <iostream>
#include <stdio.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	//Variables
	char cedula[20];
    char nombre[50];
    int tipo;
    double salarioPorHora;
    double horasTrabajadas;
    double salarioOrdinario;
    double aumento;
    double salarioBruto;
    double deduccionCCSS;
    double salarioNeto;

    int opcion;
    int cantOperarios = 0, cantTecnicos = 0, cantProfesionales = 0;
    double acumuladoNetoOperarios = 0, acumuladoNetoTecnicos = 0, acumuladoNetoProfesionales = 0;
    
    do{
    	printf("Ingrese la cedula del empleado: ");
        scanf("%s", cedula);

        printf("Ingrese el nombre del empleado: ");
        scanf("%s", nombre);

        printf("Ingrese el tipo de empleado (1-Operario, 2-Tecnico, 3-Profesional): ");
        scanf("%d", &tipo);

        printf("Ingrese el salario por hora: ");
        scanf("%lf", &salarioPorHora);

        printf("Ingrese la cantidad de horas trabajadas: ");
        scanf("%lf", &horasTrabajadas);
        
        salarioOrdinario = salarioPorHora * horasTrabajadas;

        switch(tipo) {
            case 1: // Operario
                aumento = salarioOrdinario * 0.15;
                cantOperarios++;
                break;
            case 2: // Técnico
                aumento = salarioOrdinario * 0.10;
                cantTecnicos++;
                break;
            case 3: // Profesional
                aumento = salarioOrdinario * 0.05;
                cantProfesionales++;
                break;
            default:
                printf("Tipo de empleado no válido.\n");
                continue;
        }
        
        salarioBruto = salarioOrdinario + aumento;
        deduccionCCSS = salarioBruto * 0.0917;
        salarioNeto = salarioBruto - deduccionCCSS;
        
        // Actualiza los acumulados después de calcular el salario neto
        if (tipo == 1) {
            acumuladoNetoOperarios += salarioNeto;
        } else if (tipo == 2) {
            acumuladoNetoTecnicos += salarioNeto;
        } else if (tipo == 3) {
            acumuladoNetoProfesionales += salarioNeto;
        }
        
        printf("\n¿Desea ingresar otro empleado? (1-Si, 0-No): ");
        scanf("%d", &opcion);
	}while(opcion != 0);
    
    
	return 0;
}
