#include "APP/Init/Init_Interface.h"
#include "APP/SpotCounter/SpotCounter_Interface.h"
#include "APP/Idle/Idle_Interface.h"
#include "APP/ParkingManager/ParkingManager_Interface.h"

int main(void)
{
    App_Init();

    while(1)
    {
        ParkingManager_Run();
        Idle_Run();
    }

    return 0;
}