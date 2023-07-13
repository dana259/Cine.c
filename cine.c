#include <stdio.h>
#include <string.h>
#define MAX_INTENTOS 3
#define MAX_ASIENTOS_NORMAL 100
#define MAX_ASIENTOS_VIP 50
#define MAX_ASIENTOS_3D 75
#define PRECIO_NORMAL 8.00
#define PRECIO_VIP 15.00
#define PRECIO_3D 12.00
#define DESCUENTO_1 0.05
#define DESCUENTO_2 0.10
#define DESCUENTO_3 0.15
int main (void){

    int opcion,total_entradas;
    float total_ingresos;
    char username1[20] = "Cliente1";
    char password1[20] = "1234";
    char username2[20] = "Cliente2";
    char password2[20] = "cines";
    char username3[20] = "Cliente3";
    char password3[20] = "descuentos";
    char user [20];
    char password[20];
    int attempts = 0;

    printf("Inicio de sesión\n");

    while (attempts < MAX_INTENTOS) {
        printf ("Nombre de usuario: ");
        scanf ("%s", user);
        printf ("Contraseña: ");
        scanf ("%s", password);

        if ((strcmp (user, username1) == 0 && strcmp(password, password1) == 0) ||
            (strcmp (user, username2) == 0 && strcmp(password, password2) == 0) ||
            (strcmp (user, username3) == 0 && strcmp(password, password3) == 0)) {
            printf ("Inicio de sesión exitoso. ¡Bienvenido, %s!\n",user);
            printf ("   \n");
            break;
        } else {
            attempts++;
            printf ("Usuario o contraseña incorrectos, intento #%d\n", attempts);

            if (attempts == MAX_INTENTOS) {
                printf ("Imposible ingresar\n");
                printf ("Cerrando sistema\n");
                return 0;
            }
        }
    }

    char venta_entradas [20] = "Entradas";
    char estadistica_de_ventas [20] = "Estadistica";
    char opcion_cine [20];
    char Salir [10 ]= "Salir";
    char tipo_sala[10];
    int num_entradas,max_asientos;
    float precio_entrada,costo_total;


    do
    {
        printf ("Ingrese lo que desea hacer: \n ");
        printf ("Si desea comprar entradas, escriba: Entradas\n");
        printf ("Si desea ver las estadísticas de ventas,escriba: Estadistica\n");
        printf ("Cuando acabe de usar la página, ingrese: Salir \n");
        printf ("   \n");
        scanf ("%s",opcion_cine);

        if (strcmp (venta_entradas,opcion_cine)==0 )
        {
            printf ("Seleccionó comprar entradas\n");
            printf ("    \n");
            do
            {
                printf ("Seleccione que película quiere ver:\n");
                printf ("   \n");
                printf ("Aladdin live action: 1 \n");
                printf ("Cenicienta live action: 2 \n");
                printf ("   \n");
                printf ("Si no va a comprar nada, seleccione la opción: 3\n");
                printf ("   \n");
                scanf ("%d",&opcion);

                switch (opcion)
                {
                case 1:

                    printf ("Está comprando entradas para: Aladdin live action\n");
                    printf ("   \n");
                    

                    break;
                case 2:

                    printf ("Está comprando entradas para: Cenicienta live action\n");
                    printf ("     \n");
                    break;

                case 3:

                    printf ("Siempre es un placer ayudarle\n");
                    printf ("Regresando\n");
                    printf ("   \n");
                    break;

                default:

                    printf ("Opción inválida, intente de nuevo\n");
                    printf ("   \n");

                    break;
                     

                }

                printf ("Las salas disponibles son: Normal, VIP y 3D\n");
                printf ("En que sala quiere ver la película?\n");
                printf ("   \n");
                scanf ("%s",tipo_sala);

                if (strcmp(tipo_sala, "Normal") == 0) {
                    max_asientos = MAX_ASIENTOS_NORMAL;
                    precio_entrada = PRECIO_NORMAL;
                } 

                else if (strcmp(tipo_sala, "VIP") == 0) {
                    max_asientos = MAX_ASIENTOS_VIP;
                    precio_entrada = PRECIO_VIP;
                } 

                else if (strcmp(tipo_sala, "3D") == 0) {
                    max_asientos = MAX_ASIENTOS_3D;
                    precio_entrada = PRECIO_3D;
                } 

                else {
                    printf ("Tipo de sala no válido\n");
                    printf ("    \n");
                } 

                printf ("Ingrese el número de entradas que va a comprar: ");
                printf ("   \n");
                scanf("%d", &num_entradas);

                if (num_entradas > max_asientos) {
                    printf ("No hay suficientes asientos disponibles, seleccione otra cantidad\n");
                    
                }   

                else{
                    costo_total = num_entradas * precio_entrada;
                    printf ("El precio de las entradas sin descuento es: $%.2f\n",costo_total);
                    printf ("    \n");

                    if (costo_total >= 40 && costo_total < 80) {
                        costo_total -= costo_total * DESCUENTO_1;
                    }

                    else if (costo_total >= 80 && costo_total < 120) {
                        costo_total -= costo_total * DESCUENTO_2;
                    }

                    else if (costo_total >= 120) {
                        costo_total -= costo_total * DESCUENTO_3;
                    }   

                    printf ("El precio de las entradas aplicando el descuento es: $%.2f\n", costo_total);
                    printf ("Gracias por su compra\n");
                    printf ("    \n");

                    total_entradas += num_entradas;
                    total_ingresos += costo_total;

                    
                }   
                

            } while (opcion !=3);

            
        }


        if (strcmp(estadistica_de_ventas,opcion_cine)== 0)
        {
        printf ("Seleccionó ver las estadísticas de la venta de entradas\n");
        printf ("    \n");

        printf("Total de entradas vendidas: %d\n", total_entradas);
        printf("Total de ingresos generados: %.2f\n", total_ingresos);
        }
    
        

    
    } while (strcmp(Salir,opcion_cine)==-1||strcmp(Salir,opcion_cine)==1);

    

    printf ("Gracias por usar\n");
    printf ("Cerrando sistema\n");
    
    
    return 0;
}