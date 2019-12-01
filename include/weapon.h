/*
** EPITECH PROJECT, 2019
** weapon.h
** File description:
** my_hunter : weapon (structure)
*/

#ifndef DEF_WEAPON
#define DEF_WEAPON

#include <stdlib.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include "pigeon.h"

typedef struct weapon {
    sfVector2f position;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect_sprite;
    sfClock *clock;
    sfSoundBuffer *sound_buff;
    sfSound *sound;
} weapon_t;

int create_weapon(weapon_t **weapon, char *filepath);
void make_wand_sparkle(weapon_t *weapon);
void make_wand_glow(weapon_t *weapon);
void destroy_weapon(weapon_t *weapon);

#endif // DEF_WEAPON