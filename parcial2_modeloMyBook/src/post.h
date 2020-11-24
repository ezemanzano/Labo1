typedef struct
{
	int idPost;
	int popularidadMensaje;
	char mensajePost[2000];
	int idUsuario;
}Post;

Post* post_new(void);
Post* post_newParam(int idPost,int idUsuario, int popularidadMensaje, char* mensajePost);
int post_setIdPost(Post* this, int idPost);
int post_setPopularidadMensaje(Post* this, int popularidadMensaje);
int post_setMensajePost(Post* this, char* mensajePost);
int post_getIdPost(Post* this);
int post_getPopularidadMensaje(Post* this);
char* post_getMensajePost(Post* this);
int post_getIdUsuarioPost(Post* this);
int post_setIdUsuarioPost(Post* this, int idUserPost);
int isValidIdUsuarioPost(int idPost);

int isValidMensajePost(char* mensajePost);
int isValidPopularidadMensaje(int popularidadMensaje);
int isValidIdPost(int idPost);
int post_imprimirTodos(void*thisA);
