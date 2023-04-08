#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int choice;

    // Load display and keyboard


    printf("Choose an unlock sound:\n");
    printf("1. Default achievement unlock sound\n");
    printf("2. Xbox achievement unlock sound\n");
    printf("3. Playstation trophy unlock sound\n");
    printf("4. SMW 1up sound\n");
    printf("5. SMW coin sound\n");
    printf("6. SMW egg hatch sound\n");
    printf("7. SMW message block sound\n");
    printf("8. SMW mid gate sound\n");
    printf("9. SMW power up sound\n");
    printf("10. SMW save menu sound\n");
    printf("Enter your choice (1-3): ");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Default achievement unlock sound selected.\n");
            // End the program
            break;
        case 2:
            printf("Xbox achievement unlock sound selected.\n");
            // Move xboxunlock.ogg file from /mnt/SDCARD/unlock to /mnt/SDCARD/RetroArch/.retroarch/assets
            system("rm -rf /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            system("mv /mnt/SDCARD/unlock/xboxunlock.ogg /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            break;
        case 3:
            printf("Playstation trophy unlock sound selected.\n");
            // Move psunlock.ogg file from /mnt/SDCARD/unlock to /mnt/SDCARD/RetroArch/.retroarch/assets
            system("rm -rf /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            system("mv /mnt/SDCARD/unlock/psunlock.ogg /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            break;
        case 4:
            printf("SMW 1up sound selected.\n");
            // Move 1up.ogg file from /mnt/SDCARD/unlock to /mnt/SDCARD/RetroArch/.retroarch/assets
            system("rm -rf /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            system("mv /mnt/SDCARD/unlock/1up.ogg /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            break;
        case 5:
            printf("SMW coin sound selected.\n");
            // Move coin.ogg file from /mnt/SDCARD/unlock to /mnt/SDCARD/RetroArch/.retroarch/assets
            system("rm -rf /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            system("mv /mnt/SDCARD/unlock/coin.ogg /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            break;
        case 6:
            printf("SMW egg hatch sound selected.\n");
            // Move xboxunlock.ogg file from /mnt/SDCARD/unlock to /mnt/SDCARD/RetroArch/.retroarch/assets
            system("rm -rf /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            system("mv /mnt/SDCARD/unlock/egghatch.ogg /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            break;
        case 7:
            printf("SMW message block sound selected.\n");
            // Move psunlock.ogg file from /mnt/SDCARD/unlock to /mnt/SDCARD/RetroArch/.retroarch/assets
            system("rm -rf /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            system("mv /mnt/SDCARD/unlock/messageblock.ogg /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            break;
        case 8:
            printf("SMW mid gate sound selected.\n");
            // Move xboxunlock.ogg file from /mnt/SDCARD/unlock to /mnt/SDCARD/RetroArch/.retroarch/assets
            system("rm -rf /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            system("mv /mnt/SDCARD/unlock/midgate.ogg /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            break;
        case 9:
            printf("SMW power up sound selected.\n");
            // Move psunlock.ogg file from /mnt/SDCARD/unlock to /mnt/SDCARD/RetroArch/.retroarch/assets
            system("rm -rf /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            system("mv /mnt/SDCARD/unlock/powerup.ogg /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            break;
        case 10:
            printf("SMW save menu sound selected.\n");
            // Move psunlock.ogg file from /mnt/SDCARD/unlock to /mnt/SDCARD/RetroArch/.retroarch/assets
            system("rm -rf /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            system("mv /mnt/SDCARD/unlock/savemenu.ogg /mnt/SDCARD/RetroArch/.retroarch/assets/sounds/unlock.ogg");
            break;
        default:
            printf("Invalid choice.\n");
            // End the program
            break;
    }

    return 0;
}
