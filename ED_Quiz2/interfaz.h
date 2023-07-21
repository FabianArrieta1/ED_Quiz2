#include "Parqueo.h"
#include "metodoInterfaz.h"

class interfaz
{
public:
	void pantallaTitulo();
	void menuPrincipal();
	
private:
	metodoInterfaz _metodoInterfaz;
	vehiculo _vehiculo;
	Parqueo _parqueo;
	int key;
	int counter = 1;
};

