#include "vehiculo.h"

class Parqueo : public vehiculo
{
public:
	void agregarVehiculo(vehiculo);
	void salidaVehiculo();
	void mostrarVehiculos();

private:
	queue<vehiculo> parqueo;
	queue<vehiculo> listaEspera;
};

