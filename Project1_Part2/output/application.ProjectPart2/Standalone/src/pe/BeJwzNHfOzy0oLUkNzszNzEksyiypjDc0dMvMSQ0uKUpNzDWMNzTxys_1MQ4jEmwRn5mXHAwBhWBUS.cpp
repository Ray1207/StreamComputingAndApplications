// eJxjdCwtyWdkNGF0zs8tKC1JDc7MzcxJLMosqWR0y8xJDS4pSk3MNWT0ys_1MQ_1AZgzPzsgE1FhQH


#include "BeJwzNHfOzy0oLUkNzszNzEksyiypjDc0dMvMSQ0uKUpNzDWMNzTxys_1MQ4jEmwRn5mXHAwBhWBUS.h"
#include <dst-config.h>
#include <SPL/Runtime/Utility/BackoffSpinner.h>


using namespace SPL;

extern int PE_Version;

#define MYPE BeJwzNHfOzy0oLUkNzszNzEksyiypjDc0dMvMSQ0uKUpNzDWMNzTxys_1MQ4jEmwRn5mXHAwBhWBUS



MYPE::MYPE(bool isStandalone/*=false*/) 
    : SPL::PE(isStandalone, NULL)
{
   PE_Version = 3100;
   BackoffSpinner::setYieldBehaviour(BackoffSpinner::Auto);
}



MAKE_PE(SPL::MYPE);
