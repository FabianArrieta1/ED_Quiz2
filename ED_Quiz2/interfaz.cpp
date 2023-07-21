#include "interfaz.h"

void interfaz::pantallaTitulo() 
{
    return;
}

void interfaz::menuPrincipal()
{
    setlocale(LC_ALL, "");
    int Set[] = { 7, 7, 7, 7 };
    Set[0] = 12;

    while (1)
    {
        system("cls");

        cout << "		[]------------------------------------------[]" << endl;
        cout << "		|                Menú Principal              |" << endl;
        cout << "		[]------------------------------------------[]" << endl;
        cout << "		|                                            |" << endl;
        cout << "		|           Selecciona una opción:           |" << endl;
        cout << "		|";

        for (int i = 0;;)
        {

            _metodoInterfaz.gotoxy(25, 5);
            _metodoInterfaz.color(Set[0]);
            cout << "Agregar vehiculo al parqueo";

            cout << WHITE << "	     |" << endl;
            cout << "		|";

            _metodoInterfaz.gotoxy(24, 6);
            _metodoInterfaz.color(Set[1]);
            cout << "Vehiculo de salida del parqueo";

            cout << WHITE << "	     |" << endl;
            cout << "		|";

            _metodoInterfaz.gotoxy(23, 7);
            _metodoInterfaz.color(Set[2]);
            cout << "Cantidad de espacios disponibles";

            cout << WHITE << "      |" << endl;
            cout << "		|";

            _metodoInterfaz.gotoxy(35, 8);
            _metodoInterfaz.color(Set[3]);
            cout << "Salir";

            cout << WHITE << "                     |" << endl;
            cout << "		|                                            |" << endl;
            cout << "		[]------------------------------------------[]" << endl;

            key = _getch();

            if (key == 72 && (counter >= 1 && counter <= 4))		// Validar si la flecha arriba es pulsada	|| 72 es el valor de la flecha arriba en ASCII
            {
                counter--;

                if (counter == 0)
                {
                    counter = 4;
                }
            }
            else if (key == 80 && (counter >= 1 && counter <= 4))	// Validar si la flecha abajo es pulsada	|| 80 es el valor de la flecha abajo en ASCII
            {
                counter++;

                if (counter == 5)
                {
                    counter = 1;
                }
            }
            else if (key == '\r')	// Identifica si la tecla ENTER fue pulsada
            {
                switch (counter)
                {
                case 1:
                    try
                    {
                        string placa;

                        // Ingresar Vehiculo
						system("cls");
						cout << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << "		|        Ingresar vehiculo al parqueo        |" << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << endl;

                        cout << "Ingresa el número de placa: ";
                        getline(cin, placa);
                        _vehiculo.setPlaca(placa);

                        _parqueo.agregarVehiculo(_vehiculo);
                        system("pause");
                    }
                    catch (exception& e) {
                        cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
                        cout << "-------------------------" << endl;
                        cout << "Volviendo al menu principal." << endl << endl;
                        system("pause");
                    }
                    break;

                case 2:
                    try
                    {
                        // Vehiculo de Salida
						system("cls");
						cout << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << "		|       Salida de vehiculo del parqueo       |" << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << endl;
                        _parqueo.salidaVehiculo();
                        
                        system("pause");
                    }
                    catch (exception& e) {
                        cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
                        cout << "-------------------------" << endl;
                        cout << "Volviendo al menu principal." << endl << endl;
                        system("pause");
                    }

                    break;

                case 3:
                    try
                    {
						// Vehiculos en espera
						system("cls");
						cout << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << "		|             Espacios disponibles           |" << endl;
						cout << "		[]------------------------------------------[]" << endl;
						cout << endl;

                        _parqueo.mostrarVehiculos();
                        cout << endl;
                        system("pause");
                    }
                    catch (exception& e) {
                        cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
                        cout << "-------------------------" << endl;
                        cout << "Volviendo al menu principal." << endl << endl;
                        system("pause");
                    }

                    break;

                case 4:
                    try 
                    {
                        // Salir
                        exit(0);
                    }
                    catch (exception& e) {
                        cout << RED << "Ha ocurrido un error: " << WHITE << e.what() << endl;
                        cout << "-------------------------" << endl;
                        cout << "Volviendo al menu principal." << endl << endl;
                        system("pause");
                    }
                    break;

                

                default:
                    cout << RED << "Seleccione una opcion valida. " << WHITE << endl;
                }

                break;	// Para salir del ciclo for
            }

            // Color por defecto de todas las opciones
            Set[0] = 7;				// 7 es el color blanco
            Set[1] = 7;
            Set[2] = 7;
            Set[3] = 7;

            // Cambiar color basado en la opcion seleccionada
            switch (counter)
            {
            case 1:
                Set[0] = 12;		// 12 es el color rojo
                break;

            case 2:
                Set[1] = 12;		// 12 es el color rojo
                break;

            case 3:
                Set[2] = 12;		// 12 es el color rojo
                break;

            case 4:
                Set[3] = 12;		// 12 es el color rojo
                break;
            }
        }
    }
}