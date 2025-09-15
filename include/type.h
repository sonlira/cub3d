


typedef struct s_config
{
	// char	*no;
	// char	*so;
	// char	*we;
	// char	*ea;
	char	*textures[4]; // [NO, SO, WE, EA]
	int		floor_rgb[3];	// [R, G, B]
	int		ceiling_rgb[3]; // [R, G, B]
	int		floor_color;	// empaquetado 0xRRGGBB
	int		ceiling_color;	// empaquetado 0xRRGGBB
}	t_config;

typedef struct s_map
{
	char	**grid;
	int		rows;
	int		cols;
}	t_map;

typedef struct s_game
{
	t_config	*cfg;
	t_map		*map;

}	t_game;
