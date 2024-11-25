/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcesar-n <gcesar-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:35:49 by gcesar-n          #+#    #+#             */
/*   Updated: 2024/11/25 14:37:54 by gcesar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clear_backup(char *old_backup)  //limpa a memória
{
	free(old_backup);
	return (NULL);  //retorna null informando que esta vazio
}

static char	*read_and_store(int fd, char *buffer, char *stored)  //lê o arquivo e aloca memória necessaria
{
	int		bytes;  // armazenaf os bytes lidos
	char	*temp;  //variavel temporaria

	bytes = 1;
	if (stored == NULL)  //se receber um ponteiro nulo, já cria uma string vazia
	{
		stored = ft_strdup("");  //aloca a string vazia
		if (stored == NULL)
		{
			return (NULL);  //retorna nulo se o malloc da strdup der ruim
		}
	}
	while ((ft_strchr(stored, '\n') == NULL) && (bytes != 0))  //fica no loop ate encontrar '\n' ou EOF 
	{
		bytes = read(fd, buffer, BUFFER_SIZE);  //le o arquivo, com o 'size' BUFFER_SIZE
		if (bytes == -1)  //limpa o buffer se retornar -1 (falha do read)
			return (clear_backup(stored));
		buffer[bytes] = '\0'; //coloca o terminador nulo no final
		temp = stored;  //transfere o conteudo pra 'stored', pq o temp vai ser free
		stored = ft_strjoin(temp, buffer);  //manda o buffer pra stored
		free(temp);
		if (stored == NULL)  //tratativa de erro
			return (NULL);
	}
	return (stored);  //retorna a string 'stored' atualizada
}

static char	*line_extractor(char *stored)
{
	int		index;  // posicao do \n ou EOF
	char	*line;  //armazena a linha extraida

	index = 0;
	if (stored[index] == '\0')  //retorna nulo se receber uma string vazia
		return (NULL);
	while (stored[index] != '\0' && stored[index] != '\n')  //encontra onde esta o '\n'
	{
		index++;
	}
	line = ft_substr(stored, 0, index + 1);  //extrai a linha incluindo o '\n'
	return (line);  //retorna a linha extraída
}

static char	*update_backup(char *stored)
{
	int		index;  //posicao do '\n' na string
	char	*new_backup;  // armazena a string atualizada

	index = 0;
	while (stored[index] != '\0' && stored[index] != '\n')  //encontra o '\n' e inicia o loop
	{
		index++;
	}
	if (stored[index] == '\0')  //se n encontrar o '\n'
	{
		return (clear_backup(stored));  //limpa a memoria
	}
	new_backup = ft_substr(stored, index + 1, ft_strlen(stored) - index);  //cria uma nova string começando depois do '\n'
	free(stored);
	return (new_backup);
}

char	*get_next_line(int fd)
{
	static char	*stored;  //buffer
	char		*buffer;  //armazena o buffer temporario
	char		*line;  //armazena a linha

	if (fd < 0 || BUFFER_SIZE <= 0)  //tratativa de possíveis erros
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));  //aloca o tamanho pro buffer
	if (buffer == NULL)                                        //tratativa de erro
	{
		return (NULL);  //retorna nulo se malloc der ruim
	}
	stored = read_and_store(fd, buffer, stored);  //le o arquivo e guarda os dados em 'stored'
	free(buffer);                                //libera a memoria logo apos a leitura
	if (stored == NULL)                         //tratativa em caso de erro ou não ter dados
	{
		return (NULL);
	}
	line = line_extractor(stored);             //extrai a prox linha chamando a func
	stored = update_backup(stored);           //atualiza o buffer pra ter so os dados restantes
	return (line);                           //retorna a linha
}

int	main(void)
{
	int fd;
	char *line;

	if (argc != 2)
	{
		write(2, "./get_next_line arquivo\n", 35);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}