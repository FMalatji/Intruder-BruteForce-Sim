#include <stdio.h> 
#include <unistd.h> 

int main(void)
{
    // --- ANSI COLOR CODES ---
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

    // 2. TARGET INPUT
    int pin;
    
    printf("Set Target PIN (0000-9999): ");
    
    // We check if the input is valid (scanf returns 1 if it successfully read a number)
    if (scanf("%d", &pin) != 1) 
    {
        printf("%s[!] Error: Invalid input. Exiting.\n%s", RED, RESET);
        return 1;
    }

    // Validation logic to ensure it stays within 4 digits
    if (pin < 0 || pin > 9999)
    {
        printf("%s[!] Error: PIN must be between 0000 and 9999.\n%s", RED, RESET);
        return 1;
    }
    // 0.5 second pause for dramatic effect
    printf("\n%s[!] INITIALIZING BRUTE FORCE ATTACK...%s\n", RED, RESET);
    usleep(500000);
    

    // 3. The Attack Loop
    for (int i = 0; i <= 9999; i++)
    {
        // \r returns the cursor to the start of the line so it updates in place
        printf("\r%s[*] Testing PIN combination: %04i%s", RED, i, RESET);
        
        // Force the print to happen immediately
        fflush(stdout); 
        
        // Small delay for dramatic effect
        usleep(500); 

    // 4. Check for Match
    // exit loop once found
        if (i == pin)
        {
            printf("\n\n");
            printf("%s[+] PASSWORD CRACKED SUCCESSFULLY!%s\n", GREEN, RESET);
            printf("%s[+] MATCH FOUND: %04i%s\n", GREEN, i, RESET);
            break;
        }
    }

    return 0;
}
