#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void		func_3(char *orig, char *dest, int nbcar)
{
  static char		valcar[65] = {0};
  unsigned char		octet1, octet2, octet3;
  int			i;

  if (!valcar[0])
    {
      i = -1;
      while (++i <= 26)
	valcar[i] = 'A' + i;
      i = -1;
      while (++i <= 26)
	valcar[26 + i] = 'a' + i;
      i = -1;
      while (++i < 10)
	valcar[52 + i] = '0' + i;
      valcar[62] = '+';
      valcar[63] = '/';
      valcar[64] = '\0';
    }

  while (nbcar >= 3)
    {
      octet1 = *(orig++);
      octet2 = *(orig++);
      octet3 = *(orig++);
      *(dest++) = valcar[octet1 >> 2];
      *(dest++) = valcar[((octet1 & 3) << 4) | (octet2 >> 4)];
      *(dest++) = valcar[((octet2 & 0x0F) << 2) | (octet3 >> 6)];
      *(dest++) = valcar[octet3 & 0x3F];
      nbcar -= 3;
    }
  if (nbcar)
    {
      octet1 = *(orig++);
      *(dest++) = valcar[octet1 >> 2];
      if (nbcar == 1)
	{
	  *(dest++) = valcar[(octet1 & 3) << 4];
	  *(dest++) = '=';
	}
      else
	{
	  octet2 = *orig;
	  *(dest++) = valcar[((octet1 & 3) << 4) | (octet2 >> 4)];
	  *(dest++) = valcar[(octet2 & 0x0F) << 2];
	}
      *(dest++) = '=';
    }
  *dest = '\0';
}

static void	func_1(char *str, int len)
{
  int		i;
  char		tmp;

  i = -1;
  while (++i < len / 2)
    {
      tmp = str[i];
      str[i] = str[len - i - 1];
      str[len - i - 1] = tmp;
    }
}

static void	func_2(char *str, int key)
{
  while (*str)
    {
      if (*str >= 'a' && *str <= 'z')
	*str = ((*str - 'a') + key) % 26 + 'a';
      if (*str >= 'A' && *str <= 'Z')
	*str = ((*str - 'A') + key) % 26 + 'A';
      ++str;
    }
}

static void	unxor(char *str, int key)
{
  while (*str)
    *str++ ^= key;
}

int	func_0(char *str)
{
  char	_42[] = {0x2f, 0x29, 0x00};
  char	_toto[] = {0x6f, 0x74, 0x6f, 0x74, 0x00};
  char	_tata[] = {0x6f, 0x7a, 0x6f, 0x7a, 0x00};
  char	_titi[] = {0x6f, 0x72, 0x6f, 0x72, 0x00};
  char	_bengui[] = {0x79, 0x7e, 0x75, 0x7c, 0x6e, 0x72, 0x3b, 0x68, 0x74, 0x69, 0x68, 0x3b, 0x7f, 0x7e, 0x3b, 0x78, 0x7e, 0x3b, 0x78, 0x74, 0x69, 0x6b, 0x68, 0x3b, 0x3a, 0x00};
  char	_noob[] = {0x75, 0x74, 0x74, 0x79, 0x35, 0x00};

  unxor(_42, 27);
  unxor(_toto, 27);
  unxor(_tata, 27);
  unxor(_titi, 27);
  unxor(_bengui, 27);
  unxor(_noob, 27);
  if (!strcmp(str, ""))
    return (puts(_noob));
  if (!strcmp(str, _42))
    return (puts(_bengui));
  if (!strcmp(str, _toto) || !strcmp(str, _titi) || !strcmp(str, _tata))
    return (puts(_noob));
  return (0);
}

int	main(int ac, char *av[])
{
  char	*out;

  if (ac != 2)
    return (fprintf(stderr, "usage: %s \"to_encrypt\"\n", av[0]));
  if (func_0(av[1]))
    return (0);
  if (!(out = malloc(sizeof(char) * (((strlen(av[1]) + 2) / 3 * 4) + 1))))
    return (fprintf(stderr, "malloc failed :(\n"));
  func_1(av[1], strlen(av[1]));
  func_2(av[1], 12);
  func_3(av[1], out, strlen(av[1]));
  printf("result: %s\n", out);
  free(out);
  return (0);
}
