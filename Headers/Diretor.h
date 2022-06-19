#ifndef DIRETOR_H
#define DIRETOR_H
#include "Funcionario.h"

#pragma once

class Diretor : public Funcionario
{
public:
    Diretor();
    ~Diretor();
    void aumentarSalario();
};

#endif