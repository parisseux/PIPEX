/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchatagn <pchatagn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:48:58 by pchatagn          #+#    #+#             */
/*   Updated: 2025/03/03 14:10:54 by pchatagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(char **av, int *fd, char **envp)
{
	int		fd_infile;
	int		fd_outfile;
	char	**cmd;
	char	*path;

	(void)fd;
	cmd = ft_split(av[2], ' ');
	path = ft_strjoin("/usr/bin/", cmd[0]);
	fd_infile = open(av[1], O_RDONLY);
	if (fd_infile == -1)
	{
		perror("Error opening file1");
		exit(EXIT_FAILURE);
	}
	fd_outfile = open(av[3], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile == -1)
	{
		perror("Error opening file2");
		exit(EXIT_FAILURE);
	}
	dup2(fd_infile, STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	execve(path, cmd, envp);
	free(path);
	close(fd_infile);
	close(fd_outfile);
}

void	ft_parent_process(char **av, int *fd, char **envp)
{
	(void)av;
	(void)fd;
	(void)envp;
	printf("miaoumiaou");
}

int	main(int ac, char **av, char **envp)
{
	int	fds[2];
	int	pid;

	if (ac != 4)
	{
		printf("usage: ./pipex file1 cmd1 file2\n");
		exit(EXIT_FAILURE);
	}
	if (pipe(fds) == -1)
	{
		perror("pipe error");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		ft_child_process(av, fds, envp);
	else
	{
		waitpid(pid, NULL, 0);
		ft_parent_process(av, fds, envp);
	}
	return (0);
}
