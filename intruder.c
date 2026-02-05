#include <stdio.h>  // Standard Input/Output (printf, scanf)
#include <unistd.h> // For usleep

int main(void)
{
    // --- STANDARD C STRINGS ---
    // Instead of 'string', we use 'const char *' (Pointer to characters)
    const char *GREEN = "\033[0;32m";
    const char *RED = "\033[0;31m";
    const char *RESET = "\033[0m";

    // 1. ASCII ART HEADER
    printf("%s", GREEN);
    printf("========================================\n");
    printf("      I N T R U D E R   v 3 . 0         \n");
    printf("      (Standalone Edition)              \n");
    printf("========================================\n");
    printf("%s", RESET);

    // 2. STANDARD INPUT (The biggest change)
    int pin;
    
    printf("Set Target PIN (0000-9999): ");
    
    // scanf reads an integer ("%d") and stores it at the ADDRESS of 'pin' (&pin)
    // We check if the input is valid (scanf returns 1 if it successfully read a number)
    if (scanf("%d", &pin) != 1) 
    {
        printf("%s[!] Error: Invalid input. Exiting.\n%s", RED, RESET);
        return 1;
    }

    // Simple validation logic
    if (pin < 0 || pin > 9999)
    {
        printf("%s[!] Error: PIN must be 0000-9999.\n%s", RED, RESET);
        return 1;
    }

    printf("\n%s[!] INITIALIZING BRUTE FORCE ATTACK...%s\n", RED, RESET);
    usleep(500000); 

    // 3. The Attack Loop (Same Logic)
    for (int i = 0; i <= 9999; i++)
    {
        printf("\r%s[*] Testing PIN combination: %04i%s", RED, i, RESET);
        fflush(stdout); // FORCE the print to happen immediately (standard C can be lazy with printing)
        
        usleep(500); 

        // 4. Check for Match
        if (i == pin)
        {
            printf("\n\n");
            printf("%s[+] PASSWORD CRACKED SUCCESSFULLY!%s\n", GREEN, RESET);
            printf("%s[+] MATCH FOUND: %04i%s\n", GREEN, i, RESET);
            printf("========================================\n");
            return 0;
        }
    }
}