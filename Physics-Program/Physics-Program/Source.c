#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Deklaracja struktury kt�ra b�dzie przechowywa�a dane o symulacji

typedef struct data
{
	long double x_pos, y_pos, z_pos;		//Pozycja cz�stki w przestrzeni
	long double Ex, Ey, Ez;					//Nat�enie pola elektrycznego
	long double Bx, By, Bz;					//Indukcja magnetyczna
	long double vx, vy, vz;					//Pr�dko�� cz�stki w przestrzeni
	long double m;							//Masa cz�stki
	long double dt;							//Krok czasowy
	long double q;							//�adunek elektryczny q = n * e
} input;


/*
	Dane dla ma�ej skali atomu.
*/
input data_input_micro()
{
	//Deklaracja zmiennych pomocniczych.
	long double x_pos, y_pos, z_pos, Ex, Ey, Ez, Bx, By, Bz, vx, vy, vz, m, dt, q, n;
	//Podajemy sk�adowe nat�enia pola elektrycznego [N/C]
	printf("Wektor natezenia pola elektrycznego [N/C]: \n");
	printf("Ex: ");
	scanf(" %lf", &Ex);
	printf("Ey: ");
	scanf(" %lf", &Ey);
	printf("Ez: ");
	scanf(" %lf", &Ez);
	//Podajemy sk�adowe indukcji magnetycznej [T]
	printf("Wektor indukcji magnetycznej [T]: \n");
	printf("Bx: ");
	scanf(" %lf", &Bx);
	printf("By: ");
	scanf(" %lf", &By);
	printf("Bz: ");
	scanf(" %lf", &Bz);
	//Podajemy sk�adowe pr�dko�ci [m/s]
	printf("Wektor predkosci [m/s]: \n");
	printf("vx: ");
	scanf(" %lf", &vx);
	printf("vy: ");
	scanf(" %lf", &vy);
	printf("vz: ");
	scanf(" %lf", &vz);
	//Podajemy mas� cz�stki [u]
	printf("Masa czastki [u]: \n");
	printf("m: ");
	scanf(" %lf", &m);
	//Podajemy �adunek [C]
	printf("Wielokrotnosc ladunku elementarnego [C]: \n");
	printf("n: ");
	scanf(" %lf", &n);
	//Podajemy krok czasowy [ns]
	printf("Krok czasowy [ns]: \n");
	printf("dt: ");
	scanf(" %lf", &dt);

	//Przeliczanie jednostek
	q = n * 0.00000000000000000016;				// q = n * 1,6 * 10^(-19) C
	dt = dt * 0.000000001;						// dt = dt * 10^(-9)s
	m = m * 0.00000000000000000000000000166;	// m = m * 1,66 *1 10^(-27)kg

	x_pos = 0;					//Ustalenie pocz�tkowej pozycji cz�stki w osi x
	y_pos = 0;					//Ustalenie pocz�tkowej pozycji cz�stki w osi y
	z_pos = 0;					//Ustalenie pocz�tkowej pozycji cz�stki w osi z

	input data = { x_pos, y_pos, z_pos, Ex, Ey, Ez, Bx, By, Bz, vx, vy, vz, m, dt, q };		//Przekazanie warto�ci do struktury z danymi
	return data;	//Zwracamy struktur� z danymi
}

/*
	Dane dla skali makroskopowej.
*/
input data_input_macro()
{
	//Deklaracja zmiennych pomocniczych.
	long double x_pos, y_pos, z_pos, Ex, Ey, Ez, Bx, By, Bz, vx, vy, vz, m, dt, q;
	//Podajemy sk�adowe nat�enia pola elektrycznego [N/C]
	printf("Wektor natezenia pola elektrycznego [N/C]: \n");
	printf("Ex: ");
	scanf(" %lf", &Ex);
	printf("Ey: ");
	scanf(" %lf", &Ey);
	printf("Ez: ");
	scanf(" %lf", &Ez);
	//Podajemy sk�adowe indukcji magnetycznej [T]
	printf("Wektor indukcji magnetycznej [T]: \n");
	printf("Bx: ");
	scanf(" %lf", &Bx);
	printf("By: ");
	scanf(" %lf", &By);
	printf("Bz: ");
	scanf(" %lf", &Bz);
	//Podajemy sk�adowe pr�dko�ci [m/s]
	printf("Wektor predkosci [m/s]: \n");
	printf("vx: ");
	scanf(" %lf", &vx);
	printf("vy: ");
	scanf(" %lf", &vy);
	printf("vz: ");
	scanf(" %lf", &vz);
	//Podajemy mas� cz�stki [mg]
	printf("Masa czastki [mg]: \n");
	printf("m: ");
	scanf(" %lf", &m);
	//Podajemy �adunek [mC]
	printf("Ladunek [mC]: \n");
	printf("q: ");
	scanf(" %lf", &q);
	//Podajemy krok czasowy [ms]
	printf("Krok czasowy [ms]: \n");
	printf("dt: ");
	scanf(" %lf", &dt);

	//Przeliczanie jednostek
	q = q * 0.001;								// q = q * 10^(-3)C
	dt = dt * 0.001;							// dt = dt * 10^(-3)s
	m = m * 0.000001;							// m = m * 10^(-6)kg

	x_pos = 0;					//Ustalenie pocz�tkowej pozycji cz�stki w osi x
	y_pos = 0;					//Ustalenie pocz�tkowej pozycji cz�stki w osi y
	z_pos = 0;					//Ustalenie pocz�tkowej pozycji cz�stki w osi z

	input data = { x_pos, y_pos, z_pos, Ex, Ey, Ez, Bx, By, Bz, vx, vy, vz, m, dt, q };		//Przekazanie warto�ci do struktury z danymi
	return data;	//Zwracamy struktur� z danymi
}

/*
	Obliczamy si�� nat�enia pola elektrycznego w ka�dej osi x,y,z za pomoc� wzoru F = Eq
*/

long double Electric_Field_Force_X_Axis(input data)
{
	long double Fe;
	Fe = data.Ex * data.q;
	return Fe;
}

long double Electric_Field_Force_Y_Axis(input data)
{
	long double Fe;
	Fe = data.Ey * data.q;
	return Fe;
}

long double Electric_Field_Force_Z_Axis(input data)
{
	long double Fe;
	Fe = data.Ez * data.q;
	return Fe;
}

/*
Obliczamy si�� Lorentza w ka�dej osi x,y,z za pomoc� wzoru F = q(v x B)
Poniewa� obliczamy si�� dla ka�dej sk�adowej trzeba roz�o�y� macierz.

| i  j  k  |
| vx vy vz | = i(vy * Bz - vz * By) - j(vx * Bz - vz * Bx) + k(vx * By - vy * Bx) = w(i,-j,k)
| Bx By Bz |

Sk�adow� i przedstawiamy jako o� X w przestrzeni wi�c si�a dzia�aj�ca w tej osi ma posta� Fx = q * (vy * Bz - vz * By)
Sk�adow� j przedstawiamy jako o� Y w przestrzeni wi�c si�a dzia�aj�ca w tej osi ma posta� Fy = q * -(vx * Bz - vz * Bx)
Sk�adow� k przedstawiamy jako o� Z w przestrzeni wi�c si�a dzia�aj�ca w tej osi ma posta� Fz = q * (vx * By - vy * Bx)
*/

long double Lorentz_Force_X_Axis(input data)
{
	long double Fm;
	Fm = data.q * ((data.vy * data.Bz) - (data.vz * data.By));
	return Fm;
}

long double Lorentz_Force_Y_Axis(input data)
{
	long double Fm;
	Fm = (-1) * data.q * ((data.vx * data.Bz) - (data.vz * data.Bx));
	return Fm;
}

long double Lorentz_Force_Z_Axis(input data)
{
	long double Fm;
	Fm = data.q * ((data.vx * data.By) - (data.vy * data.Bx));
	return Fm;
}

/*
Obliczamy ��czn� warto�� si� dzia�aj�cych w osi x,y,z dodaj�c si�� pola elektrycznego oraz magnetycznego F = Fm + Fe
*/

long double Electromagnetic_Force_X_Axis(input data)
{
	long double F, Fe, Fm;
	Fe = Electric_Field_Force_X_Axis(data);
	Fm = Lorentz_Force_X_Axis(data);
	F = Fe + Fm;
	return F;
}

long double Electromagnetic_Force_Y_Axis(input data)
{
	long double F, Fe, Fm;
	Fe = Electric_Field_Force_Y_Axis(data);
	Fm = Lorentz_Force_Y_Axis(data);
	F = Fe + Fm;
	return F;
}

long double Electromagnetic_Force_Z_Axis(input data)
{
	long double F, Fe, Fm;
	Fe = Electric_Field_Force_Z_Axis(data);
	Fm = Lorentz_Force_Z_Axis(data);
	F = Fe + Fm;
	return F;
}

/*
Obliczamy now� pozycj� cz�stki w nast�pnym kroku danym wzorem r = ro + vo * dt + (F * dt^2) / 2m
*/

long double X_Axis_Position(input data)
{
	long double F, position_x;
	F = Electromagnetic_Force_X_Axis(data);
	position_x = data.x_pos + (data.vx * data.dt) + ((F * data.dt * data.dt) / (2 * data.m));
	return position_x;
}

long double Y_Axis_Position(input data)
{
	long double F, position_y;
	F = Electromagnetic_Force_Y_Axis(data);
	position_y = data.y_pos + (data.vy * data.dt) + ((F * data.dt * data.dt) / (2 * data.m));
	return position_y;
}

long double Z_Axis_Position(input data)
{
	long double F, position_z;
	F = Electromagnetic_Force_Z_Axis(data);
	position_z = data.z_pos + (data.vz * data.dt) + ((F * data.dt * data.dt) / (2 * data.m));
	return position_z;
}

/*
Obliczamy pr�dko�� cz�stki w nast�pnym kroku danym wzorem v = vo + (F * dt)/m
*/

long double X_Axis_Speed(input data)
{
	long double F, velocity_x;
	F = Electromagnetic_Force_X_Axis(data);
	velocity_x = data.vx + (((F / data.m) * data.dt));
	return velocity_x;
}

long double Y_Axis_Speed(input data)
{
	long double F, velocity_y;
	F = Electromagnetic_Force_Y_Axis(data);
	velocity_y = data.vy + (((F / data.m) * data.dt));
	return velocity_y;
}

long double Z_Axis_Speed(input data)
{
	long double F, velocity_z;
	F = Electromagnetic_Force_Z_Axis(data);
	velocity_z = data.vz + (((F / data.m) * data.dt));
	return velocity_z;
}

/*
Funkcja wy�wietlaj�ca informacje o si�ach dzia�aj�cych na cz�stk�.
*/

void Data_output_console(input data)
{
	printf("\n Fex = %.21lf", Electric_Field_Force_X_Axis(data));
	printf("\n Fey = %.21lf", Electric_Field_Force_Y_Axis(data));
	printf("\n Fez = %.21lf", Electric_Field_Force_Z_Axis(data));

	printf("\n Fmx = %.21lf", Lorentz_Force_X_Axis(data));
	printf("\n Fmy = %.21lf", Lorentz_Force_Y_Axis(data));
	printf("\n Fmz = %.21lf", Lorentz_Force_Z_Axis(data));

	printf("\n Fx = %.21lf", Electromagnetic_Force_X_Axis(data));
	printf("\n Fy = %.21lf", Electromagnetic_Force_Y_Axis(data));
	printf("\n Fz = %.21lf", Electromagnetic_Force_Z_Axis(data));
}

/*
Funkcja wy�wietlaj�ca aktualn� pozycj� cz�stki oraz jej pr�dko��.
*/
/*
void Output_console(input data)
{
printf("\n x pos = %.21lf", data.x_pos);
printf("\n y pos = %.21lf", data.y_pos);
printf("\n z pos = %.21lf", data.z_pos);

printf("\n x speed = %.21lf", data.vx);
printf("\n y speed = %.21lf", data.vy);
printf("\n z speed = %.21lf", data.vz);
}
*/
/*
Funkcja obliczaj�ca ca�kowit� pr�dko�� cz�stki poprzez obliczenie d�ugo�ci wektora pr�dkosci v = sqrt( vx^2 + vy^2 + vz^2 ).
*/
/*
void Total_Speed(input data)
{
double v;
v = data.vx * data.vx + data.vy * data.vy + data.vz * data.vz;
v = sqrt(v);
printf("\nPredkosc calkowita = %.21lf", v);
}
*/

/*
Funkcje od czyszczenia plik�w z danymi o symulacji.
*/

void Clear_Position_File()
{
	{
		FILE *plik = NULL;
		plik = fopen("pos.txt", "w");
		if (plik != NULL)
		{
			fclose(plik);
		}
		else
		{
			printf("\nBlad otwarcia pliku\n");
		}
	}
}

void Clear_Speed_File()
{
	{
		FILE *plik = NULL;
		plik = fopen("vel.txt", "w");
		if (plik != NULL)
		{
			fclose(plik);
		}
		else
		{
			printf("\nBlad otwarcia pliku\n");
		}
	}
}

/*
Funkcje kt�re zapisuj� dane do pliku.
*/

void File_Position_Output(input data)
{
	FILE *plik = NULL;
	plik = fopen("pos.txt", "a");
	if (plik != NULL)
	{

		fprintf(plik, "%.21lf %.21lf %.21lf\n", data.x_pos, data.y_pos, data.z_pos);
		fclose(plik);
	}
	else
	{
		printf("\nBlad otwarcia pliku\n");
	}
}

void File_Speed_Output(input data)
{
	FILE *plik = NULL;
	plik = fopen("vel.txt", "a");
	if (plik != NULL)
	{

		fprintf(plik, "%.21lf %.21lf %.21lf\n", data.vx, data.vy, data.vz);
		fclose(plik);
	}
	else
	{
		printf("\nBlad otwarcia pliku\n");
	}
}

/*
G��wny kod programu
*/

int main()
{
	//Deklaracja zmiennych pomocniczych wykorzystywanej w p�tli
	//i - zmienna pomocnicza
	//n - liczba krok�w, podawana przez u�ytkownika
	//menu - wyb�r opcji z menu
	//menu_loop - p�tla w menu
	int i, n, menu;
	int menu_loop = 1;
	//Deklaracja zmiennych pomocniczych kt�re przechowuj� tymczasowe obliczone warto�ci w przysz�ych krokach.
	long double velocity_x, velocity_y, velocity_z, position_x, position_y, position_z;
	input data;
	//Menu g��wne programu, wybieramy typ skal� symulacji.
	printf("Program do symulacji toru lotu czastki w jednorodnym polu elektromagnetycznym.\n");
	do
	{
		printf("Dla jakiej skali chcesz wykonac symulacje?\n 1. Skala Mikro \n 2. Skala Makro\n 3. Demo Skali Mikro\n 4. Demo Skali Makro\nOpcja: ");
		scanf(" %d", &menu);
		switch (menu)
		{
		case 1:
			//Skala mikroskopowa dla pojedy�czego atomu.
			data = data_input_micro();
			menu_loop = 0;
			break;
		case 2:
			//Skala makroskopowa dla wi�kszych obiekt�w np. kropla oleju.
			data = data_input_macro();
			menu_loop = 0;
			break;
		case 3:
			system("demomicro.plt");
			system("demomicro2.plt");
			break;
		case 4:
			system("demomacro.plt");
			system("demomacro2.plt");
			break;
		default:
			printf("Nieznana opcja.\n");
			break;
		}
	} 
	while (menu_loop == 1);
	//Wy�wietlamy informacje o si�ach
	Data_output_console(data);
	//Czy�cimy pliki z danymi o symulacji
	Clear_Position_File();
	Clear_Speed_File();
	//Podajemy liczb� krok�w
	printf("\n\nLiczba krokow: ");
	scanf(" %d", &n);
	//Rozpoczynamy p�tl� do obliczenia nowych warto�ci
	for (i = 0; i < n; i++)
	{
		//Wy�wietlamy numer kroku
		printf("\n\nKrok %d/%d\n", i + 1, n);
		/*
		Obliczamy pozycj� cz�stki i obliczone warto�ci przypisujemy do zmiennych pomocniczych.
		*/
		position_x = X_Axis_Position(data);
		position_y = Y_Axis_Position(data);
		position_z = Z_Axis_Position(data);
		/*
		Obliczamy pr�dko�� cz�stki, nast�pnie obliczone warto�ci przypisujemy do zmiennych pomocniczych.
		*/
		velocity_x = X_Axis_Speed(data);
		velocity_y = Y_Axis_Speed(data);
		velocity_z = Z_Axis_Speed(data);
		/*
		Obliczone warto�ci w krokach nadpisujemy z obecnymi w strukturze.
		*/
		data.vx = velocity_x;
		data.vy = velocity_y;
		data.vz = velocity_z;
		data.x_pos = position_x;
		data.y_pos = position_y;
		data.z_pos = position_z;
		/*
		Zapisujemy dane pozycji i pr�dko�ci cz�stki do plik�w.
		*/
		File_Position_Output(data);
		File_Speed_Output(data);
		/*
		Czy�cimy ekran
		*/
		system("cls");
	}
	//Uruchamiamy skrypt do wyznaczenia toru lotu cz�stki
	system("plot.plt");
	system("plot2.plt");
	printf("\n\n");
	//Ko�czymy program
	system("pause");
	return 0;
}