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
        getchar();  // Consumir el salto de l�nea pendiente en el buffer
        fgets(nombre, sizeof(nombre), stdin);

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
            case 2: // T�cnico
                aumento = salarioOrdinario * 0.10;
                cantTecnicos++;
                break;
            case 3: // Profesional
                aumento = salarioOrdinario * 0.05;
                cantProfesionales++;
                break;
            default:
                printf("Tipo de empleado no valido.\n");
                continue;
        }
        
        salarioBruto = salarioOrdinario + aumento;
        deduccionCCSS = salarioBruto * 0.0917;
        salarioNeto = salarioBruto - deduccionCCSS;
        
        // Actualiza los acumulados despu�s de calcular el salario neto
        if (tipo == 1) {
            acumuladoNetoOperarios += salarioNeto;
        } else if (tipo == 2) {
            acumuladoNetoTecnicos += salarioNeto;
        } else if (tipo == 3) {
            acumuladoNetoProfesionales += salarioNeto;
        }
        
        // Mostrar los datos del empleado
        printf("\nDatos del empleado:\n");
        printf("--------------------------------------------------\n");
        printf("Cedula: %s\n", cedula);
        printf("Nombre: %s\n", nombre);
        printf("Tipo Empleado: %d\n", tipo);
        printf("Salario por Hora: %.2lf\n", salarioPorHora);
        printf("Cantidad de Horas: %.2lf\n", horasTrabajadas);
        printf("--------------------------------------------------\n");
        printf("Salario Ordinario: %.2lf\n", salarioOrdinario);
        printf("Aumento: %.2lf\n", aumento);
        printf("Salario Bruto: %.2lf\n", salarioBruto);
        printf("Deduccion CCSS: %.2lf\n", deduccionCCSS);
        printf("Salario Neto: %.2lf\n", salarioNeto);
        printf("--------------------------------------------------\n");
        
        printf("\n�Desea ingresar otro empleado? (1-Si, 0-No): ");
        scanf("%d", &opcion);
	}while(opcion != 0);
    
    printf("\nEstadisticas finales:\n");
    printf("--------------------------------------------------\n");
    printf("Cantidad de Empleados Tipo Operarios: %d\n", cantOperarios);
    if (cantOperarios > 0) {
    	printf("Acumulado Salario Neto para Operarios: %.2lf\n", acumuladoNetoOperarios);
        printf("Promedio Salario Neto para Operarios: %.2lf\n", acumuladoNetoOperarios / cantOperarios);
    } else {
    	printf("Acumulado Salario Neto para Operarios: N/A\n");
        printf("Promedio Salario Neto para Operarios: N/A\n");
    }
    
    printf("--------------------------------------------------\n");
    printf("Cantidad de Empleados Tipo Tecnico: %d\n", cantTecnicos);
    if (cantTecnicos > 0) {
    	printf("Acumulado Salario Neto para Tecnicos: %.2lf\n", acumuladoNetoTecnicos);
        printf("Promedio Salario Neto para Tecnicos: %.2lf\n", acumuladoNetoTecnicos / cantTecnicos);
    } else {
    	printf("Acumulado Salario Neto para Tecnicos: N/A\n");
        printf("Promedio Salario Neto para Tecnicos: N/A\n");
    }
    
    printf("--------------------------------------------------\n");
    printf("Cantidad de Empleados Tipo Profesional: %d\n", cantProfesionales);
    if (cantProfesionales > 0) {
    	printf("Acumulado Salario Neto para Profesionales: %.2lf\n", acumuladoNetoProfesionales);
        printf("Promedio Salario Neto para Profesionales: %.2lf\n", acumuladoNetoProfesionales / cantProfesionales);
    } else {
    	printf("Acumulado Salario Neto para Profesionales: N/A\n");
        printf("Promedio Salario Neto para Profesionales: N/A\n");
    }
    printf("--------------------------------------------------\n");

    getch(); // Pausa antes de finalizar el programa
    
	return 0;
}
