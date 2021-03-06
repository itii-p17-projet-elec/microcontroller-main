/* Corresponding header inclusion */
#include "fsmstateview_currconsobatt.h"

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
#include "fsmstateview_currdecharge.h"
#include "fsmstateview_voltage.h"

namespace Display
{

/* ########################################################################## */
/* ########################################################################## */

FSMStateView_CurrConsoBatt::FSMStateView_CurrConsoBatt(void)
    : FSMStateView_AbstractCurr()
{
    return;
}


/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrConsoBatt::on_button_pressed(const Keypad::TeButtonsID &pButtonID)
{
    FSMAbstractState::on_button_pressed(pButtonID);

    TRACE("FSMStateView_CurrConsoBatt : Pressed button : ");
    TRACELN( Keypad::buttonName(pButtonID) );


    switch( pButtonID )
    {
        case    Keypad::BUTTON_LEFT:
            FSMContext::Instance()->changeState(
                        FSMStateView_CurrDecharge::Instance() );
            break;


        case    Keypad::BUTTON_RIGHT:
            FSMContext::Instance()->changeState(
                        FSMStateView_Voltage::Instance() );
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

void    FSMStateView_CurrConsoBatt::on_state_enter(void)
{
    TRACELN( "Entering FSMStateView_CurrConsoBatt." );
    Display::g_LCD.clear();

    displayOnLCD("< Curr Cons.Batt >", 0, 0);

    this->update_1s();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrConsoBatt::on_state_exit(void)
{
    /* Nothing to do */
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMStateView_CurrConsoBatt::update_1s(void)
{
    displayOnLCD((char*)"?? C          ");
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */
