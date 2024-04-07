int     mlx_destroy_image(mlx_ptr_t *mlx_ptr, mlx_img_list_t *img_todel)
{
  mlx_img_ctx_t	ctx_first;
  mlx_img_ctx_t	*ctx;
  mlx_img_ctx_t	*ctx_to_del;
  mlx_img_list_t img_first;
  mlx_img_list_t *img;
  mlx_win_list_t *win;

  img_first.next = mlx_ptr->img_list;
  img = &img_first;
  while (img && img->next)
    {
      if (img->next == img_todel)
	img->next = img->next->next;
      img = img->next;
    }
  mlx_ptr->img_list = img_first.next;


  win = mlx_ptr->win_list;
  while (win)
    {
      ctx_first.next = win->img_list;
      ctx = &ctx_first;
      while (ctx && ctx->next)
	{
	  if (ctx->next->img == img_todel)
	    {
	      [(id)(win->winid) selectGLContext];
	      glDeleteBuffers(1, &(ctx->next->vbuffer));
	      glDeleteTextures(1, &(ctx->next->texture));
	      ctx_to_del = ctx->next;
	      ctx->next = ctx->next->next;
	      free(ctx_to_del);
	    }
	  ctx = ctx->next;
	}
      win->img_list = ctx_first.next;
      win = win->next;
    }


  free(img_todel->buffer);
  free(img_todel);

  //  printf("destroy image done.\n");
  return (0);
}
