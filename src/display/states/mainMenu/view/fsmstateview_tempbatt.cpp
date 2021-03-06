/* Corresponding header inclusion */
#include "fsmstateview_tempbatt.h"

/* System includes */

/* Libraries includes */
#include <Arduino.h>

/* Project includes */
#include "variables_globales.h"
#include "common/trace.h"
#include "display/FSMContext.h"

#include "../../../FSMContext.h"
#include "../../FSMStateDefault.h"
//#include "../../../FSMAbstractState.h"

#include "../FSMStateMainMenu_View.h"
#include "FSMStateView_Back.h"

/* previous and next views */
#include "fsmstateview_tempambiante.h"
#include "fsmstateview_currcharge.h"

namespace Display
{
/* ########################################################################## */
/* ########################################################################## */

FSMStateView_TempBatt::FSMStateView_TempBatt(void)
    : FSMStateView_AbstractT()
    , Display::FSMAbstractState()
{
    return;
}


/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_TempBatt::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    TRACE("FSMStateView_TempBatt : Pressed button : ");
    TRACELN( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateView_TempAmbiante::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateView_CurrCharge::Instance() );
            break;


//        case    Keypad::BUTTON_UP:
//            FSMContext::Instance()->changeState(
//                        FSMStateMainMenu_View::Instance());


        default:
            break;
    }
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_TempBatt::on_state_enter(void)
{
    TRACELN( "Entering FSMStateView_TempBatt." );
    Display::g_LCD.clear();

    displayOnLCD("< Battery temp >", 0, 0);

    this->update_1s();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_TempBatt::on_state_exit(void)
{
    /* Nothing to do */
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_TempBatt::update_1s(void)
{
    displayOnLCD(g_sensors.batteryTemperature_c(), 0, 1, 2);
    displayOnLCD((char*)" *C          " );
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
