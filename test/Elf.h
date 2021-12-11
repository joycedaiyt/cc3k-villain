#ifndef ELF_H
#define ELF_H
#include "Enemy.h"

class Elf: public Enemy {
    public:
    Elf(int x_cor, int y_cor);
    ~Elf();
    char get_symbol() override;
};

#endif
