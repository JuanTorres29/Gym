// Incluir las librerías necesarias
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <list>
#include <mmsystem.h>

// Usar el namespace estandar
using namespace std;

// Definir las teclas de movimiento
#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

/* Nota: falta documentar :O*/
/* Nota: en propiedades - vinculador - entrada 
   agregar winmm.lib para la música
*/

// Función para mover el cursor en la consola
void gotoxy(int x, int y)
{
	HANDLE hCon;
	// Recupera el control de la consola
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	// Establece las coordenadas
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}

// Función para ocultar el cursor
void ocultarCursor()
{
	HANDLE hCon;
	// Recupera el control de la consola
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 50;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(hCon, &cci);
}

// Función para pintar los límites del juego
void pintarLimite()
{
	for (int i = 2; i < 78; i++)
	{
		gotoxy(i, 3); printf("%c", 205);
		gotoxy(i, 33); printf("%c", 205);
	}
	for (int i = 4; i < 33; i++)
	{
		gotoxy(2, i); printf("%c", 186);
		gotoxy(77, i); printf("%c", 186);
	}
	gotoxy(2, 3); printf("%c", 201);
	gotoxy(2, 33); printf("%c", 200);
	gotoxy(77, 3); printf("%c", 187);
	gotoxy(77, 33); printf("%c", 188);
}

// Funciones para reproducir sonidos
void disparo()
{
	sndPlaySound("snd_disparo.wav", SND_ASYNC);
}
void lose()
{
	sndPlaySound("snd_lose.wav", SND_ASYNC);
}
void explosion()
{
	sndPlaySound("explosion.wav", SND_ASYNC);
}

// Clase para la nave del jugador
class NAVE
{
	int x, y;  // Posiciones de la nave
	int corazones;  // Salud de la nave
	int vidas;  // Vidas de la nave
public:
	NAVE();
	NAVE(int _x, int _y, int _corazones, int _vidas);  // Constructor
	void pintar();  // Función para pintar la nave
	void borrar();  // Función para borrar la nave
	void mover();  // Función para mover la nave
	void pintarCorazones();  // Función para pintar los corazones de salud
	void perderVida();  // Función para quitar una vida a la nave
	void dismunirCorazon(){ corazones--; }  // Función para disminuir los corazones
	int X(){ return x; }  // Obtener la posición x
	int Y(){ return y; }  // Obtener la posición y
	int vidasJugador(){ return vidas; }  // Obtener las vidas del jugador

};

// Constructor de la clase NAVE
NAVE::NAVE(int _x, int _y, int _corazones,int _vidas)
{
	x = _x;
	y = _y;
	corazones = _corazones;
	vidas = _vidas;
}

// Método que dibuja la nave
void NAVE::pintar()
{
	gotoxy(x, y); printf("  %c", 30);
	gotoxy(x, y + 1); printf(" %c%c%c", 40, 207, 41);
	gotoxy(x, y + 2); printf("%c%c %c%c", 30, 190, 190, 30);
}

// Método que borra la nave
void NAVE::borrar()
{
	gotoxy(x, y);     printf("         ");
	gotoxy(x, y + 1); printf("         ");
	gotoxy(x, y + 2); printf("         ");
}

// Método que maneja el movimiento de la nave
void NAVE::mover()
{
	if (_kbhit())
	{
		char tecla = _getch();
		borrar();
		if (tecla == IZQUIERDA && x > 3)
		{
			x--;
		}
		else if (tecla == DERECHA && x + 6 < 77)
		{
			x++;
		}
		else if (tecla == ARRIBA && y > 4 )
		{
			y--;
		}
		else if (tecla == ABAJO && y + 3 < 33  )
		{
			y++;
		}
		else if (tecla == 'e')
		{
			corazones--;
		}
		pintar();
		pintarCorazones();
	}
}

// Método para pintar los corazones (vida) de la nave
void NAVE::pintarCorazones()
{
	gotoxy(50, 2);
	printf("Vida: %d",vidas);
	gotoxy(64, 2);
	printf("Salud:");
	gotoxy(70, 2);
	printf("      ");
	for (int i = 0; i < corazones; i++)
	{
		gotoxy(70 + i, 2);
		printf("%c", 3);
	}
}

// Método que gestiona la pérdida de vida de la nave
void NAVE::perderVida()
{
	if (corazones == 0)
	{
		borrar();
		gotoxy(x, y);     printf("   **   ");
		gotoxy(x, y + 1); printf("  ****  ");
		gotoxy(x, y + 2); printf("   **   ");
		Sleep(200);
		borrar();
		gotoxy(x, y);     printf(" * ** *");
		gotoxy(x, y + 1); printf("  **** ");
		gotoxy(x, y + 2); printf(" * ** *");
		Sleep(200);
		borrar();
		vidas--;
		corazones = 3;
		pintarCorazones();
		pintar();
		explosion();
	}
}

// Clase para los asteroides
class Asteroide
{
	int x, y;  // Posiciones del asteroide
public:
	Asteroide(int _x, int _y);  // Constructor
	void pintar();  // Función para pintar el asteroide
	void mover();  // Función para mover el asteroide
	void colisionNave(NAVE &nave);  // Función para detectar la colisión con la nave
	int X(){ return x; }
	int Y(){ return y; }
};

// Constructor de la clase Asteroide
Asteroide::Asteroide(int _x, int _y)
{
	x = _x;
	y = _y;
}

// Método que dibuja el asteroide
void Asteroide::pintar()
{
	gotoxy(x, y); printf("%c", 184);
}

// Método que mueve el asteroide
void Asteroide::mover()
{
	gotoxy(x, y); printf(" ");
	y++;
	if (y > 32)
	{
		x = (rand() % 71) + 4;
		y = 4;
	}
	pintar();
}

// Método que gestiona la colisión del asteroide con la nave
void Asteroide::colisionNave(NAVE &nave)
{
	if (x >= nave.X() && x < nave.X() + 6 && y >= nave.Y() && y <= nave.Y() + 2)
	{
		nave.dismunirCorazon();
		nave.borrar();
		nave.pintar();
		nave.pintarCorazones();
		x = (rand() % 71) + 4;
		y = 4;
	}
}

// Clase para las balas
class Bala
{
	int x, y;  // Posiciones de la bala
public:
	Bala(int _x, int _y);  // Constructor
	void mover();  // Función para mover la bala
	bool fuera();  // Función para comprobar si la bala está fuera de la pantalla
	int X(){ return x; }
	int Y(){ return y; }
};

// Constructor de la clase Bala
Bala::Bala(int _x, int _y)
{
	x = _x;
	y = _y;
}

// Método que mueve la bala
void Bala::mover()
{
	gotoxy(x, y); printf(" ");
	y--;
	gotoxy(x, y); printf("*");
	
}

// Método que comprueba si la bala está fuera de la pantalla
bool Bala::fuera()
{
	if (y == 4) return true;
	return false;
	
}

// Función principal del programa
int main()
{
	ocultarCursor();
	pintarLimite();
	NAVE n(37,30,3,3);
	n.pintar();
	n.pintarCorazones();
	list<Asteroide*> A;
	list<Asteroide*>::iterator itA;
	int puntos = 0;

	// Creación de los asteroides
	for (int  i = 0; i < 5; i++)
	{
		A.push_back(new Asteroide(rand() % 75 + 3, rand() % 5 + 4));
	}

	list<Bala*> B;  // Lista de balas
	list<Bala*>::iterator it;
	bool gameOver = false;

	// Bucle principal del juego
	while (!gameOver)
	{	
		gotoxy(4, 2); printf("Puntos: %d", puntos);
		if(_kbhit())
		{
			char tecla = _getch();
			if (tecla == 'a' || tecla == 'A')
			{
				B.push_back(new Bala(n.X() + 2, n.Y() - 1));
				disparo();
			}
		}
		for (it = B.begin(); it != B.end(); it++)
		{
			(*it)->mover();
			if ((*it)->fuera())
			{
				gotoxy((*it)->X(), (*it)->Y()); printf(" ");
				delete(*it);
				it = B.erase(it);
			}
		}

		for (itA = A.begin(); itA != A.end(); itA++)
		{
			(*itA)->mover();
			(*itA)->colisionNave(n);
		}

		for (itA = A.begin(); itA != A.end(); itA++)
		{
			for (it = B.begin(); it != B.end(); it++)
			{
				if ((*itA)->X() == (*it)->X() && ((*itA)->Y() + 1 == (*it)->Y() || (*itA)->Y() == (*it)->Y()))
				{
					gotoxy((*it)->X(), (*it)->Y()); printf(" ");
					delete(*it);
					it = B.erase(it);
					A.push_back(new Asteroide(rand() % 74 + 3, 4));
					gotoxy((*itA)->X(), (*itA)->Y()); printf(" ");
					delete(*itA);
					itA = A.erase(itA);
					puntos += 5;
				}
			}
		}

		if (n.VIDAS() == 0) gameOver = true;

		n.mover();
		Sleep(30);
	}

	return 0;
}
