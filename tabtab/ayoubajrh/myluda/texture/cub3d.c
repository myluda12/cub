/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 21:57:55 by ayajrhou          #+#    #+#             */
/*   Updated: 2019/10/31 22:14:02 by ayajrhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

#define K_UP 65362
#define K_DOWN 65364
#define K_LEFT 65361
#define K_RIGHT 65363

void *mlx_ptr;
void *win_ptr;
char **map;
int width = 1500;
int height = 1000;
//design morba3 (map 2D)
char **line;
int y_len;
int x;
int y;
int k = 0;
int remaind = 50;
int none = 1;
//wall
int wall = 50;
int x_len_map;

int swiitch = 1;
// Player movement
int X_player;
int Y_player;   
int radian = 3;
float rotationAngle = - (M_PI / 2);
float rotationSpeed = 1;
int len_angle = 30;
float turnDirection = 0;
int walkDirection = 0;
int j;
float rotation;

float rot;
//DATA COLLECTION FOR IMAGE 
int g_a;
int g_b;
int g_c;
int *g_data;
void *g_image;


//int k = 0;
//Remainding the old position of X && Y Player
int Y_remainder;
int X_remainder;
//Ray Intersaction && steps
 float xintercept;
 float yintercept;

 float ystep;
 float xstep;

 float nextHoriX;
 float nextHoriY;
 //check if wall is hited
 float wallHoriHit;
 float wallVertHit;
 float HorizwallHitX;
 float HorizwallHitY;
 float VertwallHitX;
 float VertwallHitY;
 
 //delete
 int pc = 0;

 float WallHitX;
 float WallHitY;
// Ray Direction 
int rayFacingDown;
int rayFacingUp;
int rayFacingRight;
int rayFacingLeft;

// Distance between Vertical && Horizontal
float HorzHitDistance;
float VertHitDistance;
float distance;
float wasHitVertical;
//COLOR RENDERING
int alpha;
//key UP / DOWN
int up;
int down;
int left;
int right;
//Rendering 3D MAP
float correctWallDistance;
float distanceProjectionPlan;
float wallStripHeight;
float WallStripWidth = 1;
//color
unsigned int DarkColor;
//bullshit variables for data (LEARN LATER)
int tab[20];
void *img1;
void *img2;
void *img3;
void *img4;
unsigned int *textu0;
unsigned int *textu1;
unsigned int *textu2;
unsigned int *textu3;
unsigned int *achraf4;
float xOfsset;
float yOffset;
int g_mhah;
float g_pourcent;
int copystart;
int g_rightleftupdown;
//The Raycasting variables
//indicateur pour le stockage
int g_f;
//float isRaydown = ;
int calculparam_x = 50 / 2;
int calculparam_y = 50 / 2;
    int sprite;
int distance_center;
int sprite_indicator;

//// SAVE X AND Y CENTER;
int center_x;
int center_y;

////////////
int sprite_number;

typedef struct s_sprite
{
float wallVertHit;
float VertwallHitX;
float VertwallHitY;
float wallHoriHit;
float HorizwallHitX;
float HorizwallHitY;
float g_mhah;
float wasHitVertical;
float VertHitDistance;
float HorzHitDistance;
float WallHitX;
float WallHitY;
float xcentre;
float ycentre;
float distance;
float rotation;
float x;
float y;
float xoff;
}               t_sprite;
t_sprite sprites[1000], sprites_temp;

typedef struct s_spritefinder
{
    float point_x;
    float point_y;
    float point_distance_x;
    float point_distance_y;
    float new_angle;
    float x_offset;
    float angle_sghira;
    float angle_kbira;
    float angle_wanted;
    float angle_jdida;
    float center_x;
    float center_y;
}               t_spritefinder;
t_spritefinder finder;

int sprite_count;
typedef struct s_mapcount
{
    int mapx;
}               t_mapcount;
t_mapcount mapcount[1000];

int inde;

int     design_morba3(int i, unsigned int color, char **line, int j)
{
    int save;
    int y_copy;

    y_copy = y;
    save = k;

   // i = i + 1;

    while (k < x)
    {
        if(swiitch == 0)
            mlx_pixel_put(mlx_ptr, win_ptr, k, y, color);
        k++;
        if (k == x)
        {
            k = save;
            y = y - 1;
            if (y == remaind - wall - 1)
            {
                k += wall;
                break;
                }
            }
    }

    if (line[j][i] == 'N' && none == 1)
    {
        if (swiitch == 1)
            mlx_pixel_put(mlx_ptr, win_ptr, k, y, 0x000000);
        X_player = k;
        Y_player = y;
        none++;
    }
    y = y_copy;
    x = x + wall;
    return k;
}
void	sorting(void)
{
	int indd;
	int j;

	indd = 1;
	j = 0;
	while (indd < sprite_count)
	{
		while (j < sprite_count - indd)
		{
			if (sprites[j].distance > sprites[j + 1].distance)
			{
				sprites_temp = sprites[j];
				sprites[j] = sprites[j + 1];
				sprites[j + 1] = sprites_temp;
			}
			j++;
		}
		j = 0;
		indd++;
	}
}
void ft_morba3(char **line)
{
    int i;
    unsigned int color;
    sprite_number = 0;

   
    i = 0;
    j = 0;
    while(line[j][i])
    {
        if (line[j][i] == '1')
        {
            color = 0x6f665d;
            design_morba3(i, color, line, j);
        }
        else if(line[j][i] == '0' || line[j][i] == 'N')
        {
            color = 0xFFFFFF;
            design_morba3(i, color, line, j);
        }
        else if(line[j][i] == '2')
        {
            color = 0xdcd3f6;
            design_morba3(i, color, line, j);
            sprite_number++;
        }
        i++;
        if (line[j][i] == '\0')
        {
            i = 0;
            if (line[j + 1] != NULL)
            {
                j++;
                y = y + wall;
                x = wall;
                remaind = remaind + wall;
                k = 0;
            }
            else
                break;
        }    
    }
}





int abs (int n)
{ 
    return ( (n>0) ? n : ( n * (-1))); 
}

unsigned int    *ft_texture(char     *file, unsigned int *texture)
{
    int c = 63;
    int i= 0;
    img1 = mlx_xpm_file_to_image(mlx_ptr,file,&tab[g_f],&tab[g_f + 1]);
    texture = (unsigned int *)mlx_get_data_addr(img1,&tab[g_f + 2],&tab[g_f + 3], &tab[g_f + 4]);
    g_f = g_f + 5;
    return texture;
}

void     text(void)
{
    g_f = 0;
    textu0 = ft_texture("eagle.xpm", textu0);
    textu1 = ft_texture("ayoub.xpm", textu1);
    textu2 = ft_texture("hani.xpm", textu2);
    textu3 = ft_texture("maroc.xpm", textu3);
    //achraf4 = ft_texture("eagle.xpm",achraf4);
}

//DDA Function for line generation 
void DDA(int X0, int Y0, int X1, int Y1) 
{ 
    // calculate dx & dy 
    int dx = X1 - X0; 
    int dy = Y1 - Y0; 
  
    // calculate steps required for generating pixels 
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float) steps; 
    float Yinc = dy / (float) steps; 
  
    // Put pixel for each step 
    float X = X0; 
    float Y = Y0; 
    for (int i = 0; i <= steps; i++) 
    { 
       
        if(X >= 0 && X <= mapcount[6].mapx * 50 && Y >= 0 && Y <= inde * 50)
        {
            if(swiitch == 0)
           mlx_pixel_put(mlx_ptr, win_ptr, X, Y, 0xFF0000);
        }
        X += Xinc;           // increment in x at each step 
        Y += Yinc;           // increment in y at each step 
         // for visualization of line- 
                             // generation step by step 
    } 
} 
//FUNCTION TO COVERT HEXA TO RGB
unsigned int    convert_rgb(int r, int g, int b)
{
    unsigned int color;
    color = r;
    color = (color << 8) + g;
    color = (color << 8) + b;
    return (color);
} 
unsigned int    check_opacity(unsigned int hexcolor)
{
    double red;
    double green;
    double blue;
    float oppasity;

    oppasity = (distance / 822) > 1 ? 1 : 1 - (distance / 822) ;
    red = ((hexcolor >> 16) & 255) * oppasity;
    green = ((hexcolor >> 8) & 255) * oppasity;
    blue = (hexcolor & 255) * oppasity;
    return (convert_rgb(red, green, blue));
}

int wall_checker()
{
    int X_pos;
    int Y_pos;

    X_pos = nextHoriX / wall;
    Y_pos = nextHoriY / wall;
    //printf("\n|==>|'%c'||\n",line[Y_pos][X_pos]);
    if ((X_pos >= 0 &&  X_pos < mapcount[6].mapx) && (Y_pos >= 0 &&  Y_pos < inde))
    {
        if (line[Y_pos][X_pos] == '2')
        {
            sprite = 1;
            sprite_indicator = 1;
        }
        if (line[Y_pos][X_pos] == '1')
            return (1);
        
    }
    return 0;

}
 int wall_collision()
{
    int X_pos;
    int Y_pos;

    X_pos = X_remainder / wall;
    Y_pos = Y_remainder / wall;
   // printf("\n|==>|'%c'||\n",line[Y_pos][X_pos]);
    if (line[Y_pos][X_pos] == '1' || line[Y_pos][X_pos] == '2')
    {
        return (1);
    }
    return 0;

}

float ft_normalize_angle(float angle)
{
    while (angle > 2 * M_PI)
        angle -= 2 * M_PI;
    if (angle < 0)
    {
        angle += (2 * M_PI);
    }
    return (angle);
}

void ft_nizar_calcul()
{
     if(g_mhah)
    {
        if (rayFacingDown)
        {
           g_rightleftupdown = 1;
        }
        else if (rayFacingUp)
        {
          g_rightleftupdown = 2;
        }
    }
    else if(!g_mhah)
    {
        if (rayFacingLeft)
        {
           g_rightleftupdown = 3;
        }
        else if (rayFacingRight)
        {
           g_rightleftupdown = 4;
        }
    }
}
void render_column1(int i, int count)
{
        int start;
    int j;
    int p = 0;
    j = 0;
    start = (height / 2) - (wallStripHeight / 2);
   // unsigned int colorr;
    //if (start < 0)
       // start = 0;
    // modification is here
    
    while(j < start)
    {
        g_data[width * j + i] = 0x00FFFF;//+ pc;
         j++;
    }
    
    //printf("%f\n",finder.x_offset);
    while(j < start + wallStripHeight && j < height)
    {
        g_pourcent = (j - start) / wallStripHeight;
            yOffset = 50 * g_pourcent;
        
            if(check_opacity(textu0[(int)yOffset * 50 + (int)sprites[count].xoff]) != 0x000000)
            {
               // printf("%d\n",count);
                g_data[width * j + i] = check_opacity(textu0[(int)yOffset * 50 + (int)sprites[count].xoff]);
                //printf("1\n");
            }
            if(swiitch == 0)
                mlx_pixel_put(mlx_ptr,win_ptr,i,j,0x006400);
        j++;
    }
    while(j < height)
    {
         g_data[width * j + i] = 0x808080;// + pc;
         j++;
    }
;

}
void render_colomn(int i)
{
    int start;
    int j;
    int p = 0;
    j = 0;
    start = (height / 2) - (wallStripHeight / 2);
    //if (start < 0)
       // start = 0;
    // modification is here
    
    while(j < start)
    {
        g_data[width * j + i] = 0x00FFFF;
         j++;
    }
    while(j < start + wallStripHeight && j < height)
    {
        g_pourcent = (j - start) / wallStripHeight;
            yOffset = 50 * g_pourcent;
            if(g_rightleftupdown == 1)
            {
                g_data[width * j + i] = check_opacity(textu0[(int)yOffset * 50 + (int)xOfsset]);
                //printf("1\n");
            }
            else if(g_rightleftupdown == 2)
            {
                g_data[width * j + i] = check_opacity(textu1[(int)yOffset * 50 + (int)xOfsset]);
                //printf("2\n");
            }
            else if(g_rightleftupdown == 3)
            {
                g_data[width * j + i] = check_opacity(textu2[(int)yOffset * 50 + (int)xOfsset]);
                //printf("3\n");
            }
            else if(g_rightleftupdown == 4)
            {
                g_data[width * j + i] = check_opacity(textu3[(int)yOffset * 50 + (int)xOfsset]);
               // printf("4\n");
            }
         /*   else if(sprite == 1)
            {
                g_data[1000 * j + i] = 0;

            } */

            if(swiitch == 0)
                mlx_pixel_put(mlx_ptr,win_ptr,i,j,0x006400);
        j++;
    }
    while(j < height)
    {
         g_data[width * j + i] = 0x808080;
         j++;
    }
;
}
void render_map3D(int i)
{
    correctWallDistance = distance * cos(rotation - rotationAngle);
   // alpha = 80 / correctWallDistance;
    distanceProjectionPlan = (width / 2) / tan(rad(45) / 2); //here delete cos
    wallStripHeight = (50 / correctWallDistance) * distanceProjectionPlan;
    xOfsset = g_mhah == 1 ? fmod(WallHitX,50) : fmod(WallHitY,50);
           ft_nizar_calcul();
        //Modification here 2  
        if(swiitch == 1)
            render_colomn(i);
}
int ray_Direction()
{
    rayFacingDown = 0;
    rayFacingUp = 0;
    rayFacingRight = 0;
    rayFacingLeft = 0;

    rayFacingDown = (deg(rotation) > 0 && deg(rotation) < 180) ? 1 : 0;
    rayFacingUp = !(rayFacingDown) ? 1 : 0;

    rayFacingRight = ((deg(rotation) > 0 && (deg(rotation) < 90)) || (deg(rotation) > 270 && (deg(rotation) < 360))) ? 1 : 0;
    rayFacingLeft = !(rayFacingRight) ? 1 : 0;
    // printf("%d\n",rayFacingUp);
     //printf("%f\n",deg(rotation));
     return 0;

}
float Distance_between_HorVer(int x1,int y1, int x2, int y2)
{
    return sqrtf(powf((x2 - x1),2) + powf((y2 - y1),2));
}

int ft_cast_ray(int index)
{
    WallHitX = 0;
    WallHitY = 0;
    distance = 0;
    sprite = 0;
    int i = 0;
    sprite_indicator = 0;
    int stop = 1;
    int check;
    wallHoriHit = 0;
    ray_Direction();

    yintercept = (int)(Y_player / wall) * wall;
    yintercept += rayFacingDown ? wall : 0;
    xintercept = X_player + (yintercept - Y_player) / tan(rotation);

    ystep = wall;
    ystep *= rayFacingUp ? -1 : 1;

    // ==> 
    xstep = ystep / tan(rotation);
    // ==>
    //xstep *= (rayFacingLeft && xstep > 0) ? -1 : 1;
    //xstep *= (rayFacingRight && xstep < 0) ? -1 : 1;

    nextHoriX = xintercept;
    nextHoriY = yintercept;

    if(rayFacingUp)
        nextHoriY--;
        //increment x & y step until we find  a wall
    while(nextHoriX >= 0 && nextHoriX < mapcount[6].mapx * 50 && nextHoriY >= 0 && nextHoriY < inde * 50)
    {
        sprite = 0;
        check = wall_checker();
        // if(sprite_count > 6)
        //     exit(0);
        if(sprite == 1)
        {
            sprites[sprite_count].xcentre = ((int)nextHoriX / 50 * 50) + 25;
            sprites[sprite_count].ycentre = ((int)nextHoriY / 50 * 50) + 25;
            sprites[sprite_count].x = nextHoriX;
            sprites[sprite_count].y = nextHoriY;
            sprites[sprite_count].distance =  sqrtf(powf(Y_player - sprites[sprite_count].y,2) + powf(X_player - sprites[sprite_count].x,2));
            sprites[sprite_count].rotation = atan2(Y_player - nextHoriY,  X_player - nextHoriX);
            sprite_count++;

        }
        if (check == 1)
        {
            wallHoriHit = 1;
            HorizwallHitX = nextHoriX;
            HorizwallHitY = nextHoriY;
            //DDA(X_player, Y_player,  HorizwallHitX, HorizwallHitY);
            break;
        }
        else
        {
            nextHoriX += xstep;
            nextHoriY += ystep; 
        }
    }
    // VERITICAL RAYCAST
    //sprites[sprite_count].
    wallVertHit = 0;
    ray_Direction();
    xintercept = (int)(X_player / wall) * wall;
    xintercept += rayFacingRight ? wall : 0;
    yintercept = Y_player - (X_player - xintercept) * tan(rotation);

    xstep = wall;
    xstep *= rayFacingLeft ? -1 : 1;
    // ==>
    ystep = xstep * tan(rotation);
    // == <
    //ystep *= (rayFacingUp && ystep > 0) ? -1 : 1;
    //ystep *= (rayFacingDown && ystep < 0) ? -1 : 1;

    nextHoriX = xintercept;
    nextHoriY = yintercept;

    if(rayFacingLeft)
        nextHoriX--;

    while(nextHoriX >= 0 && nextHoriX < mapcount[6].mapx * 50 && nextHoriY >= 0 && nextHoriY < inde * 50)
    {
        sprite = 0;
        check = wall_checker();
        if(sprite == 1)
        {
            sprites[sprite_count].xcentre = ((int)nextHoriX / 50 * 50) + 25;
            sprites[sprite_count].ycentre = ((int)nextHoriY / 50 * 50) + 25;
            sprites[sprite_count].rotation = atan2(Y_player - nextHoriY,  X_player - nextHoriX);
            sprites[sprite_count].x = nextHoriX;
            sprites[sprite_count].y = nextHoriY;
            sprites[sprite_count].distance =  sqrtf(powf(Y_player - sprites[sprite_count].y,2) + powf(X_player - sprites[sprite_count].x,2));
            sprite_count++;

        }
        if (check == 1)
        {
            wallVertHit = 1;
            VertwallHitX = nextHoriX;
            VertwallHitY = nextHoriY;
          //  DDA(X_player, Y_player,  HorizwallHitX, HorizwallHitY);
            break;
        }
        else
        {
            nextHoriX += xstep;
            nextHoriY += ystep; 
        }
    }

    // The Distance between vert and horizontal distances and precist the smallest value

    HorzHitDistance = (wallHoriHit) ? Distance_between_HorVer(X_player , Y_player, HorizwallHitX,HorizwallHitY) : MAX_INT;
    VertHitDistance = (wallVertHit) ? Distance_between_HorVer(X_player , Y_player, VertwallHitX,VertwallHitY) : MAX_INT;
// store the smallest of the distances

    WallHitX = (HorzHitDistance) < (VertHitDistance) ? HorizwallHitX : VertwallHitX;
    WallHitY = (HorzHitDistance) < (VertHitDistance) ? HorizwallHitY : VertwallHitY;
    distance = (HorzHitDistance) < (VertHitDistance) ? HorzHitDistance : VertHitDistance;
    g_mhah = distance == HorzHitDistance ? 1 : 0;
    wasHitVertical = (VertHitDistance) < (HorzHitDistance);
    
   // printf("%f\n",distance);
    DarkColor = 0x006400;
    DarkColor = check_opacity(DarkColor);
    
    //     sprites[sprite_count].HorzHitDistance = (sprites[sprite_count].wallHoriHit) ? Distance_between_HorVer(X_player , Y_player, sprites[sprite_count].HorizwallHitX,sprites[sprite_count].HorizwallHitY) : MAX_INT;
    //    // mlx_pixel_put(mlx_ptr,win_ptr,sprites[sprite_count].HorizwallHitX,sprites[sprite_count].HorizwallHitY,0x000000);
    //     sprites[sprite_count].VertHitDistance = (sprites[sprite_count].wallVertHit) ? Distance_between_HorVer(X_player , Y_player, sprites[sprite_count].VertwallHitX,sprites[sprite_count].VertwallHitY) : MAX_INT;
    //    // printf("Hor ==> |%f|||||| Vert == >|%f| \n",sprites[sprite_count].HorzHitDistance, sprites[sprite_count].VertHitDistance);
    //     sprites[sprite_count].WallHitX = (sprites[sprite_count].HorzHitDistance) < (sprites[sprite_count].VertHitDistance) ? sprites[sprite_count].HorizwallHitX : sprites[sprite_count].VertwallHitX;
    //     sprites[sprite_count].WallHitY = (sprites[sprite_count].HorzHitDistance) < (sprites[sprite_count].VertHitDistance) ? sprites[sprite_count].HorizwallHitY : sprites[sprite_count].VertwallHitY;
    //     finder.center_x = (int)(sprites[sprite_count].WallHitX / 50) * 50 + 25;
    //     finder.center_y = (int)(sprites[sprite_count].WallHitY / 50) * 50 + 25;
    //     distance_center = sqrtf(powf(Y_player - finder.center_y,2) + powf(X_player - finder.center_x,2));
    //     sprites[sprite_count].distance = (sprites[sprite_count].HorzHitDistance) < (sprites[sprite_count].VertHitDistance) ? sprites[sprite_count].HorzHitDistance : sprites[sprite_count].VertHitDistance;
        // sprites[sprite_count].g_mhah = sprites[sprite_count].distance == sprites[sprite_count].HorzHitDistance ? 1 : 0;
        // sprites[sprite_count].wasHitVertical = (sprites[sprite_count].VertHitDistance) < (sprites[sprite_count].HorzHitDistance);

        
        //mlx_pixel_put(mlx_ptr,win_ptr,center_x,center_y,0x000000);
        //printf("center X ==> |%d\n|",center_x);
        //printf("center Y ==> |%d\n|",center_y);
       // printf("%f\n",finder.x_offset);
    //}   
    //printf("|%d\n|",inde);
    DDA(X_player,Y_player,WallHitX,WallHitY);
    //printf("%f\n",finder.x_offset);

   return 0;
}

int mlx_key_press(int key)
{
    if(key == 123)
        left = 1;
    if (key == 124)
        right = 1;
    if (key == 125)
        down = 1;
    if (key == 126)
        up = 1;
    return 0;
}
int key_release(int key)
{
    if(key == 123)
        left = 0;
    if(key == 124)
        right = 0;
    if (key == 125)
        down = 0;
    if (key == 126)
        up = 0;
    return 0;
}

void render_sprite(int i)
{
    if (sprite_indicator == 1)
    {
        int ind = 0;
        int count = sprite_count - 1;
        float angle_wanted,angle_sghira,point_x,point_y,point_distance_x,point_distance_y;
        float angle_jdida;
        sorting();
        while (count >= 0)
        {
            angle_sghira = atan2(Y_player - sprites[count].ycentre, X_player - sprites[count].xcentre);
            angle_wanted = sprites[count].rotation - angle_sghira;

            point_x = X_player + (sprites[count].xcentre - X_player) * cos(angle_wanted) - (sprites[count].ycentre - Y_player) * sin(angle_wanted);
            point_y = Y_player + (sprites[count].xcentre - X_player) * sin(angle_wanted) + (sprites[count].ycentre - Y_player) * cos(angle_wanted);
            angle_jdida = M_PI / 2 + angle_sghira;
            point_distance_x = sprites[count].xcentre + (50 / 2) * cos(angle_jdida);
            point_distance_y = sprites[count].ycentre + (50 / 2) * sin(angle_jdida);
            sprites[count].xoff = sqrtf(powf(point_distance_y - point_y,2) + powf(point_distance_x - point_x,2));
            double diss = sqrtf(powf(point_x - sprites[count].xcentre,2) + powf(point_y - sprites[count].ycentre,2));
            if (diss > 25)
                sprites[count].xoff = 0;
            //printf("%f\n",sprites[sprite_count].xoff);
            correctWallDistance = sqrtf(powf((Y_player - sprites[count].ycentre), 2)
					+ powf((X_player - sprites[count].xcentre), 2));
   // printf("%f\n",sprites[sprite_count].distance);
   // printf("%f\n",distance);
    
   // alpha = 80 / correctWallDistance;
    distanceProjectionPlan = (width / 2) / tan(rad(45) / 2); //here delete cos
    wallStripHeight = (50 / correctWallDistance) * distanceProjectionPlan;
  //  finder.x_offset = sprites[sprite_count].g_mhah == 1 ? fmod(sprites[sprite_count].WallHitX,50) : fmod(sprites[sprite_count].WallHitY,50);
    ft_nizar_calcul();
        //Modification here 2
    //printf("%f\n",finder.x_offset);  
        if(swiitch == 1)
        {
            //printf("s\n");+
            render_column1(i,count);
        }
            count--;
        }
    
    }
}
int deal_key(void)
{
    int p = 0;
    x = wall;
    y = wall;
    k = 0;
    int i = 0;
    int j = 0;
    int ray_lenght;
    remaind = wall;
  //  ft_morba3(line);
    //mlx_clear_window(mlx_ptr,win_ptr);
    rotation = rotationAngle - M_PI / 8;
    rot = rad(45) / width;
    sprite_count = 0;
    if (rotationAngle > 2 * M_PI || rotationAngle < 0)
            rotationAngle = ft_normalize_angle(rotationAngle);
   // printf("rotationAngle :|%f|\n",deg(rotationAngle));

    while(i < width)
    {
        if (rotation > 2 * M_PI || rotation < 0)
            rotation = ft_normalize_angle(rotation);
        //DDA(X_player, Y_player,  wallHitX, wallHitY);
        ft_cast_ray(i);
        rotation += rot;
        // if(sprite == 0)
        render_map3D(i);
        if(sprite_indicator == 1 )
        {
             render_sprite(i);
            // printf("%d\n",sprite_count);
             sprite_count = 0;
        }
            
        
       // printf("%d",sprite);
        // if(sprite == 1)
        // {
        //     //printf("1\n");
        //     render_sprite(i);
        // } 
        i++;
      //  printf("Only Rotation |%f|\n",deg(rotation));
     //   printf("rotationAngle :|%f|\n",deg(rotationAngle));
    }

    //DDA(X_player, Y_player,  X_player  +  150  *  cos(rotationAngle - M_PI / 8) , Y_player +  150 * sin//(rotationAngle - M_PI / 8));
    if(down == 1)
    {
        X_remainder = X_player;
        Y_remainder = Y_player;
        X_remainder -= cos(rotationAngle) * 5;
        Y_remainder -= sin(rotationAngle) * 5;
        p = wall_collision();
        if (p != 1)
        {
            X_player -= cos(rotationAngle) * 5;
            Y_player -= sin(rotationAngle) * 5;
        }
        // printf("%f",deg(rotation));
    }
    if (up == 1)
    {
        X_remainder = X_player;
        Y_remainder = Y_player;
        X_remainder += cos(rotationAngle) * 5;
        Y_remainder += sin(rotationAngle) * 5;
         p = wall_collision();
        if (p != 1)
        {
            X_player += cos(rotationAngle) * 5;
            Y_player += sin(rotationAngle) * 5;
        }
    }
    if (left == 1)
    {
         rotationAngle -= rad(rotationSpeed);
    }
    if (right == 1)
    {
         rotationAngle += rad(rotationSpeed);
    }
    /*printf("x = |%d| \ny = |%d|",X_player,Y_player);
    printf("\n====> X_remainder : ||%d||\n",X_remainder);
    printf("\n====> Y_remainder : ||%d||\n",Y_remainder);
    //printf("%f\n",rotationAngle );*/
   // rotation = ft_normalize_angle(rotation);
    return 0;
}


int loop_key()
{

   /*textu1 = "ayoub.xpm";
    textu2 = "maroc.xpm";
    textu3 = "shanks.xpm"; */

    mlx_hook(win_ptr,2,0,mlx_key_press,0);
    mlx_hook(win_ptr,3,0,key_release,0);
    deal_key();
    // modification 3
    //mlx_clear_window(mlx_ptr,win_ptr);
    if(swiitch == 1)
        mlx_put_image_to_window(mlx_ptr,win_ptr,g_image,0,0);
    
    //ft_texture();
    return 0; 
}
void **fd_tab2(int fd)
{
    //line = (char **)malloc(sizeof(char *) * 1000);
    int j = 0;
    int c = 0;
    
    /*line[i] = malloc(sizeof (char) * 1000);
        while(map[y_len][j])
        {
            line[i][j] = map[y_len][j];
            j++;
        }
    line[i][j] = '\0';*/
    line[inde] = strdup(map[y_len]);

    
}
void  fd_tab(int fd)
{
    int c = 0;
    int t = 0;
    y_len = 0;
    map = malloc(sizeof(char *) * 1000);
    while(get_next_line(fd,&map[y_len]))
    {
        if(strchr("R" , map[0][0])
        {

        }
        mapcount[t].mapx = ft_strlen(map[y_len]);
        if (strchr("012NWES", map[y_len][0]) && mapcount[t].mapx > 0)
        {
            fd_tab2(fd);
              printf("%s\n",line[inde]);
            inde++;
        }

        t++;
        y_len++;
    }
    
     //printf("%s\n",line[0]);
    fd_tab2(fd);
    //printf("%s\n",line[inde]);
    line[++inde] = NULL;
    map[y_len + 1] = NULL;
    y_len++;
}
int main()
{
   int i = 0;
    int j = 0;
    inde = 0;
    //printf("ayoub")
    x = wall;
    y = wall;
       line = (char **)malloc(sizeof(char *) * 1000);

   // memset(g_rays, 0, 1000 * sizeof(int));
    //memset(g_rays_hit, 0, 1000 * sizeof(int));
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, width, height,"mlx 42");
    g_image = mlx_new_image(mlx_ptr,width,height);
    g_data = (int *)mlx_get_data_addr(g_image,&g_b,&g_a,&g_c);
    int fd = open("map.txt", O_RDONLY);
    fd_tab(fd);
    ft_morba3(line);
    text();
    //return 0;
    rotation = rotationAngle - M_PI / 8;
    rot = rad(45) / width;
    while(i < width)
    {
        if (rotation > 2 * M_PI || rotation < 0)
            rotation = ft_normalize_angle(rotation);
       ft_cast_ray(i);
        rotation += rot;
        i++;

    } 
    //printf("%d\n",sprite_number);
    mlx_loop_hook(mlx_ptr,loop_key,0);

   mlx_loop(mlx_ptr);
}