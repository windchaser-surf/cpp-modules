#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
		: AForm("Shrubbery Creation Form", 145, 137) {

	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& old)
		 : AForm(old.getName(), old.getSignedGrade(), old.getExecGrade()){
			
			_target = old._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& old) {

	if (this != &old)
		_target = old._target; 
	return (*this);
}

void ShrubberyCreationForm::createFile() const {

	std::string	filename = _target + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	if (!outfile.is_open()) {
		throw FileNotOpened();
		return ;
	}
	        outfile << "    ccee88oo          \n"
                   "  C8O8O8Q8PoOb o8oo   \n"
                   " dOB69QO8PdUOpugoO9bD\n"
                   "CgggbU8OU qOp qOdoUOdcb\n"
                   "    6OuU  /p u gcoUodpP\n"
                   "      \\\\\\//  /douUP\n"
                   "        \\\\\\////\n"
                   "         |||/\\\n"
                   "         |||\\//\\\n"
                   "         |||||\n"
                   "   .....//||||\n\n\n"

					"		  *\n"  
					"	   / \\\n" 
					"	  /   \\\n"
					"	 /     \\\n" 
					"  /       \\\n" 
					" /         \\\n" 
					"/___________\\\n" 
					"    |||\n"    
					"    |||\n"    
					"    |||\n";  
	outfile.close();
}

void ShrubberyCreationForm::execute(const Bureaucrat& executer) const {
	

	AForm::checkRequirements(executer);
	createFile();
	
}

const char* ShrubberyCreationForm::FileNotOpened::what() const throw() {

	return "File cannot be opened!!!";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}
