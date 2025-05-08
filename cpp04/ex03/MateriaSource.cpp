#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        templates[i] = NULL;
    }
    
    for (int i = 0; i < 4; i++) {
        if (other.templates[i]) {
            templates[i] = other.templates[i]->clone();
        }
    }
}

MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (templates[i]) {
            delete templates[i];
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &other) {
        // Delete current templates
        for (int i = 0; i < 4; i++) {
            if (templates[i]) {
                delete templates[i];
                templates[i] = NULL;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            if (other.templates[i]) {
                templates[i] = other.templates[i]->clone();
            }
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) {
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (templates[i] == NULL) {
            templates[i] = m;
             std::cout << "MateriaSource learned " << m->getType() << std::endl;
            return;
        }
    }
    
    std::cout << "MateriaSource cannot learn any more materias" << std::endl; 
    delete m;  
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (templates[i] && templates[i]->getType() == type) {
              std::cout << "MateriaSource created " << type << std::endl;
            return templates[i]->clone();  // Return a clone of the template
        }
    }
    
      std::cout << "MateriaSource cannot create unknown type: " << type << std::endl;
    return NULL;
}
