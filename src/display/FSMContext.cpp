/* Corresponding header inclusion */
#include "FSMContext.h"

/* System includes */

/* Libraries includes */

/* Project includes */
#include "FSMAbstractState.h"
#include "states/FSMStateDefault.h"


namespace Display {

/* ########################################################################## */
/* ########################################################################## */

FSMContext::FSMContext(void)
{
    /* Set the default state of the UI */
    this->m_currentStatePtr = FSMStateDefault::Instance();
}

/* ########################################################################## */
/* ########################################################################## */

void    FSMContext::changeState(FSMAbstractState *pFutureState)
{
    this->m_currentStatePtr->on_state_exit();

    this->m_currentStatePtr = pFutureState;
    this->m_currentStatePtr->on_state_enter();
}

/* ########################################################################## */
/* ########################################################################## */

FSMAbstractState*   FSMContext::currentState(void) const
{
    return this->m_currentStatePtr;
}

/* ########################################################################## */
/* ########################################################################## */

void FSMContext::updateDisplay()
{
    this->currentState()->updateDisplay();
}

/* ########################################################################## */
/* ########################################################################## */

}   /*< namespace Display */