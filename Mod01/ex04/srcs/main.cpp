/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:20:17 by mjuin             #+#    #+#             */
/*   Updated: 2023/03/01 14:16:34 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

bool CheckArg(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Wrong number of argument !" << std::endl;
		return (false);
	}
	if( av[2][0] == '\0')
	{
		std::cerr << "Cannot replace a \'\\0\'" << std::endl;
		return (false);
	}
	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cerr << "The " << av[1] << " file doesn't look like it exists or could not have been opened." << std::endl;
		return (false);
	}
	file.close();
	return (true);
}

void OpenFiles(std::ifstream *infile, std::ofstream *outfile, std::string av)
{
	infile->open(av.c_str());
	if (infile->is_open() == false)
		return ;
	av += ".replace";
	outfile->open(av.c_str());
	if(outfile->is_open() == false)
		infile->close();
}

std::string	replace(std::string str, std::string s1, std::string s2)
{
	size_t	pos = 0;
	size_t	previousPos = 0;
	std::string tmp;
	
	pos = str.find(s1, pos);
	while (pos != str.npos)
	{
		tmp += str.substr(previousPos, pos - previousPos);
		tmp += s2;
		pos += s1.length();
		previousPos = pos;
		pos = str.find(s1, pos);
	}
	tmp += str.substr(previousPos, pos - previousPos);
	return (tmp);
}

void	Copy(char **av)
{
	std::ifstream infile;
	std::ofstream outfile;
	std::string readedFile;

	OpenFiles(&infile, &outfile, av[1]);
	if (infile.is_open() == false || outfile.is_open() == false)
		return ;
	if (infile.peek() == std::ifstream::traits_type::eof())
	{
		infile.close();
		outfile.close();
		return ;
	}
	while (infile.peek() != std::ifstream::traits_type::eof())
	{
		std::getline(infile, readedFile);
		outfile << replace(readedFile, av[2], av[3]) << std::endl;
	}
	infile.close();
	outfile.close();
}

int main(int ac, char **av)
{
	if (CheckArg(ac, av) == false)
		return (1);
	Copy(av);
}