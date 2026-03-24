#include <stdio.h>
#include <windows.h> // Necesaria para GetAsyncKeyState

int main() {
    printf("Detectando teclas modificadoras (Presiona Esc para salir)...\n");

    while (1) {
        
        if (GetAsyncKeyState(VK_CONTROL) & 0x8000) {
            printf("¡Estas presionando CTRL!\n");
        }
        
        if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
            printf("¡Estas presionando SHIFT!\n");
        }

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            break; // Salir del bucle
        }

        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            printf("Precionaste flecha arriba!\n");
        }
        
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            printf("Precionaste flecha abajo!\n");
        }

        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            printf("Precionaste flecha izquierda!\n");
        }

        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            printf("Precionaste flecha derecha!\n");
        }

        Sleep(100); // Pausa de 100ms para no saturar el procesador
    }

    return 0;
}