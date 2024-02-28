#!/bin/bash

{
	# Boucle sur chaque fichier map dans le répertoire maps
	for mapfile in maps_test/*; do
		echo "Traitement de la map: $mapfile"
		# Vérifie si le nom du fichier commence par 'b'
		 output=$(timeout --foreground 5s valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 --log-file=/dev/null ./cub3D "$mapfile" 2>&1);
		exit_status=$?
		if [ $exit_status -eq 124 ]; then
			echo -e "Le programme $mapfile a été terminé en raison d'un dépassement de temps (timeout).\n"
			if [[ $(basename "$mapfile") == b* ]]; then
				echo -e "\e[31mERROR: $mapfile\e[0m"
			fi
		else
			echo -e "Le programme $mapfile a été terminé avec le code de sortie $exit_status.\n"
		fi
		if [[ $(basename "$mapfile") == b* ]]; then
			# Exécute cub3D avec valgrind, capture la sortie standard et d'erreur
			# Cherche le motif d'erreur spécifique "Error\n \n"
			if echo "$output" | grep -Pzo "Error.*(\n.*)?"; then
				# Si le motif d'erreur est trouvé, affiche les erreurs
				# echo "$output"
				echo -e "\n"
				# sleep 1
			else
				# Si aucune erreur correspondant au motif n'est trouvée et que le nom commence par 'b'
				echo -e "\e[31mERROR: $mapfile\e[0m"
				echo -e "\n"
				# sleep 20
			fi
		fi
		if [[ $(basename "$mapfile") == g* ]]; then
			# Exécute cub3D avec valgrind, capture la sortie standard et d'erreur
			# Cherche le motif d'erreur spécifique "Error\n \n"
			if echo "$output" | grep -Pzo "Error.*(\n.*)?"; then
				# Si le motif d'erreur est trouvé, affiche les erreurs
				echo -e "\e[31mERROR: $mapfile\e[0m"
				# echo "$output"
				echo -e "\n"
				# sleep 1
			else
				# Si aucune erreur correspondant au motif n'est trouvée et que le nom commence par 'b'
				echo -e "\n"
				# sleep 20
			fi
		fi
		# Ferme le programme cub3D
		# pkill cub3D
	done
} 2>&1 | tee outfile.txt