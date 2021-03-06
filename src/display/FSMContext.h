#ifndef FSMCONTEXT_H
#define FSMCONTEXT_H

/* Inherited classes */
#include "common/TSingleton.hpp"

/* System includes */

/* Libraries includes */
#include <LiquidCrystal.h>

/* Project includes */
#include "drivers/Keypad.h"

namespace Display {

class FSMAbstractState;

extern LiquidCrystal    g_LCD;
extern uint8_t          g_LCD_backlightValue;


/* ########################################################################## */
/* ########################################################################## */

class   FSMContext
        :   public TSingleton<FSMContext>
{
    friend class    TSingleton<FSMContext>;

public:

    void    changeState(FSMAbstractState* pFutureState);


    FSMAbstractState*   currentState(void) const;


    void    update_1s(void);
    void    update_50ms(void);


    void    on_button_pressed(const Keypad::TeButtonsID &pButtonID);



protected:
private:

    FSMContext(void);



public:
protected:
private:

    FSMAbstractState*   m_currentStatePtr;

};

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */

#endif  /*< FSMCONTEXT_H */
