/*
** EPITECH PROJECT, 2019
** weapon.c
** File description:
** my_hunter : functions handling weapon
*/

#include "include/weapon.h"

int create_weapon(weapon_t **weapon, char *filepath)
{
    *weapon = malloc(sizeof(weapon_t));
    if (*weapon == NULL)
        return (84);
    (*weapon)->position.x = (800 - 92) / 2;
    (*weapon)->position.y = 600 - 120;
    (*weapon)->texture = sfTexture_createFromFile(filepath, NULL);
    (*weapon)->sprite = sfSprite_create();
    (*weapon)->rect_sprite.top = 0;
    (*weapon)->rect_sprite.left = 0;
    (*weapon)->rect_sprite.width = 92;
    (*weapon)->rect_sprite.height = 160;
    (*weapon)->clock = sfClock_create();
    sfSprite_setTexture((*weapon)->sprite, (*weapon)->texture, sfTrue);
    return (0);
}

void make_wand_shine(weapon_t *weapon)
{
    sfTime time;
    float seconds = 0.0;

    time = sfClock_getElapsedTime(weapon->clock);
    seconds = sfTime_asSeconds(time);
    if (seconds > 0.1) {
        sfClock_restart(weapon->clock);
        if (weapon->rect_sprite.left == weapon->rect_sprite.width)
            weapon->rect_sprite.left = 0;
        else
            weapon->rect_sprite.left += weapon->rect_sprite.width;
        sfSprite_setTextureRect(weapon->sprite, weapon->rect_sprite);
    }
}

void destroy_weapon(weapon_t *weapon)
{
    sfTexture_destroy(weapon->texture);
    sfSprite_destroy(weapon->sprite);
    sfClock_destroy(weapon->clock);
    free(weapon);
}