/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmoncier <lmoncier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:45:18 by lmoncier          #+#    #+#             */
/*   Updated: 2024/07/07 14:45:24 by lmoncier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

void     print_config(int *config){
    int     i;

    i = 0;
    while ( i < 10)
    {
        //write(1, &config[i] + 48, 1);
        printf("%d", config[i]);
        i++;
    }
    printf("\n");
    //write(1, "\n", 1);
}

int val_abs(int a){
    if (a < 0)
        return (-a);
    else
        return (a);
}

int     ft_check(int *config, int pos)
{
    // est ce que le numero est dejq utilisé ?
    // est il danq une diago ?
    int     i = 0;
    while (i < pos){
        //printf("config[i]: %d, i:%d config[pos]:%d pos:%d", config[i], i, config[pos], pos);
        if (config[i] == config[pos] ||
        val_abs(i - pos) == val_abs(config[i] - config[pos])){
            return (-1);
        }
        //(i - config[i]) == (pos - config[pos]))

        i++;
    }
    return (1);
}

void    ft_make_config(int *config, int pos, int *nbr_conf){
    // -1 = revenir au noeuds avant;
    // 1 = on continue
    int i = 0;
    while (i < 10) {
        config[pos] = i;
        if (ft_check(config, pos) == 1) {
            if (pos == 9) {
                print_config(config);
                (*nbr_conf) ++;
                return ;
                // TOTAL + 1 ?
            } else
                ft_make_config(config, pos + 1, nbr_conf);
        }
        i++;
    }
}


int     ft_ten_queens_puzzle(void)
{
    int     i;
    int     config[10];
    int     nbr_conf = 0;

    //nbr = {0,1, 2, 3, 4, 5, 6, 7, 8, 9};
    //config = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    ft_make_config(config, 0, &nbr_conf);
    return nbr_conf;
}

int main(){
    printf("%d", ft_ten_queens_puzzle());
}