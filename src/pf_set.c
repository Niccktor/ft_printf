 #include "../inc/ft_printf.h"

void    pf_set_handel(t_pf_handel *handel)
{
    handel[0].c = 'c';
    handel[0].fnc = &pf_handeler_c;
    handel[1].c = 's';
    handel[1].fnc = &pf_handeler_s;
    handel[2].c = 'p';
    //handel[2].fnc = &pf_handeler_p;
    handel[3].c = 'd';
    //handel[3].fnc = &pf_handeler_d;
    handel[4].c = 'i';
    //handel[4].fnc = &pf_handeler_i;
    handel[5].c = 'o';
    //handel[5].fnc = &pf_handeler_o;
    handel[6].c = 'u';
    //handel[6].fnc = &pf_handeler_u;
    handel[7].c = 'x';
    //handel[7].fnc = &pf_handeler_x;
    handel[8].c = 'X';
    //handel[8].fnc = &pf_handeler_X;
    handel[9].c = '\0';
    //handel[9].fnc = &pf_handeler_unknow;
}

void    pf_reset_flag(t_pf_env *env)
{
    int i;

    i = -1;
    while (++i < 14)
        env->flag[i] = 0;
    env->flag[9] = -1;
    env->flag[i] = 0;
}