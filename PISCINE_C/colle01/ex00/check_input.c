/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassi-f <malikfassifihri@gmail.co>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/07/27 23:32:57 by mfassi-f          #+#    #+#             */
/*   Updated: 2013/07/28 13:54:55 by fbusi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Cette fonction check si les parametres sont bons, elle verifie si il y a
//exactement 9 lignes, 9 colonnes et minimum 16 chiffres (cfr wikipedia)
//si < 16 chiffres, sudoku a plus qu'une seule solution.
//
//J'ai pas encore verifier la norme. La fonction semble marcher d'apres mes test
//
// IL FAUT ENCORE CHECKER SI LE TABLEAU EST VALIDE 
// PAR RAPPORT AU REGLES DU SUDOKU,
// GENRE DANS INPUT IL Y A DEJA 2 NEUF SUR LA MEME LIGNE
// ET VERIFIER QU'IL Y A QUE DES CHIFFRES DE 1-9 ou des points. 
// je ne l'ai pas encore fait pcq j;ai pas encore les fonctions pour l'instant.
//
// explication des parametres : 
// 			 argc represente le nombre d'argument que l'on passe au main 
// 					(sans compter le nom de la fonction)
// 			argv represente le tableau des arguments a partir de l'indice 1;
// 				(sans compter le nom de la fonction);
//
int	check_input(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	if (argc == 9)
	{
		j = 9;
		i = 0;
		while (j == 9 && i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				if (argv[i][j] == '0')
				{
					return (0);
				}
				if (argv[i][j] != '.')
				{
					count++;
				}
				j++;
			}
			i++;
		}
	}
	return ((i == 9) && j == 9 && count >= 17);
}
