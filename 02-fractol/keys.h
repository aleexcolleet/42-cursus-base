#ifndef KEYS_H
# define KEYS_H
# ifdef __linux__
#  define K_ESC			65307
#  define K_NUM_PLUS	65451
#  define K_NUM_MINUS	65453
#  define K_UP			65362
#  define K_DOWN		65364
#  define K_LEFT		65361
#  define K_RIGHT		65363
# else
#  define K_ESC			53
#  define K_NUM_PLUS	69
#  define K_NUM_MINUS	78
#  define K_UP			126
#  define K_DOWN		125
#  define K_LEFT		123
#  define K_RIGHT		124
# endif
#endif
