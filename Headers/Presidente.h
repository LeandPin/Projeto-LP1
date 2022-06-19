#ifndef PRESIDENTE_H
#define PRESIDENTE_H
#include "Funcionario.h"

#pragma once

class Presidente : public Funcionario
{
public:
    Presidente();
    ~Presidente();

    void aumentarSalario();
};

#endif