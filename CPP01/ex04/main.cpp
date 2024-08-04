/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:00:23 by felix             #+#    #+#             */
/*   Updated: 2024/02/06 11:55:25 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

std::string	replaceWord(std::string const &s1, std::string const &s2, std::string &line) {
	
 	if (s1.empty())
	{
		std::cout << "Do you want to end up in an infinite loop?" << std::endl;
		return (line);
	}
	size_t pos_s1 = line.find(s1);
	while (pos_s1 != std::string::npos) {
		
		line = line.erase(pos_s1, s1.length());
		line = line.insert(pos_s1, s2);
		pos_s1 = line.find(s1, pos_s1 + s2.length());
	}
	return (line);
}

int main (int argc, char **argv) {

	if (argc < 4)
	{
		std::cerr << "Too less parameter; <filename> <s1> <s2>" << std::endl;
		std::cerr << "<filename> : File which should be read from" << std::endl;
		std::cerr << "<s1> : String1 which should be replaced" << std::endl;
		std::cerr << "<s2> : String which should be the new String" << std::endl;
	}
	else if (argc == 4)
	{
		std::string 		filename(argv[1]);
		std::string 		filename_replace = filename + ".replace";
		std::stringstream 	infile_text;
		std::string			convert_text;
		
		std::ifstream inputFile(filename.c_str());
		if (!inputFile.is_open()) {
			std::cerr << "Input file couldn't be opened" << std::endl;
			return (1);
		}
		std::ofstream outputFile(filename_replace.c_str());
		if (!outputFile.is_open()) {
			std::cerr << "Output file couldn't be opened" << std::endl;
			inputFile.close();
			return (1);
		}
		infile_text << inputFile.rdbuf();
		convert_text = infile_text.str();
		outputFile << replaceWord(argv[2], argv[3], convert_text);
		inputFile.close();
		outputFile.close();
	}
	else 
		std::cerr << "Too less parameter; <filename> <s1> <s2>" << std::endl;
	
	(void) argv;
	return (0);
}
