#include "philo.h"

/*
# philosophers

IDEIAS E TAREFAS

validação de dados
- checar se houve algum input não numerico 
- checar numero de inputs 4 - 5

criação da mesa
- ter os n filosofos em uma lista linkada circular
- adicionar os garfos
- gravar a hora de criação de cada filosofo

a estrutura filosofo deve ter
-tempo de criação 
-tempo da ultima refeição
-mutex gafos

*/


int main (int argc, char **argv)
{
    if (!argc > 6 || !argc < 5)
    {
        check_num(argv);
        
    }
    else
    {
        write(2,"Error! wrong number of arguments", 32);
        exit(2);
    }

}