
#include "Parqueo.h"

void Parqueo::agregarVehiculo(vehiculo _vehiculo)
{
	try
	{
		queue<vehiculo> auxiliar = parqueo;
		while (!auxiliar.empty())
		{
			if (auxiliar.front().getPlaca() == _vehiculo.getPlaca())
			{
				throw exception("La placa ya fue registrada");
			}
			else
			{
				auxiliar.pop();
			}
		}

		auxiliar = listaEspera;
		while (!auxiliar.empty())
		{
			if (auxiliar.front().getPlaca() == _vehiculo.getPlaca())
			{
				throw exception("La placa ya fue registrada");
			}
			else
			{
				auxiliar.pop();
			}
		}

		if (parqueo.size() >= 3)
		{

			listaEspera.push(_vehiculo);
			cout << "--------------------------------------" << endl;
			cout << GREEN << "El vehiculo fue puesto en la lista de espera" << WHITE << endl;
		}
		else
		{
			parqueo.push(_vehiculo);
			cout << "--------------------------------------" << endl;
			cout << GREEN << "El vehiculo fue ingresado al parqueo" << WHITE << endl;
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

void Parqueo::salidaVehiculo()
{
	if (!parqueo.empty())
	{
		cout << "El vehiculo " << parqueo.front().getPlaca() << " está saliendo." << endl;
		parqueo.pop();
	}
	
	if (!listaEspera.empty())
	{
		cout << "El vehiculo " << listaEspera.front().getPlaca() << " puede entrar al parqueo." << endl << endl;
		parqueo.push(listaEspera.front());
		listaEspera.pop();
	}

	if (listaEspera.empty() && parqueo.empty())
	{
		cout << "No hay vehiculos en espera" << endl;
	}
}

void Parqueo::mostrarVehiculos()
{
	if (!parqueo.empty())
	{
		queue<vehiculo> auxiliar = parqueo;
		cout << "Vehiculos en el parqueo: " << endl;

		while (!auxiliar.empty())
		{
			cout << "Placa: " << auxiliar.front().getPlaca() << endl;
			auxiliar.pop();
		}
	}
	
	if (!listaEspera.empty())
	{
		queue<vehiculo> auxiliar = listaEspera;
		cout << endl << "Vehiculos en lista de espera: " << endl;

		while (!auxiliar.empty())
		{
			cout << "Placa: " << auxiliar.front().getPlaca() << endl;
			auxiliar.pop();
		}
	}
	
	if (listaEspera.empty() && parqueo.empty())
	{
		cout << "No hay vehiculos en espera" << endl;
	}
}
